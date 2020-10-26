#include "eva_op.h"
#include <vector>
using namespace std;

eval_op::~eval_op()
{

}
eval_op::eval_op(const expression &exp)
{
    expr_id_ = exp.get_id();
    op_name_ = exp.get_op_name();
    op_params = exp.get_op_params();
    inputs_ = exp.get_inputs();


}
// tensor eval_op::eval(vars_type &variables, const kwargs_type &kwargs)
// {

// }

//const
eval_const::eval_const(const expression &expr): eval_op(expr),value_(expr.get_op_param("value"))
{

}
tensor eval_const::eval(vars_type &variables, const kwargs_type &kwargs)
{
    variables[expr_id_] = value_;
    return value_;
}

//input
eval_input::eval_input(const expression &expr):eval_op(expr){}
tensor eval_input::eval(vars_type &variables, const kwargs_type &kwargs)
{
    auto it = kwargs.find(op_name_);
    variables[expr_id_] = it->second;
    return it->second;

    // variables[expr_id_] = kwargs.at(op_name_);
    // return kwargs.at(op_name_);

}


//addition
eval_add::eval_add(const expression &expr):eval_op(expr){}
tensor eval_add::eval(vars_type &variables, const kwargs_type &kwargs )
{
    tensor input_1 = variables.at(inputs_[0]);
    tensor input_2 = variables.at(inputs_[1]);
    std::vector<double> result;
    for(int i =0; i< input_1.get_size(); ++i)
    {
        double sum_array = input_1.get_data_array()[i] + input_2.get_data_array()[i];
        result.push_back(sum_array);
    }
    variables[expr_id_] = tensor(input_1.get_dim(),input_2.get_shape_array(),&result[0]);
    return variables[expr_id_];
}

//subtract
eval_sub::eval_sub(const expression &expr):eval_op(expr){}
tensor eval_sub::eval(vars_type &variables, const kwargs_type &kwargs )

{
    
    tensor input_1 = variables.at(inputs_[0]);
    tensor input_2 = variables.at(inputs_[1]);
    std::vector<double> result;
    for(int i =0; i< input_1.get_size(); ++i)
    {
        double sum_array = input_1.get_data_array()[i] - input_2.get_data_array()[i];
        result.push_back(sum_array);
    }
    variables[expr_id_] = tensor(input_1.get_dim(),input_2.get_shape_array(),&result[0]);
    return variables[expr_id_];


}



//multiply
eval_mul::eval_mul(const expression &expr):eval_op(expr){}
tensor eval_mul::eval(vars_type &variables, const kwargs_type &kwargs ){
  
}

