
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <type_traits>

#include "tensor_lib.h"

#define BITS 8
#define X 10
#define Y 7
#define C 3
#define B 1

int main(int argc, char* argv[])
{
  std::vector<std::vector<std::vector<std::vector<float> > > > Tensor(B, std::vector<std::vector<std::vector<float> > >(C, std::vector<std::vector<float> >(Y, std::vector<float>(X, 0))));
  std::vector<std::vector<std::vector<std::vector<int> > > > qTensor;
  std::vector<std::vector<std::vector<std::vector<float> > > > rTensor;

  // Init
  tensor_lib::randTensor<float>(Tensor, -10.0, 10.0);

  // Observer
  float Max, Min;
  tensor_lib::quantization::MaxMinObserver<float>(Tensor, Min, Max);

  // Calibration
  float Scale, Zero;
  tensor_lib::quantization::SymmetricCalibration<float>(Min, Max, BITS, Scale, Zero);

  // Quantization
  tensor_lib::quantization::Quantize<float, int>(Tensor, qTensor, Scale, Zero);

  // Dequantize
  tensor_lib::quantization::Dequantize<int, float>(qTensor, rTensor, Scale, Zero);

  // Check
  if(tensor_lib::compareTensors<float>(Tensor, rTensor, 0.5)) {
    std::cout << "DEBUG: Tensors match" << std::endl;
  }
  else {
    std::cout << "DEBUG: Tensors MISMATCH!!!" << std::endl;
    std::cout << "GOLDEN:" << std::endl;
    tensor_lib::print(Tensor);
    std::cout << "\nRECONSTRUCTED" << std::endl;
    tensor_lib::print(rTensor);
  }

  return 0;
}
