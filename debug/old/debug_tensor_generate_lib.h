#ifndef _TENSOR_GENERATE_LIB_H_DEBUG_
#define _TENSOR_GENERATE_LIB_H_DEBUG_

// Namespace
namespace tensor_lib {

namespace debug {

// Static bitmask generation
constexpr unsigned maxBitVal(const unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((maxBitVal(bitwidth-1) << 1) | 0x1));
}

constexpr unsigned minNegBitVal(const unsigned bitwidth)
{
  return (bitwidth==0)? 0 : ((bitwidth==1)? 0x1 : ((minNegBitVal(bitwidth-1) << 1) | 0x0));
}

// Randomizer

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

}

#include "tpp/tensor_generate_lib.cpp"

#endif
