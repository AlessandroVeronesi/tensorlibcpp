#ifndef _TENSOR_QUANT_OBSERVER_LIB_H_DEBUG_
#define _TENSOR_QUANT_OBSERVER_LIB_H_DEBUG_

namespace tensor_lib {

namespace debug {

namespace quantization {

// MaxMin Observer
template <typename T>
void MaxMinObserver(
  const std::vector<T> & tensor,
  T& min,
  T& max
  );

template <typename T>
void MaxMinObserver(
  const std::vector<std::vector<T> > & tensor,
  T& min,
  T& max
  );

template <typename T>
void MaxMinObserver(
  const std::vector<std::vector<std::vector<T> > > & tensor,
  T& min,
  T& max
  );

template <typename T>
void MaxMinObserver(
  const std::vector<std::vector<std::vector<std::vector<T> > > > & tensor,
  T& min,
  T& max
  );

}

}

}

#include "tpp/tensor_observer_lib.cpp"

#endif
