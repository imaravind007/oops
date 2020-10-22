#include "expression.h"
#include "tensor.h"
#include <string>
#include <vector>
using namespace std;

expression::expression(int expr_id,const char *op_name,const char *op_type,int *inputs,int num_inputs):expr_id_(expr_id),
op_name_(op_name),op_type_(op_type),inputs_(inputs,inputs+num_inputs),op_param()

{
}

void expression::add_op_param_double(const char *key,double value)
{
    op_param[key] = value; 
}

void expression::add_op_param_ndarray(const char *key,int dim,size_t shape[],double data[])
{
    tensor *tval = new tensor(dim,shape,data);
    op_param_tensor[key] = *tval;

}

int expression::get_id()
{
    return expr_id_;
}
string expression ::get_op_name()
{
    return op_name_;
}
string expression::get_op_type()
{
    return op_type_;
}
map<string,double> expression::get_op_param()
{
    return op_param;
}