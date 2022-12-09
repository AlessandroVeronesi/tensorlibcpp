#ifndef _TENSOR_GENERATE_LIB_H_
#define _TENSOR_GENERATE_LIB_H_

// Namespace
namespace tensor_lib {

constexpr unsigned maxBitVal(unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((maxBitVal(bitwidth-1) << 1) | 0x1));
}

constexpr unsigned minNegBitVal(unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((minNegBitVal(bitwidth-1) << 1) | 0x0));
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

#include "tpp/tensor_generate_lib.cpp"

#endif
