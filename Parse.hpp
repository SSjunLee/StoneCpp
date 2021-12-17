//
// Created by 12206 on 2021/12/12.
//

#ifndef STONE_PARSE_HPP
#define STONE_PARSE_HPP

#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include "ast/AstTree.h"
#include "Lexer.h"
#include "ParseException.h"

//运算符优先级 (优先级，是否左结合)
typedef std::tuple<int, bool> Precedence;

class Rule {
public:
    virtual ~Rule() = default;

    //解析规则
    virtual AstTree::cptr parse(Lexer &lexer) = 0;

    //检查是否匹配规则
    virtual bool match(Lexer &lexer) = 0;
};

class Logic {
public:
    virtual ~Logic() = default;

    //将匹配到的元素解析为ast放入list
    virtual void parse(Lexer &l, std::vector<AstTree::cptr> &list) = 0;

    virtual bool match(Lexer &l) = 0;

    virtual bool ignore() const noexcept { return false; };
};

template<typename T = AstLeaf>
class NumLogic : public Logic {
public:
    NumLogic() {
        static_assert(std::is_base_of<AstLeaf, T>::value, "NumLogic must be base of AstLeaf");
    }

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        if (!match(l))throw ParseException(l.peek(0));
        list.push_back(std::make_shared<T>(l.read()));
    }

    bool match(Lexer &l) override {
        return l.peek(0)->isNumber();
    }
};


template<typename T = AstLeaf>
class StrLogic : public Logic {
public:
    StrLogic() {
        static_assert(std::is_base_of<AstLeaf, T>::value, "StrLogic must be base of AstLeaf");
    }

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        if (!match(l))throw ParseException(l.peek(0));
        list.push_back(std::make_shared<T>(l.read()));
    }

    bool match(Lexer &l) override {
        return l.peek(0)->isString();
    }
};

template<typename T = AstLeaf>
class IdLogic : public Logic {
private:
    std::unordered_set<std::string> r; //不能被当作标识符的字典
public:
    IdLogic(const std::unordered_set<std::string> &r) : r(r) {
        static_assert(std::is_base_of<AstLeaf, T>::value, "IdLogic must be base of AstLeaf");
    }

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        if (!match(l))throw ParseException(l.peek(0));
        list.push_back(std::make_shared<T>(l.read()));
    }

    bool match(Lexer &l) override {
        auto pk = l.peek(0);
        if (!pk->isIdentifier())return false;
        if (r.find(pk->getText()) != r.end()) {
            return false;
        }
        return true;
    }
};


class SepLogic : public Logic {
private:
    std::unordered_set<std::string> mPat;
public:
    SepLogic(const std::unordered_set<std::string> pat) : mPat(pat) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        if (!match(l))throw ParseException(l.peek(0));
        l.read(); //just consume
    }

    bool match(Lexer &l) override {
        auto t = l.peek(0);
        if (!t->isIdentifier())return false;
        if (mPat.find(t->getText()) != mPat.end()) {
            return true;
        }
        return false;
    }
};

class AstLogic : public Logic {
private:
    Rule *mRule;
public:
    AstLogic(Rule *rule) : mRule(rule) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        list.push_back(mRule->parse(l));
    }

    bool match(Lexer &l) override {
        return mRule->match(l);
    }
};

/**
 *
 * @tparam T 表达式Ast节点类型
 */
template<typename T>
class ExprLogic : public Logic {
private:
    Rule *mFactor;
    std::unordered_map<std::string, Precedence> mOps;
public:
    explicit ExprLogic(Rule *f, std::unordered_map<std::string, Precedence> ops)
            : mFactor(f), mOps(std::move(ops)) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        auto right = mFactor->parse(l);
        Precedence next;
        while (nextOperator(l, next)) {
            right = doShift(l, right, std::get<0>(next));
        }
        list.push_back(right);
    }

    bool match(Lexer &l) override {
        return mFactor->match(l);
    }

