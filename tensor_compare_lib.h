#ifndef _TENSOR_COMPARE_LIB_H_
#define _TENSOR_COMPARE_LIB_H_

// Namespace
namespace tensor_lib {

template <typename myType>
bool compare2Darray(myType** A, myType** B, const unsigned SizeY, const unsigned SizeX);

template <typename myType>
bool compareTensors(std::vector<myType> & A, std::vector<myType> & B);

template <typename myType>
bool compareTensors(std::vector<std::vector<myType> > & A, std::vector<std::vector<myType> > & B);

template <typename myType>
bool compareTensors(std::vector<std::vector<std::vector<myType> > >& A, std::vector<std::vector<std::vector<myType> > >& B);

template <typename myType>
bool compareTensors(std::vector<std::vector<std::vector<std::vector<myType> > > >& A, std::vector<std::vector<std::vector<std::vector<myType> > > >& B);

// End Namespace
}

#include "tpp/tensor_compare_lib.cpp"

#endif
