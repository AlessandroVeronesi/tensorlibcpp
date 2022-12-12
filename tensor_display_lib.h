#ifndef _TENSOR_DISPLAY_LIB_H_
#define _TENSOR_DISPLAY_LIB_H_

namespace tensor_lib {

// Tensor Print
template <typename T>
inline void print(std::vector<T> tensor);

template <typename T>
inline void print(std::vector<std::vector<T> > tensor);

template <typename T>
inline void print(std::vector<std::vector<std::vector<T> > > tensor);

template <typename T>
inline void print(std::vector<std::vector<std::vector<std::vector<T> > > > tensor);

}

#include "tpp/tensor_display_lib.cpp"

#endif
