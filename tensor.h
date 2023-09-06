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

    inline size_t getSize();
    inline size_t getDataSize(size_t* dimensions, size_t ndims);

 public:
    // SETDIMS
    void reshape(size_t* dimensions, size_t ndims);
    //TODO:
    //void setDims(size_t ...Args);

    // REALLOC
    void realloc(size_t* dimensions, size_t ndims);

    // CTORS
    tensor(size_t* dimensions, size_t ndims);
    tensor(size_t* dimensions, size_t ndims, T value);
    tensor(const tensor&)=default; // Shallow Copy

    ~tensor();

    // ASSIGN
    //tensor& operator= (const tensor& other); // Shallow Copy

    // COMPARE
    inline bool operator== (const tensor& foo, const tensor& other);
    inline bool operator!= (const tensor& foo, const tensor& other);
};

}

#include "tpp/tensor.cpp"

#endif
