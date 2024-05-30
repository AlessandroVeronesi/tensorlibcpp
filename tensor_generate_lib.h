#ifndef _TENSOR_GENERATE_LIB_H_
#define _TENSOR_GENERATE_LIB_H_

// Namespace
namespace tensor_lib {

namespace internal {

template <typename T>
struct uniform_distribution_traits
{
  using backend_t = typename std::conditional<(std::is_integral<T>::value || std::is_floating_point<T>::value), T, double>::type;
  using uniform_distribution_t = typename std::conditional<std::is_integral<T>::value, std::uniform_int_distribution<T>,
                                                           std::uniform_real_distribution<backend_t> >::type;
};

template <typename T>
T uniform_rand(const T& lobound, const T&hibound)
{
  using backend_t = typename uniform_distribution_traits<T>::backend_t;
  using uniform_distribution_t = typename uniform_distribution_traits<T>::uniform_distribution_t;

  static std::random_device rd;
  static std::mt19937 gen(rd());
  backend_t _lobound(lobound);
  backend_t _hibound(hibound);
  uniform_distribution_t distr(_lobound, _hibound);

  return T(distr(gen));
}

}

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

#include "tpp/tensor_generate_lib.cpp"

#endif
