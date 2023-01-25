# Tensor Library
---
C/C++ template library for tensor operations.
All tensors are based on C/C++ std::vectors.

All the signatures can be checked by looking into the header files.
The libraries does not automatically include the required STL dependencies.
All the header files can be individually included, or jointly included by:

	#include "tensor_lib.h"

## Tensor Compare

	tensor_lib::compare2Darray<type>(arrayA, arrayB, Ysize, Xsize) // Compares 2 C-style arrays, returns true if equals
	tensor_lib::compareTensors<type>(tensorA, tensorB)             // Compares 2 tensors, accepts 1-to-4 dimensional vectors

## Tensor Display

	tensor_lib::print<type>(tensor) // Prints the given tensor, accepts 1-to-4 dimensional vector

## Tensor Generate

	tensor_lib::maxBitVal(bitwidth)                           // Returns the maximum value of a given bitwidth
	tensor_lib::minNegBitVal(bitwidth)                        // Returns the minimum 2's complement value of a given bitwidth
	tensor_lib::randTensor<type, bitwidth>(tensor)            // Randomizes the tensor's data with Integral value of a given bitwidth
	tensor_lib::randTensor<type>(tensor, lowBound, highBound) // Randomizes the tensor's data with Float values in the range lowBound-highBound

## Tensor Manipulate

	tensor_lib::flattenFC_weights<type>(tensor, matrix)  // Flattens the input 4D tensor into a 2D matrix keeping channels contiguity
	tensor_lib::flattenFC_features<type>(tensor, vector) // Flattens the input 3D tensor into a 1D vector keeping channels contiguity
	tensor_lib::rollFC_features<type>(vector, tensor)    // Reroll the input 1D vector into a 3D tensor

## Tensor Debug

	tensor_lib::debug::linear<type>(inVec, wMat, oVec)      // Performs 2D lienar layer between 2D inputs
	tensor_lib::debug::convolution<type>(inTen, wTen, oMap) // Performs 2D convolution layer between 4D inputs
	tensor_lib::debug::bias_add<type>(inF, Bias, oF)        // Performs 1D vector bias addition on 2D or 4D tensors
	tensor_lib::debug::ew_add<type>(A, B, Out)              // Performs Element-Wise addition over 2D or 4D tensors
	tensor_lib::debug::relu<type>(inF, oF)                  // Performs ReLU over 2D or 4D input tensors
	tensor_lib::debug::max_pool<type>(inF, oF, KernelSize)  // Performs a MaxPool of a squared kernel over 4D input tensors

## Tensor Quant
See `QUANT.md` for an explanation of the basic quantization mechanics

	tensor_lib::quantization::MaxMinObserver<type>(tensor, min, max)                      // Implements a MinMax observer on 1D-to-4D tensors
	tensor_lib::quantization::AffineCalibration<type>(min, max, bitwidth, scale, zero)    // Implements an Affine Calibration
	tensor_lib::quantization::SymmetricCalibration<type>(min, max, bitwidth, scale, zero) // Implements an Symmetric Calibration
	tensor_lib::quantization::Quantize<fType, iType>(inT, oT, scale, zero)                // Quantiza the 1D-to-4D input tensor
	tensor_lib::quantization::Dequantize<iType, fType>(inT, oT, scale, zero)              // Dequantize the 1D-to-4D input tensor

