#ifndef _TENSOR_DEBUG_H_
#define _TENSOR_DEBUG_H_

namespace tensor_lib {

namespace debug {

template <typename T>
int linear(
  std::vector<std::vector<T> > & InFvec,
  std::vector<std::vector<T> > & Kmat,
  std::vector<std::vector<T> > & Ovec
  );

template <typename T>
int convolution(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Kmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned Stride, const unsigned Padding, const unsigned Dilatation
  );

}

template <typename T>
int relu(
  std::vector<std::vector<T> > & InFvec
  );

template <typename T>
int relu(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap
  );

}

#include "tpp/linear.cpp"
#include "tpp/convolution.cpp"
#include "tpp/relu.cpp"

#endif
