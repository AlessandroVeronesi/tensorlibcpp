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

// Bias Addition
template <typename T>
int bias_add(
  std::vector<std::vector<T> >& InFvec,
  std::vector<T>& Bias,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int bias_add(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<T> & Bias,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// EW Addition
template <typename T>
int ew_add(
  std::vector<std::vector<T> >& Amap,
  std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  )

template <typename T>
int ew_add(
  std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  )

// ReLU
template <typename T>
int relu(
  std::vector<std::vector<T> >& InFvec,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int relu(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// MaxPool
template <typename T>
int max_pool(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned KernelSize
  );

}

}

#include "tpp/linear.cpp"
#include "tpp/convolution.cpp"
#include "tpp/bias_add.cpp"
#include "tpp/ew_add.cpp"
#include "tpp/relu.cpp"
#include "tpp/max_pool.cpp"

#endif
