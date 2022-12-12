#ifndef _TENSOR_DISPLAY_LIB_H_
#define _TENSOR_DISPLAY_LIB_H_

namespace tensor_lib {

// Tensor Print
template <typename T>
inline void print(std::vector<T> tensor);

template <typename T>
inline void print(std::vector<std::vector<T> > tensor);

template <typename T>
inline void print(std::vector<std::vector<std::vector<T> > > tensor);

template <typename T>
inline void print(std::vector<std::vector<std::vector<std::vector<T> > > > tensor);

// DEBUG
namespace quantization {

template <typename T> inline void bitPrint(T val, unsigned bitwidth)
{
  static_assert(std::is_integral<T>(), "ERROR(binPrint): T isn't integral");

  for(unsigned i=0; i<bitwidth; i++) {
    std::cout << (unsigned) ((val >> i) & 0x1) << std::flush;
  }
}

template <typename T>
inline void binPrint(std::vector<std::vector<T> > tensor, unsigned bitwidth) {
  for(unsigned i=0; i<tensor.size(); i++) {
    for(unsigned j=0; j<tensor[0].size(); j++) {
      std::cout << " ";
      bitPrint<T>(tensor[i][j], bitwidth);
    }
    std::cout << std:: endl;
  }
}
/////////////////////////////////

}

}

#include "tpp/tensor_display_lib.cpp"

#endif
