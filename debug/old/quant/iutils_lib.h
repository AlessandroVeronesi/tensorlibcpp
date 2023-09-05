#ifndef _TENSOR_QUANT_IUTILS_LIB_H_
#define _TENSOR_QUANT_IUTILS_LIB_H_

namespace tensor_lib {

namespace quantization {

//// Auxiliary Functions

constexpr unsigned myPow2(const char p)
{
  return (p%2)? ((p==1)? 2 : (2*myPow2(p/2)*myPow2(p/2))) : ((p==0)? 1 : (myPow2(p/2)*myPow2(p/2)));
}

constexpr unsigned myLog2(const unsigned p)
{
  return (p<2)? 0 : (1 + myLog2(p/2));
}

constexpr unsigned maxBitRange(const char bitwidth)
{
  return myPow2(bitwidth);
}

constexpr int maxPosBitRange(const char bitwidth)
{
  return myPow2(bitwidth-1)-1;
}

constexpr int maxNegBitRange(const char bitwidth)
{
  return -myPow2(bitwidth-1);
}

}

}

#endif
