#ifndef _TENSOR_COMPARE_LIB_H_
#define _TENSOR_COMPARE_LIB_H_

// Namespace
namespace tensor_lib {

template <typename myType>
bool compareArray(myType* A, myType* B, const unsigned Size);

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

// W. Threshold
template <typename myType>
bool compareArray(myType* A, myType* B, const unsigned Size, const myType t);

template <typename myType>
bool compare2Darray(myType** A, myType** B, const unsigned SizeY, const unsigned SizeX, const myType t);

template <typename myType>
bool compareTensors(std::vector<myType> & A, std::vector<myType> & B, const myType t);

template <typename myType>
bool compareTensors(std::vector<std::vector<myType> > & A, std::vector<std::vector<myType> > & B, const myType t);

template <typename myType>
bool compareTensors(std::vector<std::vector<std::vector<myType> > >& A, std::vector<std::vector<std::vector<myType> > >& B, const myType t);

template <typename myType>
bool compareTensors(std::vector<std::vector<std::vector<std::vector<myType> > > >& A, std::vector<std::vector<std::vector<std::vector<myType> > > >& B, const myType t);

// End Namespace
}

#include "tpp/tensor_compare_lib.cpp"

#endif
