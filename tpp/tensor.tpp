#ifndef __TENSORCPP_TENSOR_TPP__
#define __TENSORCPP_TENSOR_TPP__

// GET DATA SIZE
template<typename T>
size_t tensorcpp::tensor<T>::getDataSize()
{
    size_t size=1;
    for(size_t i=0; i<this->ndims; i++) {
        size *= this->dims[i];
    }
    return size;
}

template<typename T>
size_t tensorcpp::tensor<T>::getDataSize(const size_t* dimensions, const size_t ndims)
{
    size_t size=1;
    for(size_t i=0; i<ndims; i++) {
        size *= dimensions[i];
    }
    return size;
}

// INDEXING 
template<typename T>
size_t tensorcpp::tensor<T>::getFlattenIndex(const size_t* coordinates)
{
    size_t idx = coordinates[this->ndim - 1];
    for(size_t i = this->ndim - 2; i < SIZE_MAX; i--) {
        idx = idx * dims[i] + coordinates[i];
    }
    return idx;
}

template<typename T>
void tensorcpp::tensor<T>::getCoorinates(const size_t flattenIndex, size_t* coordinates)
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
tensorcpp::tensor<T>::tensor(const size_t* dimensions, const size_t ndims)
{
    delete[] this->dims;

    this->ndims = ndims;
    this->dims = new size_t[ndims];
    std::memcpy(this->dims, dimensions, sizeof(size_t));

    size_t size=getDataSize();
    this->data = new T[size];
}

template<typename T>
tensorcpp::tensor<T>::~tensor()
{
    delete[] data;
    delete[] ndims;
}

// ELEMENT ACCESS
template<typename T>
template<typename ...Args>
T& tensorcpp::tensor<T>::operator()(Args... args) 
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

// FIXME: To Test
//// SET LOGICAL DIMENSIONS
//template<typename T>
//void tensorcpp::tensor<T>::reshape(const size_t* dimensions, const size_t ndims)
//{
//    TENSOR_ASSERT((this->getDataSize) == (getDataSize(dimensions, ndims)), "reshape: dimensions are not matching");
//    
//    delete[] this->dims;
//
//    this->ndims = ndims;
//    this->dims = new size_t[ndims];
//    std::memcpy(this->dims, dimensions, sizeof(size_t));
//}

// FIXME: To Test
//// REALLOC
//template<typename T>
//void tensorcpp::tensor<T>::realloc(const size_t* dimensions, const size_t ndims)
//{
//    delete[] this->data;
//    delete[] this->dims;
//
//    this->ndims = ndims;
//    this->dims = new size_t[ndims];
//    std::memcpy(this->dims, dimensions, sizeof(size_t));
//
//    size_t size=getDataSize();
//    this->data = new T[size];
//}
//
//template<typename T>
//void tensorcpp::tensor<T>::realloc(const size_t* dimensions, const size_t ndims, const T value)
//{
//    delete[] this->data;
//    delete[] this->dims;
//
//    this->ndims = ndims;
//    this->dims = new size_t[ndims];
//    std::memcpy(this->dims, dimensions, sizeof(size_t));
//
//    size_t size=getDataSize();
//    this->data = new T[size];
//    std::memset(this->data, value, size*sizeof(T));
//}

// FIXME: To Test
// COMPARE
//template<typename T>
//bool tensorcpp::tensor<T>::operator==(const tensorcpp::tensor<T>& lhs, const tensorcpp::tensor<T>& rhs)
//{
//    if(lhs.ndims != rhs.ndims) return false;
//    if(!std::equal(lhs.dims, lhs.dims+lhs.ndims-1, rhs)) return false;
//    
//    return std::equal(lhs.data, lhs.data+lhs.getDataSize()-1, rhs);
//}
//
//template<typename T>
//bool tensorcpp::tensor<T>::operator!=(const tensorcpp::tensor<T>& lhs, const tensorcpp::tensor<T>& rhs)
//{
//    return !(lhs == rhs);
//}

#endif
