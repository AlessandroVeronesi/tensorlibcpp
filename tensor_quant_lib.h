#ifndef _TENSOR_QUANT_LIB_H_
#define _TENSOR_QUANT_LIB_H_

namespace tensor_lib {

namespace quantization {

//// Auxiliary Functions

constexpr unsigned myPow2(char p)
{
  return (p%2)? ((p==1)? 2 : (2*myPow2(p/2)*myPow2(p/2))) : ((p==0)? 1 : (myPow2(p/2)*myPow2(p/2)));
}

constexpr unsigned myLog2(unsigned p)
{
  return (p<2)? 0 : (1 + myLog2(p/2));
}

constexpr unsigned maxBitRange(char bitwidth)
{
  return myPow2(bitwidth);
}

constexpr int maxPosBitRange(char bitwidth)
{
  return myPow2(bitwidth-1)-1;
}

constexpr int maxNegBitRange(char bitwidth)
{
  return -myPow2(bitwidth-1);
}

//// MinMaxObserver

template <typename T>
inline void MaxMinObserver(
  std::vector<T> tensor,
  T& min,
  T& max
  );

template <typename T>
inline void MaxMinObserver(
  std::vector<std::vector<T> > tensor,
  T& min,
  T& max
  );

template <typename T>
inline void MaxMinObserver(
  std::vector<std::vector<std::vector<T> > > tensor,
  T& min,
  T& max
  );

template <typename T>
inline void MaxMinObserver(
  std::vector<std::vector<std::vector<std::vector<T> > > > tensor,
  T& min,
  T& max
  );

////////////

//// Calibration

template <typename T>
void AffineCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  );

template <typename T>
void SymmetricCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  );

////////////

//// Quantize

template <typename floatT, typename intT>
void Quantize(
  std::vector<floatT> & floatTensor,
  std::vector<intT> & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  std::vector<std::vector<floatT> > & floatTensor,
  std::vector<std::vector<intT> > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename floatT, typename intT>
void Quantize(
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  const floatT scale,
  const floatT zero_point
  );

////////////

//// Dequantize

template <typename intT, typename floatT>
void Dequantize(
  std::vector<intT> & intTensor,
  std::vector<floatT> & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  std::vector<std::vector<intT> > & intTensor,
  std::vector<std::vector<floatT> > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

template <typename intT, typename floatT>
void Dequantize(
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  );

////////////

}

}

#include "tpp/tensor_quant_lib.cpp"

#endif
