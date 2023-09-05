#ifndef _TENSOR_LIB_TENSOR_H_
#define _TENSOR_LIB_TENSOR_H_

namespace tensor_lib {

template<typename T>
class tensor
{
 protected:
    T* data;
    size_t* dims;
    size_t ndims;

 public:
    // SETDIMS
    void setDims(size_t* dimensions, size_t ndims);
    //TODO:
    //void setDims(size_t ...Args);

    // CTORS
    tensor(size_t* dimensions, size_t ndims);
    tensor(size_t* dimensions, size_t ndims, T value);
    tensor(const tensor&) = default;

    ~tensor();

    // TODO
    // ASSIGN
    // TODO
    // COMPARE
};

}

#include "tpp/tensor.cpp"

#endif
