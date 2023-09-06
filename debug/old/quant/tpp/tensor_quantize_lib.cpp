#ifndef _TENSOR_QUANTIZE_LIB_TPP_DEBUG_
#define _TENSOR_QUANTIZE_LIB_TPP_DEBUG_

//// Quantize

template <typename floatT, typename intT>
void tensor_lib::debug::quantization::Quantize(
  const std::vector<floatT> & floatTensor,
  std::vector<intT> & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  unsigned X = floatTensor.size();

  intTensor.clear();
  intTensor.resize(X, 0);

  for(unsigned x=0; x<X; x++)
    intTensor[x] = std::floor(scale*(floatTensor[x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::debug::quantization::Quantize(
  const std::vector<std::vector<floatT> > & floatTensor,
  std::vector<std::vector<intT> > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  unsigned Y = floatTensor.size();
  unsigned X = floatTensor[0].size();

  intTensor.clear();
  intTensor.resize(Y, std::vector<intT>(X, 0));

  for(unsigned y=0; y<Y; y++)
    for(unsigned x=0; x<X; x++)
      intTensor[y][x] = std::floor(scale*(floatTensor[y][x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::debug::quantization::Quantize(
  const std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  std::vector<std::vector<std::vector<intT> > > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  unsigned S = floatTensor.size();
  unsigned Y = floatTensor[0].size();
  unsigned X = floatTensor[0][0].size();

  intTensor.clear();
  intTensor.resize(S, std::vector<std::vector<intT> >(Y, std::vector<intT>(X, 0)));

  for(unsigned s=0; s<S; s++)
    for(unsigned y=0; y<Y; y++)
      for(unsigned x=0; x<X; x++)
        intTensor[s][y][x] = std::floor(scale*(floatTensor[s][y][x] - zero_point));
}

template <typename floatT, typename intT>
void tensor_lib::debug::quantization::Quantize(
  const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_floating_point<floatT>(), "Quantize: T isn't float");
  static_assert(std::is_integral<intT>(), "Quantize: T isn't int");

  unsigned C = floatTensor.size();
  unsigned S = floatTensor[0].size();
  unsigned Y = floatTensor[0][0].size();
  unsigned X = floatTensor[0][0][0].size();

  intTensor.clear();
  intTensor.resize(C, std::vector<std::vector<std::vector<intT> > >(S, std::vector<std::vector<intT> >(Y, std::vector<intT>(X, 0))));

  for(unsigned c=0; c<C; c++)
    for(unsigned s=0; s<S; s++)
      for(unsigned y=0; y<Y; y++)
        for(unsigned x=0; x<X; x++)
          intTensor[c][s][y][x] = std::floor(scale*(floatTensor[c][s][y][x] - zero_point));
}


#endif