private:
    /**
     * 功能：是否要先算右边
     * 比如 a=b=c b=c要先算,返回true
     * a/2+3  就得先算左边，返回false
     * @param prec 靠左边的操作符的优先级
     * @param nextPrec  靠右边的操作符的优先级
     * @return
     */
    bool rightIsExpr(int prec, Precedence nextPrec) {
        if (std::get<1>(nextPrec))return prec < std::get<0>(nextPrec);
        return prec <= std::get<0>(nextPrec);
    }

    /**
     *
     * @param l
     * @param left 左表达式
     * @param prec 左表达式优先级
     * @return {left,op,right}
     */
    AstTree::cptr doShift(Lexer &l, AstTree::cptr left, int prec) {
        //read op and consume op
        AstTree::cptr op = std::make_shared<const AstLeaf>(l.read());
        auto right = mFactor->parse(l);
        Precedence next;
        //如果存在下一个操作符且下一个操作符的优先级更高
        //dfs 计算下一个处理下一个操作符（即构造一颗右偏树）
        while (nextOperator(l, next) && rightIsExpr(prec, next)) {
            right = doShift(l, right, std::get<0>(next));
        }
        return std::make_shared<T>(std::vector<AstTree::cptr>{left, op, right});
    }

    /**
     * 检查下一个token是否是操作符
     * 如果是标识符，查询表示符的有先权
     * 把优先权写入p，返回1
     *
     * 如果不是操作符token读完，则返回false
     * @param l
     * @param p 输出参数
     * @return
     */
    bool nextOperator(Lexer &l, Precedence &p) {
        auto tk = l.peek(0);
        if (tk->isIdentifier() && mOps.find(tk->getText()) != mOps.end()) {
            p = mOps[tk->getText()];
            return true;
        }
        return false;
    }
};

class OptionLogic : public Logic {
private:
    Rule *mRule;
public:
    OptionLogic(Rule *r) : mRule(r) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        if (match(l))list.push_back(mRule->parse(l));
    }

    bool match(Lexer &l) override {
        return mRule->match(l);
    }

    bool ignore() const noexcept override { return true; }
};

template<typename T>
class MaybeLogic : public Logic {
private:
    Rule *mRule;
public:
    MaybeLogic(Rule *r) : mRule(r) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        //和Option的不同之处在于会创建一个空的ast节点
        if (match(l))list.push_back(mRule->parse(l));
        else list.push_back(std::make_shared<T>(std::vector<AstTree::cptr>()));
    }

    bool match(Lexer &l) override {
        return mRule->match(l);
    }

    bool ignore() const noexcept override { return true; }
};

class RepeatLogic : public Logic {
private:
    Rule *mRule;
public:
    RepeatLogic(Rule *r) : mRule(r) {}

    void parse(Lexer &l, std::vector<AstTree::cptr> &list) override {
        while (match(l)) {
            auto ast = mRule->parse(l);
            if (ast)
                list.push_back(ast);
        }
    }

    bool match(Lexer &l) override {
        return mRule->match(l);
    }

    bool ignore() const noexcept override { return true; }
};

/**
 *  //列表规则：将逻辑进行匹配，并用匹配结果构造语法树分支节点
 * @tparam T :默认为分支节点类
 */
template<typename T = AstList>
class ListRule : public Rule {
private:
    std::vector<Logic *> mLogics;
    bool only;
public:
    explicit ListRule(bool only = false) : only(only) {
        if (typeid(T) == typeid(AstList)) {
            this->only = true;
        }
    }

    ~ListRule() {
        for (auto r:mLogics)delete r;
    }

    AstTree::cptr parse(Lexer &lexer) override {
        std::vector<AstTree::cptr> lst;
        for (auto r:mLogics) {
            r->parse(lexer, lst);
        }
        /**
         * 这个参数主要为了解决两种情况
         * 1. 如果当前的规则只是一个wrapper，则不需要为这个规则创建astNode，直接处理它的儿子即可
         * 比如 rule().ast(node),我们不需要为这个rule创建ast，而是直接为它的儿子node创建ast
         *
         * 2. 如果当前规则是个primary
         * 之前为了扩展性  primary = mFactory.rule<PrimaryExpr>(true)->ast(primaryOr);
         * 这里解析的时候，不会为primary创建PrimaryExpr节点，而是直接为它的儿子primaryOr创建节点
         * 当处理函数时  primary = mFactory.rule<PrimaryExpr>(true)->ast(primaryOr)->repeat(postfix)
         * 则必须创建PrimaryExpr节点，primarOr和postfix则作为这个节点的儿子
         *
         *
         */
        if (only) {
            if (lst.size() == 0)return nullptr;
            if (lst.size() == 1)
                return lst.front();
        }
        return std::make_shared<T>(lst);
    }

