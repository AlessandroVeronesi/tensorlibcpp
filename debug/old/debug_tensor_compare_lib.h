#ifndef _TENSOR_COMPARE_LIB_H_DEBUG_
#define _TENSOR_COMPARE_LIB_H_DEBUG_

// Namespace
namespace tensor_lib {

namespace debug {

template <typename T>
bool compareArray(const T* A, const T* B, const unsigned Size);

template <typename T>
bool compare2Darray(const T** A, const T** B, const unsigned SizeY, const unsigned SizeX);

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
bool compareArray(const T* A, const T* B, const unsigned Size, const T t);

template <typename T>
bool compare2Darray(const T** A, T** B, const unsigned SizeY, const unsigned SizeX, const T t);

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

}

#include "tpp/tensor_compare_lib.cpp"

#endif
