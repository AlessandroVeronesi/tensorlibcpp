#ifndef __TENSOR_QUANT_LIB_TPP__
#define __TENSOR_QUANT_LIB_TPP__

template <typename floatT, typename intT>
void tensor_lib::quantization::perTensorSymmetricQuantization(
    const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<floatT > & scale,
    const char bitwidth
    )
{
    for(size_t batch_iter=0; batch_iter<floatTensor.size(); batch_iter++) {
        std::vector<std::vector<std::vector<intT> > > qTensor;
        floatT datMax, datMin;
        floatT qScale, qZeroPoint;
        // Observers Insertion
        tensor_lib::quantization::MaxMinObserver<floatT>(floatTensor[batch_iter], datMin, datMax);

        // Calibration
        tensor_lib::quantization::SymmetricCalibration<floatT>(datMin, datMax, bitwidth, qScale, qZeroPoint); 

        // Quantization
        tensor_lib::quantization::Quantize<floatT, intT>(floatTensor[batch_iter], qTensor, qScale, qZeroPoint);

        // Save Results
        intTensor.push_back(qTensor);
        scale.push_back(qScale);
    }
}

//template <typename floatT, typename intT>
//void tensor_lib::quantization::perChannelSymmetricQuantization(
//    const std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
//    std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
//    std::vector<floatT > & scale
//    );

//////////////////////////////

template<typename intT, typename floatT>
void tensor_lib::quantization::perTensorSymmetricDequantization(
    const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    const std::vector<floatT > & scale
    )
{
    for(size_t batch_iter=0; batch_iter<intTensor.size(); batch_iter++) {
        std::vector<std::vector<std::vector<floatT> > > Omap_single;
        
        tensor_lib::quantization::Dequantize<intT, floatT>(intTensor[batch_iter], Omap_single, scale[batch_iter], 0); // Supports only simmetric quant

        floatTensor.push_back(Omap_single);
    }
}


template<typename intT, typename floatT>
void tensor_lib::quantization::perTensorSymmetricDequantization(
    const std::vector<std::vector<std::vector<std::vector<intT> > > > & intTensor,
    std::vector<std::vector<std::vector<std::vector<floatT> > > > & floatTensor,
    const std::vector<floatT > & datScale,
    const std::vector<floatT > & wtScale
    )
{
    for(size_t batch_iter=0; batch_iter<intTensor.size(); batch_iter++) {
        std::vector<std::vector<std::vector<floatT> > > Omap_single;
        
        for(size_t channel=0; channel<intTensor[0].size(); channel++) {
            std::vector<std::vector<floatT> > Omap_single_channel;

            tensor_lib::quantization::Dequantize<intT, floatT>(intTensor[batch_iter][channel], Omap_single_channel, datScale[batch_iter]*wtScale[channel], 0); // Supports only simmetric quant

            Omap_single.push_back(Omap_single_channel);
        }

        floatTensor.push_back(Omap_single);
    }
}


#endif