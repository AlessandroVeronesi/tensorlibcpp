#ifndef _TENSOR_DEBUG_H_
#define _TENSOR_DEBUG_H_

namespace tensor_lib {

namespace debug {

// Linear
template <typename T>
int linear(
  std::vector<std::vector<T> > & InFvec,
  std::vector<std::vector<T> > & Kmat,
  std::vector<std::vector<T> > & Ovec
  );

// Convolution
template <typename T>
int convolution(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Kmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned Stride, const unsigned Padding, const unsigned Dilatation
  );

// Bias
template <typename T>
int bias_add(
  std::vector<std::vector<T> > & InFvec,
  std::vector<T> & Bias,
  std::vector<std::vector<T> > & Ovec
  );

template <typename T>
int bias_add(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<T> & Bias,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// ReLU
template <typename T>
int relu(
  std::vector<std::vector<T> > & InFvec,
  std::vector<std::vector<T> > & Ovec
  );

template <typename T>
int relu(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

}

}

#include "tpp/linear.cpp"
#include "tpp/convolution.cpp"
#include "tpp/relu.cpp"

#endif
