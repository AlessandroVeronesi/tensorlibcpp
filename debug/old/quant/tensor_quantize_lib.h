#ifndef _TENSOR_QUANTIZE_LIB_H_
#define _TENSOR_QUANTIZE_LIB_H_

namespace tensor_lib {

namespace quantization {

//// Quantize

template <typename floatT, typename intT>
void Quantize(
  const std::vector<floatT> & floatTensor,
  std::vector<intT> & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  const std::vector<std::vector<floatT> > & floatTensor,
  std::vector<std::vector<intT> > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  const std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

}

}

#include "tpp/tensor_quantize_lib.cpp"

#endif
