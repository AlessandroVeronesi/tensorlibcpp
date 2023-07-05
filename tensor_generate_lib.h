#ifndef _TENSOR_GENERATE_LIB_H_
#define _TENSOR_GENERATE_LIB_H_

// Namespace
namespace tensor_lib {

// Static bitmask generation
constexpr unsigned maxBitVal(unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((maxBitVal(bitwidth-1) << 1) | 0x1));
}

constexpr unsigned minNegBitVal(unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((minNegBitVal(bitwidth-1) << 1) | 0x0));
}

// Randomizer

// INT randArray
template <typename myType, unsigned bitwidth>
void randArray(myType* foo, const unsigned Size);

// INT randTensor
template <typename myType, unsigned bitwidth>
void randTensor(std::vector<myType> & foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<myType> > & foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<std::vector<myType> > >& foo);

template <typename myType, unsigned bitwidth>
void randTensor(std::vector<std::vector<std::vector<std::vector<myType> > > >& foo);

// FLOAT randTensor
template <typename myType>
void randTensor(
  std::vector<myType> & foo,
  const myType low_bound, const myType high_bound
  );

template <typename myType>
void randTensor(
  std::vector<std::vector<myType> > & foo,
  const myType low_bound, const myType high_bound
  );

template <typename myType>
void randTensor(
  std::vector<std::vector<std::vector<myType> > >& foo,
  const myType low_bound, const myType high_bound
  );

template <typename myType>
void randTensor(
  std::vector<std::vector<std::vector<std::vector<myType> > > >& foo,
  const myType low_bound, const myType high_bound
  );

}

#include "tpp/tensor_generate_lib.cpp"

#endif
