#include "program.h"
#include "evaluation.h"
using namespace std;

program::program()
{

}

void program::append_expression(int expr_id,const char *op_name,const char *op_type,int inputs[],
        int num_inputs)

{
    exprs_.push_back(expression(expr_id,op_name,op_type,inputs,num_inputs));
}

int program::add_op_param_double(const char *key,double value)
{
    exprs_.back().add_op_param_double(key,value);
    return 0;
}

int program::add_op_param_ndarray(const char *key,int dim,size_t shape[],double data[])
{
    return -1;
}

evaluation *program::build()
{
    evaluation *Eval = new evaluation(exprs_);
    return Eval;
}
