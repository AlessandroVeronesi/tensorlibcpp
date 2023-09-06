#ifndef _TENSOR_DEQUANTIZE_LIB_H_DEBUG_
#define _TENSOR_DEQUANTIZE_LIB_H_DEBUG_

namespace tensor_lib {

namespace debug {

namespace quantization {

//// Dequantize

template <typename intT, typename floatT>
void Dequantize(
  const std::vector<intT> & intTensor,
  std::vector<floatT> & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  const std::vector<std::vector<intT> > & intTensor,
  std::vector<std::vector<floatT> > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  const std::vector<std::vector<std::vector<intT> > > & intTensor,
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  const std::vector<std::vector<std::vector<std::vector<std::vector<intT> > > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<std::vector<floatT> > > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

}

}

}

#include "tpp/tensor_dequantize_lib.cpp"

#endif
