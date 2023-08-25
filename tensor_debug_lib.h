#ifndef _TENSOR_DEBUG_H_
#define _TENSOR_DEBUG_H_

namespace tensor_lib {

namespace debug {

// Linear
template <typename T>
int linear(
  const std::vector<std::vector<T> > & InFvec,
  const std::vector<std::vector<T> > & Kmat,
  std::vector<std::vector<T> > & Ovec
  );

// Convolution
template <typename T>
int convolution(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Kmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned Stride, const unsigned Padding, const unsigned Dilatation
  );

// Bias Addition
template <typename T>
int bias_add(
  const std::vector<std::vector<T> >& InFvec,
  const std::vector<T>& Bias,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int bias_add(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const std::vector<T> & Bias,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// Batch Norm
template <typename T>
int batch_norm(
  const std::vector<std::vector<T> >& InFvec,
  const std::vector<T>& Mean,
  const std::vector<T>& StdDev,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int batch_norm(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const std::vector<T>& Mean,
  const std::vector<T>& StdDev,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// EW Addition
template <typename T>
int ew_add(
  const std::vector<std::vector<T> >& Amap,
  const std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int ew_add(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// EW Subtraction
template <typename T>
int ew_sub(
  const std::vector<std::vector<T> >& Amap,
  const std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int ew_sub(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// EW Multiplication
template <typename T>
int ew_mul(
  const std::vector<std::vector<T> >& Amap,
  const std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int ew_mul(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// EW Division
template <typename T>
int ew_div(
  const std::vector<std::vector<T> >& Amap,
  const std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int ew_div(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// Scalar Vector Addition
template <typename T>
int add(
  const std::vector<std::vector<T> >& Imap,
  const T scalar,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int add(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Imap,
  const T scalar,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// Scalar Vector Subtraction
template <typename T>
int sub(
  const std::vector<std::vector<T> >& Imap,
  const T scalar,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int sub(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Imap,
  const T scalar,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// Scalar Vector Multiplication
template <typename T>
int mul(
  const std::vector<std::vector<T> >& Imap,
  const T scalar,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int mul(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Imap,
  const T scalar,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// Scalar Vector Division
template <typename T>
int div(
  const std::vector<std::vector<T> >& Imap,
  const T scalar,
  std::vector<std::vector<T> >& Omap
  );

template <typename T>
int div(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Imap,
  const T scalar,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// ReLU
template <typename T>
int relu(
  const std::vector<std::vector<T> >& InFvec,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int relu(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// pReLU
template <typename T>
int prelu(
  const std::vector<std::vector<T> >& InFvec,
  const T scale,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int prelu(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const T scale,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// LeakyReLU
template <typename T>
int leaky_relu(
  const std::vector<std::vector<T> >& InFvec,
  const T scalePos,
  const T scaleNeg,
  std::vector<std::vector<T> >& Ovec
  );

template <typename T>
int leaky_relu(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const T scalePos,
  const T scaleNeg,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  );

// MaxPool
template <typename T>
int max_pool(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const KernelSize
  );

// MinPool
template <typename T>
int min_pool(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const KernelSize
  );

// AvgPool
template <typename T>
int avg_pool(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const KernelSize
  );

}

}

#include "tpp/linear.cpp"
#include "tpp/convolution.cpp"
#include "tpp/bias_add.cpp"
#include "tpp/batch_norm.cpp"
#include "tpp/ew_add.cpp"
#include "tpp/ew_sub.cpp"
#include "tpp/ew_mul.cpp"
#include "tpp/ew_div.cpp"
#include "tpp/add.cpp"
#include "tpp/sub.cpp"
#include "tpp/mul.cpp"
#include "tpp/div.cpp"
#include "tpp/relu.cpp"
#include "tpp/prelu.cpp"
#include "tpp/leaky_relu.cpp"
#include "tpp/max_pool.cpp"

#endif
