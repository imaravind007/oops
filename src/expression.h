#ifndef EXPRESSION_H
#define EXPRESSION_H
using namespace std;
#include "tensor.h"
#include<vector>
#include<string>
#include<map>

class evaluation;

class expression
{
    friend class evaluation;

private:
    int expr_id_;
    string op_name_;
    string op_type_ ;
    vector<int> inputs_;
    map<string, double>op_param;
    map<string, tensor>op_param_tensor;
public:
    int get_id(); 
    string get_op_name();
    string get_op_type();
    map<string,double> get_op_param();
    expression(int expr_id,const char *op_name,const char *op_type,int *inputs,int num_inputs);

    void add_op_param_double(const char *key,double value);

    void add_op_param_ndarray(const char *key, int dim, size_t shape[],double data[]);
}; // class expression


#endif // EXPRESSION_H
