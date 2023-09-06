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
    inline size_t getDataSize(const size_t* dimensions, const size_t ndims);

    inline size_t getFlattenIndex(const size_t* coordinates);
    inline size_t* getCoorinates(const size_t flattenIndex);

 public:
    // CTORS
    tensor(const size_t* dimensions, const size_t ndims);
    tensor(const size_t* dimensions, const size_t ndims, const T value);
    tensor(const tensor&)=default; // Shallow Copy

    ~tensor();

    // ASSIGN
    //tensor& operator= (const tensor& other); // Shallow Copy

    // COMPARE
    inline bool operator== (const tensor& foo, const tensor& other);
    inline bool operator!= (const tensor& foo, const tensor& other);

    // MATH OP

    // MATH ASSIGNMENT
    inline tensor& operator+=(const tensor& other);
    inline tensor& operator-=(const tensor& other);
    inline tensor& operator*=(const tensor& other);
    inline tensor& operator/=(const tensor& other);

    // GET DIMENSIONS
    inline size_t getNdim();
    inline void getDims(size_t* dimensions);

    // CHANGE LOGICAL SIZE
    inline void reshape(const size_t* dimensions, const size_t ndims);
    // TODO:
    //inline void reshape(size_t ...Args);

    // REALLOC
    inline void realloc(const size_t* dimensions, const size_t ndims);
    inline void realloc(const size_t* dimensions, const size_t ndims, T value);
};

}

#include "tpp/tensor.cpp"

#endif
