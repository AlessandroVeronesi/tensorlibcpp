#ifndef _TENSOR_QUANT_LIB_H_
#define _TENSOR_QUANT_LIB_H_

namespace tensor_lib {

namespace quantization {

//// Auxiliary Functions

constexpr unsigned myPow2(char p)
{
// if (p == 0) return 1;
//  if (p == 1) return 2;
//  
//  int tmp = myPow2(p/2);
//
//  if (p%2 == 0)
//    return tmp * tmp;
//  else
//    return 2 * tmp * tmp;

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

//template <typename oldT, typename newT> inline newT sign_extension(const oldT val, const unsigned oldBitwidth)
//{
//  static_assert(std::is_integral<newT>(), "ERROR(sign_extension): new type isn't integral");
//  static_assert(std::is_integral<oldT>(), "ERROR(sign_extension): old type isn't integral");
//
//  const unsigned newBitwidth = sizeof(newT)*8;
//  char sign = (val >> (oldBitwidth-1)) & 0x1;
//
//  newT extendedVal = val;
//  if(sign) {
//    for(unsigned bit=oldBitwidth; bit<newBitwidth; bit++)
//      extendedVal |= 0x1 << bit;
//  }
//
//  return extendedVal;
//}

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
