
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <type_traits>

#include "tensor_compare_lib.h"
#include "tensor_generate_lib.h"
#include "tensor_display_lib.h"
#include "tensor_debug_lib.h"
#include "tensor_quant_lib.h"

int main(int argc, char* argv[])
{





//  int ret;
//  long unsigned maxval, minval;
//
//  maxval = tensor_lib::maxBitVal(2);
//  minval = tensor_lib::minNegBitVal(2);
//  std::cout << "-I: 2-bits, max uvalue is: " << maxval << ", min ivalue is: " << minval << std::endl;
//
//  maxval = tensor_lib::maxBitVal(8);
//  minval = tensor_lib::minNegBitVal(8);
//  std::cout << "-I: 8-bits, max uvalue is: 0x" << std::hex << maxval << ", min ivalue is: 0x" << std::hex << minval << std::endl;
//
//  maxval = tensor_lib::maxBitVal(16);
//  minval = tensor_lib::minNegBitVal(16);
//  std::cout << "-I: 16-bits, max uvalue is: 0x" << std::hex << maxval << ", min ivalue is: 0x" << std::hex << minval << std::endl;
//
//  std::vector<std::vector<char> > test(2, std::vector<char>(3, 0));
//
//  tensor_lib::randTensor<char, 4>(test);
//
//  tensor_lib::print<char> (test);
//
//  ////////////////////////////////
//  // Float Matrices
//  std::vector<std::vector<float> > floatVec(BATCH, std::vector<float>(C, 0));
//  std::vector<std::vector<float> > floatMat(K, std::vector<float>(C, 0));
//  std::vector<std::vector<float> > floatOut;
//  std::vector<std::vector<float> > floatOut_match;
//  // INT Matrices
//  std::vector<std::vector<long int> > intVec;
//  std::vector<std::vector<long int> > intMat;
//  std::vector<std::vector<long int> > intOut;
//
//  std::cout << "-I: Quant Lib Test" << std::endl;
//
//  // Randomize Data
//  tensor_lib::randTensor<float>(floatVec, -100.0, 100.0);
//  tensor_lib::randTensor<float>(floatMat, -100.0, 100.0);
//
//  std::cout << "-I: Float Data generated" << std::endl;
//
//  std::cout << "-I: Print float Vec" << std::endl;
//  tensor_lib::print<float>(floatVec);
//
//  std::cout << "-I: Print float Mat" << std::endl;
//  tensor_lib::print<float>(floatMat);
//
//  // Observer Insertion
//  float iMax, iMin;
//  float wMax, wMin;
//  tensor_lib::quantization::MaxMinObserver<float>(floatVec, iMin, iMax);
//  tensor_lib::quantization::MaxMinObserver<float>(floatMat, wMin, wMax);
//
//  std::cout << "-I: Alpha, Beta observed" << std::endl;
//
//  // Calibration
//  float iScale, iZeroP;
//  float wScale, wZeroP;
//  tensor_lib::quantization::SymmetricCalibration<float>(iMin, iMax, 8, iScale, iZeroP);
//  tensor_lib::quantization::SymmetricCalibration<float>(wMin, wMax, 8, wScale, wZeroP);
//
//  std::cout << "-I: Scales and Zero Points calculated" << std::endl;
//
//  // Quantize
//  tensor_lib::quantization::Quantize<float, long int>(floatVec, intVec, iScale, iZeroP);
//  tensor_lib::quantization::Quantize<float, long int>(floatMat, intMat, wScale, wZeroP);
//
//  std::cout << "-I: Data quantized" << std::endl;
//
//  std::cout << "-I: Print int Vec" << std::endl;
//  tensor_lib::print<long int>(intVec);
//
//  std::cout << "-I: Print int Mat" << std::endl;
//  tensor_lib::print<long int>(intMat);
//
//  // Compute FLOAT VMM
//  ret = tensor_lib::debug::linear<float>(floatVec, floatMat, floatOut);
//  if (ret) return ret;
//
//  std::cout << "-I: Float Linear calc" << std::endl;
//
//  // Compute INT VMM
//  ret = tensor_lib::debug::linear<long int>(intVec, intMat, intOut);
//  if (ret) return ret;
//
//  std::cout << "-I: Int Linear calc" << std::endl;
//
//  // Dequantize
//  tensor_lib::quantization::Dequantize<long int, float>(intOut, floatOut_match, (iScale*wScale), 0);
//
//  std::cout << "-I: Output dequantized" << std::endl;
//
//  // Compare Output
//  if(tensor_lib::compareTensors<float>(floatOut, floatOut_match)) {
//    std::cout << "-I: float Output and reconstructured Output match" << std::endl;
//  }
//  else {
//    std::cout << "-I: float Output and reconstructured Output doesn't match" << std::endl;
//
//    std::cout << "-I: Original Float" << std::endl;
//    tensor_lib::print<float>(floatOut);
//
//    std::cout << "-I: Reconstruct Float" << std::endl;
//    tensor_lib::print<float>(floatOut_match);
//  }
//
  return 0;
}
