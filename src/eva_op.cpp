#include "eva_op.h"
#include "expression.h"


eval_op::~eval_op()
{
}
eval_op::eval_op(const expression &expr){

}
void eval_op::eval(vars_type &variables, const kwargs_type &kwargs){

}


eval_const::eval_const(const expression &expr):eval_op(expr)
{

}
void eval_const::eval(vars_type &variables, const kwargs_type &kwargs){
    variables[expr_id] = value_;
}

eval_input::eval_input(const expression &expr):eval_op(expr)
{

}
void eval_input::eval(vars_type &variables, const kwargs_type &kwargs){

}


eval_add::eval_add(const expression &expr):eval_op(expr){

}
void eval_add::eval(vars_type &variables, const kwargs_type &kwargs){
    
}

eval_sub::eval_sub(const expression &expr):eval_op(expr){
    
}
void eval_sub::eval(vars_type &variables, const kwargs_type &kwargs){
    
}

eval_mul::eval_mul(const expression &expr):eval_op(expr){
    
}
void eval_mul::eval(vars_type &variables, const kwargs_type &kwargs){
    
}



