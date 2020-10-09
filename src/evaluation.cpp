#include <assert.h>
#include<string.h>
#include<map>
#include<iostream>
#include "evaluation.h"
using namespace std;

evaluation::evaluation(const std::vector<expression> &exprs)
    : exprs_(exprs),result_(0)
{
}

void evaluation::add_kwargs_double(const char *key,double value)
{
   kwargs_[key] = value;  
}

void evaluation::add_kwargs_ndarray(const char *key,int dim,size_t shape[],double data[])
{
}

int evaluation::execute()
{
    variables_.clear();
    for (auto &expr:exprs_)
    {
        if (expr.get_op_type()=="Input"){
            variables_[expr.get_id()] = kwargs_[expr.get_op_name()];
            result_ = kwargs_[expr.get_op_name()];
        }
        else if (expr.get_op_type() == "Add"){
            double v = variables_[expr.inputs_[0]]+variables_[expr.inputs_[1]];
            result_ = v;
            }
            
        else if (expr.get_op_type() == "Mul"){
            double v = variables_[expr.inputs_[0]] * variables_[expr.inputs_[1]];
            result_ = v;
        }
        else if (expr.get_op_type() == "Sub"){
            double v = variables_[expr.inputs_[0]] - variables_[expr.inputs_[1]];
            result_ = v;
        }
        else if (expr.get_op_type() == "Const"){
            variables_[expr.get_id()] = expr.op_param["value"];
            result_ = expr.op_param["value"];
        }

        variables_[expr.get_id()] = result_;
    }
    return 0;
}

double &evaluation::get_result()
{
    return result_;
}
