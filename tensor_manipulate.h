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
void tensor_lib::rollback(
    const std::vector<T>& array,
    std::vector<std::vector<std::vector<std::vector<T> > > >& tensor
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

// PADDING
template<typename T>
void padding(
    const std::vector<std::vector<std::vector<std::vector<T> > > >& in_tensor,
    std::vector<std::vector<std::vector<std::vector<T> > > >&       out_tensor,
    const size_t PaddingX, const size_t PaddingY
)
{
    size_t B = in_tensor.size();
    size_t C = in_tensor[0].size();
    size_t H = in_tensor[0][0].size();
    size_t W = in_tensor[0][0][0].size();

    size_t He = H + 2*PaddingY;
    size_t We = H + 2*PaddingX;

    out_tensor.clear();
    out_tensor.resize(B, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::vector<T> >(He, std::vector<T>(We, 0))));

    for(size_t b=0; b<B; b++) {
        for(size_t c=0; c<C; c++) {
            for(size_t h=0; h<H; h++) {
                for(size_t w=0; w<W; w++) {
                    out_tensor[b][c][h + PaddingY][w + PaddingX] = in_tensor[b][c][h][w];
                }
            }
        }
    }
}

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