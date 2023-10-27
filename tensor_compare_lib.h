#ifndef _TENSOR_COMPARE_LIB_H_
#define _TENSOR_COMPARE_LIB_H_

// Namespace
namespace tensor_lib {

template <typename T>
bool compareArray(const T* A, const T* B, const size_t Size);

template <typename T>
bool compare2Darray(const T** A, const T** B, const size_t SizeY, const size_t SizeX);

template <typename T>
bool compareTensors(const std::vector<T> & A, const std::vector<T> & B);

template <typename T>
bool compareTensors(const std::vector<std::vector<T> > & A, const std::vector<std::vector<T> > & B);

template <typename T>
bool compareTensors(const std::vector<std::vector<std::vector<T> > >& A, const std::vector<std::vector<std::vector<T> > >& B);

template <typename T>
bool compareTensors(const std::vector<std::vector<std::vector<std::vector<T> > > >& A, const std::vector<std::vector<std::vector<std::vector<T> > > >& B);

// W. Threshold
template <typename T>
bool compareArray(const T* A, const T* B, const size_t Size, const T t);

template <typename T>
bool compare2Darray(const T** A, const T** B, const size_t SizeY, const size_t SizeX, const T t);

template <typename T>
bool compareTensors(const std::vector<T> & A, const std::vector<T> & B, const T t);

template <typename T>
bool compareTensors(const std::vector<std::vector<T> > & A, const std::vector<std::vector<T> > & B, const T t);

template <typename T>
bool compareTensors(const std::vector<std::vector<std::vector<T> > >& A, const std::vector<std::vector<std::vector<T> > >& B, const T t);

template <typename T>
bool compareTensors(const std::vector<std::vector<std::vector<std::vector<T> > > >& A, const std::vector<std::vector<std::vector<std::vector<T> > > >& B, const T t);

// End Namespace
}

#include "tpp/tensor_compare_lib.cpp"

#endif
