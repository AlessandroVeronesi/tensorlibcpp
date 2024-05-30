#ifndef __TENSOR_MANIPULATE_H__
#define __TENSOR_MANIPULATE_H__

namespace tensor_lib {

// FLATTEN
template<typename T>
void flatten(
    const std::vector<std::vector<std::vector<T> > >& tensor,
    std::vector<T>& array
    );

template<typename T>
void flatten(
    const std::vector<std::vector<std::vector<std::vector<T> > > >& tensor,
    std::vector<std::vector<T> >& array
    );

template<typename T>
void flatten(
    const std::vector<std::vector<std::vector<std::vector<std::vector<T> > > > >& tensor,
    std::vector<std::vector<std::vector<T> > >& array
    );


// ROLLBACK
template<typename T>
void rollback(
    const std::vector<T>& array,
    std::vector<std::vector<std::vector<T> > >& tensor
    );

template<typename T>
void rollback(
    const std::vector<std::vector<T> >& array,
    std::vector<std::vector<std::vector<std::vector<T> > > >& tensor
    );

template<typename T>
void rollback(
    const std::vector<std::vector<std::vector<T> > >& array,
    std::vector<std::vector<std::vector<std::vector<std::vector<T> > > > >& tensor
    );


// RESHAPE
template<typename T>
void reshape(
  std::vector<T>& Tensor,
  const size_t len
)
{
  Tensor.clear();
  Tensor.resize(len, 0);
}

template<typename T>
void reshape(
  std::vector<std::vector<T> >& Tensor,
  const size_t W,
  const size_t H
)
{
  Tensor.clear();
  Tensor.resize(H, std::vector<T>(W, 0));
}

template<typename T>
void reshape(
  std::vector<std::vector<std::vector<T> > >& Tensor,
  const size_t W,
  const size_t H,
  const size_t C
)
{
  Tensor.clear();
  Tensor.resize(C, std::vector<std::vector<T> >(H, std::vector<T>(W, 0)));
}

template<typename T>
void reshape(
  std::vector<std::vector<std::vector<std::vector<T> > > >& Tensor,
  const size_t W,
  const size_t H,
  const size_t C,
  const size_t K
)
{
  Tensor.clear();
  Tensor.resize(K, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::vector<T> >(H, std::vector<T>(W, 0))));
}

}

#include "tpp/tensor_manipulate.cpp"

#endif