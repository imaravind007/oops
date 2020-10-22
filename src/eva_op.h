#ifndef EVALUATION_0P_H
#define EVALUATION_OP_H
#include "tensor.h"
#include "expression.h"
#include<map>
#include<vector>
using namespace std;

typedef std::map<int, tensor> vars_type;
typedef std::map<std::string, tensor>kwargs_type;

class eval_op
{
protected:
    int expr_id;
    string op_name_, op_type_;
    vector<int>inputs_;
public:
    eval_op(const expression &expr);
    virtual ~eval_op();
    virtual void eval(vars_type&variables, const kwargs_type&kwargs) = 0;
    
};// class eval_op


class eval_const: public eval_op{
    tensor value_;
public:
    eval_const(const expression &expr);
    void eval(vars_type&variables, const kwargs_type&kwargs)override;
};// class eval_const


class eval_input: public eval_op{
    tensor value_;
public:
    eval_input(const expression &expr);
    void eval(vars_type&variables, const kwargs_type&kwargs)override;
};// class eval_input


class eval_add: public eval_op{
    tensor value_;
public:
    eval_add(const expression &expr);
    void eval(vars_type&variables, const kwargs_type&kwargs)override;
};// class eval_add


class eval_sub: public eval_op{
    tensor value_;
public:
    eval_sub(const expression &expr);
    void eval(vars_type&variables, const kwargs_type&kwargs)override;
};// class eval_sub


class eval_mul: public eval_op{
    tensor value_;
public:
    eval_mul(const expression &expr);
    void eval(vars_type&variables, const kwargs_type&kwargs)override;
};// class_mul

#endif

