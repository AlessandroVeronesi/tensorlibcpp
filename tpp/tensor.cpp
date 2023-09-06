#ifndef _TENSOR_LIB_TENSOR_TPP_
#define _TENSOR_LIB_TENSOR_TPP_

// GET DATA SIZE
inline size_t tensor_lib::tensor<T>::getDataSize()
{
    size_t size=1;
    for(size_t i=0; i<this->ndims; i++) {
        size *= this->dims[i];
    }
    return size;
}

inline size_t tensor_lib::tensor<T>::getDataSize(size_t* dimensions, size_t ndims)
{
    size_t size=1;
    for(size_t i=0; i<ndims; i++) {
        size *= dimensions[i];
    }
    return size;
}

// CTORS
template<typename T>
tensor_lib::tensor<T>::tensor(size_t* dimensions, size_t ndims)
{
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));

    size_t size=getDataSize();
    this->data = new T[size];
}

template<typename T>
~tensor_lib::tensor<T>::tensor()
{
    delete[] data;
    delete[] ndims;
}

// SETDIMS
template<typename T>
void tensor_lib::tensor<T>::reshape(size_t* dimensions, size_t ndims)
{
    TENSOR_ASSERT((this->getDataSize) == (getDataSize(dimensions, ndims)), "reshape: dimensions are not matching");
    
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));
}

// COMPARE
template<typename T>
inline bool tensor_lib::tensor<T>::operator== (const tensor_lib::tensor<T>& foo, const tensor_lib::tensor<T>& other)
{
    if(foo.ndims != other.ndims) return false;
    if(!std::equal(foo.dims, foo.dims+foo.ndims-1, other)) return false;
    
    return std::equal(foo.data, foo.data+foo.getDataSize()-1, other);
}

template<typename T>
inline bool tensor_lib::tensor<T>::operator!= (const tensor_lib::tensor<T>& foo, const tensor_lib::tensor<T>& other)
{
    return !(foo == other);
}

#endif
