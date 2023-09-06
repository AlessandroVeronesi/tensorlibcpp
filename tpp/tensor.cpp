#ifndef _TENSOR_LIB_TENSOR_TPP_
#define _TENSOR_LIB_TENSOR_TPP_

// GET DATA SIZE
template<typename T>
size_t tensor_lib::tensor<T>::getDataSize()
{
    size_t size=1;
    for(size_t i=0; i<this->ndims; i++) {
        size *= this->dims[i];
    }
    return size;
}

template<typename T>
size_t tensor_lib::tensor<T>::getDataSize(const size_t* dimensions, const size_t ndims)
{
    size_t size=1;
    for(size_t i=0; i<ndims; i++) {
        size *= dimensions[i];
    }
    return size;
}

// INDEXING 
template<typename T>
size_t tensor_lib::tensor<T>::getFlattenIndex(const size_t* coordinates)
{
    size_t idx = coordinates[this->ndim - 1];
    for(size_t i = this->ndim - 2; i < SIZE_MAX; i--) {
        idx = idx * dims[i] + coordinates[i];
    }
    return idx;
}

template<typename T>
void tensor_lib::tensor<T>::getCoorinates(const size_t flattenIndex, size_t* coordinates)
{   
    size_t tmp = 1;
    for(size_t i = 0; i < this->ndim - 1; i++) {
        tmp *= this->dims[i];
    }
    for(size_t i = this->ndim - 1; i > 0; i--) {
        coordinates[i] = flattenIndex / tmp;
        flattenIndex = flattenIndex % tmp;
        tmp = tmp / this->dims[i - 1];
    }
    coordinates[0] = flattenIndex;
}

// CTORS
template<typename T>
tensor_lib::tensor<T>::tensor(const size_t* dimensions, const size_t ndims)
{
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));

    size_t size=getDataSize();
    this->data = new T[size];
}

template<typename T>
tensor_lib::tensor<T>::~tensor()
{
    delete[] data;
    delete[] ndims;
}

// ELEMENT ACCESS
template<typename T>
template<typename ...Args>
T& tensor_lib::tensor<T>::operator()(Args... args) 
requires(std::conjunction<std::is_convertible<size_t,Args>...>::value)
{
    
}

// GET DIMENSIONS
template<typename T>
size_t getNdim() { return this->ndims; }

template<typename T>
void getDims(size_t* dimensions)
{
    std::memcpy(dimensions, this->dims, sizeof(size_t));
}

// SET LOGICAL DIMENSIONS
template<typename T>
void tensor_lib::tensor<T>::reshape(const size_t* dimensions, const size_t ndims)
{
    TENSOR_ASSERT((this->getDataSize) == (getDataSize(dimensions, ndims)), "reshape: dimensions are not matching");
    
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));
}

// REALLOC
template<typename T>
void tensor_lib::tensor<T>::realloc(const size_t* dimensions, const size_t ndims)
{
    delete[] this->data;
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));

    size_t size=getDataSize();
    this->data = new T[size];
}

template<typename T>
void tensor_lib::tensor<T>::realloc(const size_t* dimensions, const size_t ndims, const T value)
{
    delete[] this->data;
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));

    size_t size=getDataSize();
    this->data = new T[size];
    std::memset(this->data, value, size*sizeof(T));
}

// COMPARE
template<typename T>
bool tensor_lib::tensor<T>::operator==(const tensor_lib::tensor<T>& foo, const tensor_lib::tensor<T>& other)
{
    if(foo.ndims != other.ndims) return false;
    if(!std::equal(foo.dims, foo.dims+foo.ndims-1, other)) return false;
    
    return std::equal(foo.data, foo.data+foo.getDataSize()-1, other);
}

template<typename T>
bool tensor_lib::tensor<T>::operator!=(const tensor_lib::tensor<T>& foo, const tensor_lib::tensor<T>& other)
{
    return !(foo == other);
}

// TODO
//// MATH ASSIGNMENT
//template<typename T>
//tensor_lib::tensor<T>& tensor_lib::tensor<T>::operator+= (const tensor_lib::tensor<T>& other)
//{
//}
//
//template<typename T>
//tensor_lib::tensor<T>& tensor_lib::tensor<T>::operator-= (const tensor_lib::tensor<T>& other)
//{
//}
//
//template<typename T>
//tensor_lib::tensor<T>& tensor_lib::tensor<T>::operator*= (const tensor_lib::tensor<T>& other)
//{
//}
//
//template<typename T>
//tensor_lib::tensor<T>& tensor_lib::tensor<T>::operator/= (const tensor_lib::tensor<T>& other)
//{
//}


#endif
