#ifndef _TENSOR_MANIPULATE_LIB_H_
#define _TENSOR_MANIPULATE_LIB_H_

// Namespace
namespace tensor_lib {

template <typename myType>
int flattenFC_weights(std::vector<std::vector<std::vector<std::vector<myType> > > >& Kmap, std::vector<std::vector<myType> >& Kmatrix);

template <typename myType>
int flattenFC_features(std::vector<std::vector<std::vector<myType> > >& Fmap, std::vector<myType>& Fvec);

template <typename myType>
int rollFC_features(std::vector<myType>& Fvec, std::vector<std::vector<std::vector<myType> > >& Fmap);

// End Namespace
}

#include "tpp/tensor_manipulate_lib.cpp"

#endif
