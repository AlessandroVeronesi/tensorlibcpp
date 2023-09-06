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

     size_t getDataSize();
     size_t getDataSize(const size_t* dimensions, const size_t ndims);

     size_t getFlattenIndex(const size_t* coordinates);
     void getCoorinates(const size_t flattenIndex, size_t* coordinates);

 public:
    // CTORS
    tensor() { };
    tensor(const size_t* dimensions, const size_t ndims);
    tensor(const size_t* dimensions, const size_t ndims, const T value);
    tensor(const tensor&)=default; // Shallow Copy

    ~tensor();

    // ASSIGN
    //tensor& operator= (const tensor& other); // Shallow Copy

    // DATA ACCESS
    T& operator()(const size_t* coordinates);

    template<typename ...Args>
    T& operator()(Args... args) 
    requires(std::conjunction<std::is_convertible<size_t,Args>...>::value);

    // GET DIMENSIONS
    size_t getNdim();
    void getDims(size_t* dimensions);

    // SET LOGICAL DIMENSIONS
    void reshape(const size_t* dimensions, const size_t ndims);
    // TODO:
    // void reshape(size_t ...Args);

    // REALLOC
     void realloc(const size_t* dimensions, const size_t ndims);
     void realloc(const size_t* dimensions, const size_t ndims, T value);

    // COMPARE
     bool operator==(const tensor& foo, const tensor& other);
     bool operator!=(const tensor& foo, const tensor& other);

// TODO
//    // MATH OP
//
//    // MATH ASSIGNMENT
//     tensor& operator+=(const tensor& other);
//     tensor& operator-=(const tensor& other);
//     tensor& operator*=(const tensor& other);
//     tensor& operator/=(const tensor& other);
};

}

#include "tpp/tensor.cpp"

#endif