    bool match(Lexer &lexer) override {
        for (auto r:mLogics) {
            if (!r->ignore()) { return r->match(lexer); }
            if (r->match(lexer))return true;
        }
        return true;
    }

    /**
     * 向当前分支节点里插入一个数字字面量Loigc节点,返回当前对象
     * @tparam E 数字字面量Ast节点类型
     * @return  当前的分支节点
     */
    template<typename E>
    ListRule<T> *number() {
        mLogics.push_back(new NumLogic<E>);
        return this;
    };

    /**
     * 向当前分支节点的儿子列表里插入一个字符串面量Loigc节点,返回当前对象
     * @tparam E
     * @return
     */
    template<typename E>
    ListRule<T> *string() {
        mLogics.push_back(new StrLogic<E>);
        return this;
    };

    /**
     * 向当前分支节点的儿子列表里插入一个标识符Loigc节点,返回当前对象
     * @tparam E
     * @param r 一个字典，字典里的字符不能被当作标识符
     * @return
     */
    template<typename E = AstLeaf>
    ListRule<T> *identifier(const std::unordered_set<std::string> &r) {
        mLogics.push_back(new IdLogic<E>(r));
        return this;
    };

    /**
     * 向当前分支节点的儿子列表里插入一个包含pat字符Loigc节点,返回当前对象
     * @param pat
     * @return
     */
    ListRule<T> *sep(const std::unordered_set<std::string> pat) {
        mLogics.push_back(new SepLogic(pat));
        return this;
    }

    /**
     * 向当前分支节点的儿子列表里插入一个分支ruler节点,返回当前对象
     * @param rule
     * @return
     */
    ListRule<T> *ast(Rule *rule) {
        mLogics.push_back(new AstLogic(rule));
        return this;
    }

    //0次或1次，如果是0次，添加空分支节点
    template<typename E>
    ListRule<T> *maybe(ListRule<E> *rule) {
        mLogics.push_back(new MaybeLogic<E>(rule));
        return this;
    }

    //0次或一次，如果是0次，则不添加节点
    ListRule<T> *option(Rule *rule) {
        mLogics.push_back(new OptionLogic(rule));
        return this;
    }

    // 0次或多次
    ListRule<T> *repeat(Rule *rule) {
        mLogics.push_back(new RepeatLogic(rule));
        return this;
    }


    template<typename E>
    ListRule<T> *expression(Rule *f, const std::unordered_map<std::string, Precedence> &ops) {
        mLogics.push_back(new ExprLogic<E>(f, ops));
        return this;
    };
};

class OrRule : public Rule {
private:
    std::vector<Rule *> mRules;
public:
    explicit OrRule(std::vector<Rule *> rules) : mRules(std::move(rules)) {}

    void push_back(std::vector<Rule *> r) {
        mRules.insert(mRules.end(), r.begin(), r.end());
    }

    void push_front(std::vector<Rule *> r) {
        mRules.insert(mRules.begin(), r.begin(), r.end());
    }

    AstTree::cptr parse(Lexer &lexer) override {
        for (auto e:mRules) {
            if (!e->match(lexer))continue;
            return e->parse(lexer);
        }
        return nullptr;
    }

    bool match(Lexer &lexer) override {
        for (auto e:mRules) {
            if (e->match(lexer))return true;
        }
        return false;
    }

};

//对rule做内存管理
class ParseFactory {
private:
    std::vector<Rule *> rules;
public:
    ~ParseFactory() {
        for (auto &r:rules) {
            delete r;
        }
    }

    template<typename T=AstList>
    ListRule<T> *rule(bool only = false) {
        auto *ret = new ListRule<T>(only);
        rules.push_back(ret);
        return ret;
    };

    OrRule *orRule(const std::vector<Rule *> &rs) {
        auto *ret = new OrRule(rs);
        rules.push_back(ret);
        return ret;
    }
};


#endif //STONE_PARSE_HPP
