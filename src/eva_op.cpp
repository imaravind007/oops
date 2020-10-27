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
    // #Method:1
    auto it = kwargs.find(op_name_);
    variables[expr_id_] = it->second;
    return it->second;

    // Method:2
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
    variables[expr_id_] = tensor(input_1.get_dim(),input_1.get_shape_array(),&result[0]);
    return variables[expr_id_];
}
//subraction
eval_sub::eval_sub(const expression &expr):eval_op(expr){}
tensor eval_sub::eval(vars_type &variables, const kwargs_type &kwargs )

{
    
    tensor input_1 = variables.at(inputs_[0]);
    tensor input_2 = variables.at(inputs_[1]);
    std::vector<double> result;
    for(int i =0; i< input_1.get_size(); ++i)
    {
        double sub_array = input_1.get_data_array()[i] - input_2.get_data_array()[i];
        result.push_back(sub_array);
    }
    variables[expr_id_] = tensor(input_1.get_dim(),input_1.get_shape_array(),&result[0]);
    return variables[expr_id_];

}



//multipliction
eval_mul::eval_mul(const expression &expr):eval_op(expr){}
tensor eval_mul::eval(vars_type &variables, const kwargs_type &kwargs )
{
    tensor input_1 = variables.at(inputs_[0]);
    tensor input_2 = variables.at(inputs_[1]);
    if (input_1.get_dim()== 0) 
    {
        variables[expr_id_] = input_2;
        return variables[expr_id_];
    }
    if(input_2.get_dim()==0)
    {
        variables[expr_id_] = input_1;
        return variables[expr_id_];
    }
    vector<double>result;

    // #initializing the result of matrix result = 0
    for(int i=0; i < input_1.get_shape_array()[0]; ++i)
        for(int j=0; j < input_2.get_shape_array()[1]; ++j)
        {
            result.push_back(0);
            
        }
    // multiplying matrix Input1, Input2 and storing inside the result
    for(int i=0; i < input_1.get_shape_array()[0]; ++i)
        for(int j=0; j < input_2.get_shape_array()[1]; ++j)
            for(int k=0; k < input_1.get_shape_array()[1]; ++k)
            {
                result[i * input_2.get_shape_array()[1] + j] += input_1.at(i,k) * input_2.at(k,j);
            }
    size_t * result_shape = input_1.get_shape_array();
    result_shape[1] = input_2.get_shape_array()[1];
    variables[expr_id_] = tensor(2,result_shape, &result[0]);
    return variables[expr_id_];
  
}

