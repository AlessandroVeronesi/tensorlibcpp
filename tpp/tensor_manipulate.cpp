#ifndef __TENSOR_MANIPULATE_TPP__
#define __TENSOR_MANIPULATE_TPP__

// FLATTEN
template<typename T>
void tensor_lib::flatten(
    const std::vector<std::vector<std::vector<T> > >& tensor,
    std::vector<T>& array
    )
{
    size_t C = tensor.size();
    size_t H = tensor[0].size();
    size_t W = tensor[0][0].size();

    tensor_lib::reshape(array, W*H*C);

    size_t it = 0;
    for(size_t c=0; c<C; c++) {
        for(size_t h=0; h<H; h++) {
            for(size_t w=0; w<W; w++) {
                array[it] = tensor[c][h][w];
                it++;
            }
        }
    }
}

template<typename T>
void tensor_lib::flatten(
    const std::vector<std::vector<std::vector<std::vector<T> > > >& tensor,
    std::vector<std::vector<T> >& array
    )
{
    size_t B = tensor.size();
    tensor_lib::reshape(array, 0, B);

    for(size_t b=0; b<B; b++) {
        tensor_lib::flatten(tensor[b], array[b]);
    }
}

template<typename T>
void tensor_lib::flatten(
    const std::vector<std::vector<std::vector<std::vector<std::vector<T> > > > >& tensor,
    std::vector<std::vector<std::vector<T> > >& array
    )
{
    size_t F = tensor.size();
    tensor_lib::reshape(array, 0, 0, F);

    for(size_t f=0; f<F; f++) {
        tensor_lib::flatten(tensor[f], array[f]);
    }
}


// ROLLBACK
template<typename T>
void tensor_lib::rollback(
    const std::vector<T>& array,
    std::vector<std::vector<std::vector<T> > >& tensor
    )
{
    size_t W = 1;
    size_t H = 1;
    size_t C = array.size();

    tensor_lib::reshape(tensor, W, H, C);

    for(size_t c=0; c<C; c++) {
        tensor[c][0][0] = array[c];
    }
}

template<typename T>
void tensor_lib::rollback(
    const std::vector<std::vector<T> >& array,
    std::vector<std::vector<std::vector<std::vector<T> > > >& tensor
    )
{
    size_t B = array.size();
    tensor_lib::reshape(tensor, 0, 0, 0, B);

    for(size_t b=0; b<B; b++) {
        tensor_lib::rollback(array[b], tensor[b]);
    }
}

template<typename T>
void tensor_lib::rollback(
    const std::vector<std::vector<std::vector<T> > >& array,
    std::vector<std::vector<std::vector<std::vector<std::vector<T> > > > >& tensor
    )
{
    size_t F = array.size();
    tensor_lib::reshape(tensor, 0, 0, 0, 0, F);

    for(size_t f=0; f<F; f++) {
        tensor_lib::rollback(array[f], tensor[f]);
    }
}

#endif