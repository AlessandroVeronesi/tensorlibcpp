#ifndef __TENSORCPP_TENSOR_H__
#define __TENSORCPP_TENSOR_H__

namespace tensorcpp {

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

// FIXME: To Test
//    // SET LOGICAL DIMENSIONS
//    void reshape(const size_t* dimensions, const size_t ndims);
//    // TODO:
//    // void reshape(size_t ...Args);

// FIXME: To Test
//    // REALLOC
//     void realloc(const size_t* dimensions, const size_t ndims);
//     void realloc(const size_t* dimensions, const size_t ndims, T value);

// FIXME: To Test
//    // COMPARE
//     bool operator==(const tensor& lhs, const tensor& rhs);
//     bool operator!=(const tensor& lhs, const tensor& rhs);
};

}

#include "tpp/tensor.tpp"

#endif
