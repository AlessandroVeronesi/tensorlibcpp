#ifndef _TENSOR_QUANT_LIB_TPP_
#define _TENSOR_QUANT_LIB_TPP_

//// MinMaxObserver

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  std::vector<T> tensor,
  T& min,
  T& max
  )
{
  max = *std::max_element(std::begin(tensor), std::end(tensor));
  min = *std::min_element(std::begin(tensor), std::end(tensor));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  std::vector<std::vector<T> > tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned row=0; row<tensor.size(); row++)
    temp.push_back(*std::max_element(std::begin(tensor[row]), std::end(tensor[row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned row=0; row<tensor.size(); row++)
    temp.push_back(*std::min_element(std::begin(tensor[row]), std::end(tensor[row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  std::vector<std::vector<std::vector<T> > > tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned ch=0; ch<tensor.size(); ch++)
    for(unsigned row=0; row<tensor[0].size(); row++)
      temp.push_back(*std::max_element(std::begin(tensor[ch][row]), std::end(tensor[ch][row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned ch=0; ch<tensor.size(); ch++)
    for(unsigned row=0; row<tensor[0].size(); row++)
      temp.push_back(*std::min_element(std::begin(tensor[ch][row]), std::end(tensor[ch][row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  std::vector<std::vector<std::vector<std::vector<T> > > > tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned k=0; k<tensor.size(); k++)
    for(unsigned ch=0; ch<tensor[0].size(); ch++)
      for(unsigned row=0; row<tensor[0][0].size(); row++)
        temp.push_back(*std::max_element(std::begin(tensor[k][ch][row]), std::end(tensor[k][ch][row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned k=0; k<tensor.size(); k++)
    for(unsigned ch=0; ch<tensor[0].size(); ch++)
      for(unsigned row=0; row<tensor[0][0].size(); row++)
        temp.push_back(*std::min_element(std::begin(tensor[k][ch][row]), std::end(tensor[k][ch][row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}

////////////

//// Calibration

template <typename T>
void tensor_lib::quantization::AffineCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  )
{
  static_assert(std::is_floating_point<T>(), "AffineCalibration: T isn't float");

  const int BetaQ  = maxPosBitRange(bitwidth);
  const int AlphaQ = maxNegBitRange(bitwidth);
  const int DistQ  = BetaQ - AlphaQ;

  scale = DistQ / (max - min);
  zero_point = (AlphaQ*max - BetaQ*min) / DistQ;
}

template <typename T>
void tensor_lib::quantization::SymmetricCalibration(
  const T min,
  const T max,
  const char bitwidth,
  T& scale,
  T& zero_point
  )
{
  static_assert(std::is_floating_point<T>(), "SymetricCalibration: T isn't float");

  const int GammaQ = maxPosBitRange(bitwidth);
  T absMax = (max > -min)? max : -min;

  scale = GammaQ / absMax;
  zero_point = 0;
}

////////////

//// Quantize

template <typename floatT, typename intT>
void tensor_lib::quantization::Quantize(
  std::vector<floatT> & floatTensor,
  std::vector<intT> & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  const unsigned X = floatTensor.size();

  intTensor.clear();
  intTensor.resize(X, 0);

  for(unsigned x=0; x<X; x++)
    intTensor[x] = floor(scale*(floatTensor[x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::quantization::Quantize(
  std::vector<std::vector<floatT> > & floatTensor,
  std::vector<std::vector<intT> > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  const unsigned Y = floatTensor.size();
  const unsigned X = floatTensor[0].size();

  intTensor.clear();
  intTensor.resize(Y, std::vector<intT>(X, 0));

  for(unsigned y=0; y<Y; y++)
    for(unsigned x=0; x<X; x++)
      intTensor[y][x] = floor(scale*(floatTensor[y][x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::quantization::Quantize(
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  const unsigned S = floatTensor.size();
  const unsigned Y = floatTensor[0].size();
  const unsigned X = floatTensor[0][0].size();

  intTensor.clear();
  intTensor.resize(S, std::vector<std::vector<intT> >(Y, std::vector<intT>(X, 0)));

  for(unsigned s=0; s<S; s++)
    for(unsigned y=0; y<Y; y++)
      for(unsigned x=0; x<X; x++)
        intTensor[s][y][x] = floor(scale*(floatTensor[s][y][x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::quantization::Quantize(
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  const unsigned C = floatTensor.size();
  const unsigned S = floatTensor[0].size();
  const unsigned Y = floatTensor[0][0].size();
  const unsigned X = floatTensor[0][0][0].size();

  intTensor.clear();
  intTensor.resize(C, std::vector<std::vector<std::vector<intT> > >(S, std::vector<std::vector<intT> >(Y, std::vector<intT>(X, 0))));

  for(unsigned c=0; c<C; c++)
    for(unsigned s=0; s<S; s++)
      for(unsigned y=0; y<Y; y++)
        for(unsigned x=0; x<X; x++)
          intTensor[c][s][y][x] = floor(scale*(floatTensor[c][s][y][x] - zero_point));
}

////////////

//// Dequantize

template <typename intT, typename floatT>
void tensor_lib::quantization::Dequantize(
  std::vector<intT> & intTensor,
  std::vector<floatT> & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  const unsigned X = intTensor.size();

  floatTensor.clear();
  floatTensor.resize(X, 0);

  for(unsigned x=0; x<X; x++)
    floatTensor[x] = (intTensor[x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::quantization::Dequantize(
  std::vector<std::vector<intT> > & intTensor,
  std::vector<std::vector<floatT> > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  const unsigned Y = intTensor.size();
  const unsigned X = intTensor[0].size();

  floatTensor.clear();
  floatTensor.resize(Y, std::vector<floatT>(X, 0));

  for(unsigned y=0; y<Y; y++)
    for(unsigned x=0; x<X; x++)
      floatTensor[y][x] = (intTensor[y][x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::quantization::Dequantize(
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  const unsigned S = intTensor.size();
  const unsigned Y = intTensor[0].size();
  const unsigned X = intTensor[0][0].size();

  floatTensor.clear();
  floatTensor.resize(S, std::vector<std::vector<floatT> >(Y, std::vector<floatT>(X, 0)));

  for(unsigned s=0; s<S; s++)
    for(unsigned y=0; y<Y; y++)
      for(unsigned x=0; x<X; x++)
        floatTensor[s][y][x] = (intTensor[s][y][x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::quantization::Dequantize(
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  const unsigned C = intTensor.size();
  const unsigned S = intTensor[0].size();
  const unsigned Y = intTensor[0][0].size();
  const unsigned X = intTensor[0][0][0].size();

  floatTensor.clear();
  floatTensor.resize(C, std::vector<std::vector<std::vector<floatT> > > (S, std::vector<std::vector<floatT> >(Y, std::vector<floatT>(X, 0))));

  for(unsigned c=0; c<C; c++)
    for(unsigned s=0; s<S; s++)
      for(unsigned y=0; y<Y; y++)
        for(unsigned x=0; x<X; x++)
          floatTensor[c][s][y][x] = (intTensor[c][s][y][x] / scale) + zero_point;
}

////////////

#endif
