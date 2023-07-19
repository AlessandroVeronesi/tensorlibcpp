#ifndef _CONVOLUTION_TPP_
#define _CONVOLUTION_TPP_

template <typename T>
int tensor_lib::debug::convolution(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Kmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned Stride, const unsigned Padding, const unsigned Dilatation
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the Convolution operation
  //
  //  FIXME: known limitations
  //  Supports only squared Tensors and Kernels
  //  Dilatation not supported
  //
  //* ================================ *//

  // Input Tensors Shapes
  const unsigned H = InFmap[0][0][0].size();
  const unsigned W = InFmap[0][0].size();
  const unsigned C = InFmap[0].size();
  const unsigned BatchSize = InFmap.size();

  const unsigned R  = Kmap[0][0][0].size();
  const unsigned S  = Kmap[0][0].size();
  const unsigned Ck = Kmap[0].size();
  const unsigned K  = Kmap.size();

  // Parameters Check
  if(!(Stride > 0)) {
    std::cerr << "\033[1;31mERROR: Stride must be at least 1\033[0m" << std::endl;
    return -1;
  }

  if(H != W) {
    std::cerr << "\033[1;31mERROR: Tensor X-Y shapes don't match\033[0m" << std::endl;
    return -1;
  }

  if(S != R) {
    std::cerr << "\033[1;31mERROR: Filter X-Y shapes don't match\033[0m" << std::endl;
    return -1;
  }

  if(C != Ck) {
    std::cerr << "\033[1;31mERROR: Filter-Input C shapes don't match\033[0m" << std::endl;
    return -1;
  }

  if((Dilatation > 1) || !Dilatation){
    std::cerr << "INFO: Dilatation not supported, must be 1" << std::endl;
    return -1;
  }

  // Output Tensor Shapes
  //unsigned S_ = (S-1)*Dilatation+1;
  unsigned S_ = S;
  unsigned R_ = S_;

  unsigned W_ = ((2*Padding + W - S_)/Stride)+1;
  unsigned H_ = ((2*Padding + H - R_)/Stride)+1;
  unsigned C_ = K;

  // Clear Output
  Omap.clear();
  Omap.resize(BatchSize, std::vector<std::vector<std::vector<T> > >(C_, std::vector<std::vector<T> >(H_, std::vector<T>(W_, 0))));

  // Conv Computation Core
  for(unsigned batch_iter=0; batch_iter<BatchSize; batch_iter++)
    for(unsigned k=0; k<C_; k++)
      for(unsigned h=0; h<H_; h++)
        for(unsigned w=0; w<W_; w++)
          for(unsigned c=0; c<C; c++)
            for(unsigned s=0; s<S; s++)
              for(unsigned r=0; r<R; r++)
                Omap[batch_iter][k][h][w] += InFmap[batch_iter][c][(h*Stride) - Padding + s][(w*Stride) - Padding + r] * Kmap[k][c][s][r];

  // Exit
  return 0;
}

#endif
