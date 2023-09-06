#ifndef _TENSOR_DEQUANTIZE_LIB_TPP_DEBUG_
#define _TENSOR_DEQUANTIZE_LIB_TPP_DEBUG_

//// Dequantize

template <typename intT, typename floatT>
void tensor_lib::debug::quantization::Dequantize(
  const std::vector<intT> & intTensor,
  std::vector<floatT> & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  unsigned X = intTensor.size();

  floatTensor.clear();
  floatTensor.resize(X, 0);

  for(unsigned x=0; x<X; x++)
    floatTensor[x] = (intTensor[x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::debug::quantization::Dequantize(
  const std::vector<std::vector<intT> > & intTensor,
  std::vector<std::vector<floatT> > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  unsigned Y = intTensor.size();
  unsigned X = intTensor[0].size();

  floatTensor.clear();
  floatTensor.resize(Y, std::vector<floatT>(X, 0));

  for(unsigned y=0; y<Y; y++)
    for(unsigned x=0; x<X; x++)
      floatTensor[y][x] = (intTensor[y][x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::debug::quantization::Dequantize(
  const std::vector<std::vector<std::vector<intT> > > & intTensor,
  std::vector<std::vector<std::vector<floatT> > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  unsigned S = intTensor.size();
  unsigned Y = intTensor[0].size();
  unsigned X = intTensor[0][0].size();

  floatTensor.clear();
  floatTensor.resize(S, std::vector<std::vector<floatT> >(Y, std::vector<floatT>(X, 0)));

  for(unsigned s=0; s<S; s++)
    for(unsigned y=0; y<Y; y++)
      for(unsigned x=0; x<X; x++)
        floatTensor[s][y][x] = (intTensor[s][y][x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::debug::quantization::Dequantize(
  const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  unsigned C = intTensor.size();
  unsigned S = intTensor[0].size();
  unsigned Y = intTensor[0][0].size();
  unsigned X = intTensor[0][0][0].size();

  floatTensor.clear();
  floatTensor.resize(C, std::vector<std::vector<std::vector<floatT> > > (S, std::vector<std::vector<floatT> >(Y, std::vector<floatT>(X, 0))));

  for(unsigned c=0; c<C; c++)
    for(unsigned s=0; s<S; s++)
      for(unsigned y=0; y<Y; y++)
        for(unsigned x=0; x<X; x++)
          floatTensor[c][s][y][x] = (intTensor[c][s][y][x] / scale) + zero_point;
}

template <typename intT, typename floatT>
void tensor_lib::debug::quantization::Dequantize(
  const std::vector<std::vector<std::vector<std::vector<std::vector<intT> > > > > & intTensor,
  std::vector<std::vector<std::vector<std::vector<std::vector<floatT> > > > > & floatTensor,
  const floatT scale,
  const floatT zero_point
  )
{
  static_assert(std::is_integral<intT>(), "Dequantize: T isn't int");
  static_assert(std::is_floating_point<floatT>(), "Dequantize: T isn't float");

  unsigned F = intTensor.size();
  unsigned C = intTensor[0].size();
  unsigned S = intTensor[0][0].size();
  unsigned Y = intTensor[0][0][0].size();
  unsigned X = intTensor[0][0][0][0].size();

  floatTensor.clear();
  floatTensor.resize(F, std::vector<std::vector<std::vector<std::vector<floatT> > > >(C, std::vector<std::vector<std::vector<floatT> > >(S, std::vector<std::vector<floatT> >(Y, std::vector<floatT>(X, 0)))));

  for(unsigned f=0; f<F; f++)
    for(unsigned c=0; c<C; c++)
      for(unsigned s=0; s<S; s++)
        for(unsigned y=0; y<Y; y++)
          for(unsigned x=0; x<X; x++)
            floatTensor[f][c][s][y][x] = (intTensor[f][c][s][y][x] / scale) + zero_point;
}

#endif
