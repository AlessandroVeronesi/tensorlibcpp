#ifndef _TENSOR_QUANT_LIB_H_
#define _TENSOR_QUANT_LIB_H_

#include "quant/iutils_lib.h"
#include "quant/tensor_observer_lib.h"
#include "quant/tensor_calibration_lib.h"
#include "quant/tensor_quantize_lib.h"
#include "quant/tensor_dequantize_lib.h"

namespace tensor_lib {

namespace quantization {

template <typename floatT, typename intT>
void perTensorSymmetricQuantization(
    const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<floatT > & scale,
    const char bitwidth
    );

//template <typename floatT, typename intT>
//void perChannelSymmetricQuantization(
//    const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
//    std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
//    std::vector<floatT > & scale
//    );

//////////////////////////////

template<typename intT, typename floatT>
void perTensorSymmetricDequantization(
    const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    const std::vector<floatT > & scale
    );

template<typename intT, typename floatT>
void perTensorSymmetricDequantization(
    const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    const std::vector<floatT > & datScale,
    const std::vector<floatT > & wtScale
    );

}

}

#include "tpp/tensor_quant_lib.cpp"

#endif
