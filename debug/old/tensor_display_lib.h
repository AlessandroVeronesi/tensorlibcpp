#ifndef _TENSOR_DISPLAY_LIB_H_
#define _TENSOR_DISPLAY_LIB_H_

namespace tensor_lib {

// Tensor Print
template <typename T>
void print(const std::vector<T> & tensor);

template <typename T>
void print(const std::vector<std::vector<T> > & tensor);

template <typename T>
void print(const std::vector<std::vector<std::vector<T> > > & tensor);

template <typename T>
void print(const std::vector<std::vector<std::vector<std::vector<T> > > > & tensor);

}

#include "tpp/tensor_display_lib.cpp"

#endif
