#ifndef _TENSOR_GENERATE_LIB_H_
#define _TENSOR_GENERATE_LIB_H_

// Namespace
namespace tensor_lib {

template <unsigned bitwidth>
constexpr long unsigned maxBitVal()
{
  return (bitwidth==0)? 0x1 : ((maxBitVal<bitwidth-1>() << 1) | 0x1);
}

template <unsigned bitwidth>
constexpr long unsigned minNegBitVal()
{
  return (bitwidth==0)? 0x1 : ((maxBitVal<bitwidth-1>() << 1) | 0x0);
}

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<myType> & foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<myType> > & foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<std::vector<myType> > >& foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<std::vector<std::vector<myType> > > >& foo);

}

#include "tpp/tensor_generate_lib.tpp"

#endif
