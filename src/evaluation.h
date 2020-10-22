#ifndef EVALUATION_H
#define EVALUATION_H

#include "expression.h"
#include "tensor.h"
#include "eva_op.h"
#include<memory>

#include<map>
using namespace std;

class evaluation
{
public:
    map<string,double> kwargs_;
    map<string,tensor>kwargs_tensor;
    vector<expression> exprs_;
    map<int,tensor>variables_;
    evaluation(const std::vector<expression> &exprs);

    void add_kwargs_double(const char *key,double value);

    void add_kwargs_ndarray(const char *key,int dim,size_t shape[],double data[]);

    // return 0 for success
    int execute();

    // return the variable computed by the last expression
    // double &get_result();
    tensor &get_result();

private:
    // double result_;
    tensor result_;
    std::vector<std::shared_ptr<eval_op>> ops_;
}; // class evaluation

#endif // EVALUATION_H
