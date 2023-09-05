#ifndef _TENSOR_QUANT_CALIBRATION_LIB_H_
#define _TENSOR_QUANT_CALIBRATION_LIB_H_

namespace tensor_lib {

namespace quantization {

// Calibration
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

}

}

#include "tpp/tensor_calibration_lib.cpp"

#endif
