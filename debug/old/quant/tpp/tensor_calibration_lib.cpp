#ifndef _TENSOR_QUANT_CALIBRATION_LIB_TPP_DEBUG_
#define _TENSOR_QUANT_CALIBRATION_LIB_TPP_DEBUG_

//// Calibration

template <typename T>
void tensor_lib::debug::quantization::AffineCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  )
{
  static_assert(std::is_floating_point<T>(), "AffineCalibration: T isn't float");

  int BetaQ  = maxPosBitRange(bitwidth);
  int AlphaQ = maxNegBitRange(bitwidth);
  int DistQ  = BetaQ - AlphaQ;

  scale = DistQ / (max - min);
  zero_point = (AlphaQ*max - BetaQ*min) / DistQ;
}

template <typename T>
void tensor_lib::debug::quantization::SymmetricCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  )
{
  static_assert(std::is_floating_point<T>(), "SymetricCalibration: T isn't float");

  int GammaQ = maxPosBitRange(bitwidth);
  T absMax = (max > -min)? max : -min;

  scale = GammaQ / absMax;
  zero_point = 0;
}


#endif
