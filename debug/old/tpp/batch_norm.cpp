#ifndef _BATCH_NORM_TPP_
#define _BATCH_NORM_TPP_

template <typename T>
int tensor_lib::debug::batch_norm(
  const std::vector<std::vector<T> > & InFvec,
  const std::vector<T> & Mean,
  const std::vector<T> & StdDev,
  std::vector<std::vector<T> > & Ovec
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the Batch Normalization
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFvec.size();
  unsigned C = InFvec[0].size();

  unsigned Cb = Mean.size();
  unsigned Cc = StdDev.size();

  // Parameters Check
  if(C != Cb) {
    std::cerr << "\033[1;31mERROR: Mean Size doesn't match input\033[0m" << std::endl;
    return -1;
  }
  if(C != Cc) {
    std::cerr << "\033[1;31mERROR: StdDev Size doesn't match input\033[0m" << std::endl;
    return -1;
  }

  // Output Preparation
  Ovec.resize(BatchSize, std::vector<T>(C, 0));

  // Batch Norm Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      Ovec[batch_idx][c] = (InFvec[batch_idx][c] - Mean[c]) / StdDev[c];

  // Exit
  return 0;
}

template <typename T>
int tensor_lib::debug::batch_norm(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const std::vector<T> & Mean,
  const std::vector<T> & StdDev,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the Batch Normalization
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFmap.size();
  unsigned C = InFmap[0].size();
  unsigned H = InFmap[0][0].size();
  unsigned W = InFmap[0][0][0].size();

  unsigned Cb = Mean.size();
  unsigned Cc = StdDev.size();

  // Parameters Check
  if(C != Cb) {
    std::cerr << "\033[1;31mERROR: Mean Size doesn't match input\033[0m" << std::endl;
    return -1;
  }
  if(C != Cc) {
    std::cerr << "\033[1;31mERROR: StdDev Size doesn't match input\033[0m" << std::endl;
    return -1;
  }

  // Output Preparation
  Omap.resize(BatchSize, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::vector<T> >(H, std::vector<T>(W, 0) ) ) );

  // Batch Norm Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      for(unsigned h=0; h<H; h++) 
        for(unsigned w=0; w<W; w++) 
          Omap[batch_idx][c][h][w] = (InFmap[batch_idx][c][h][w] - Mean[c]) / StdDev[c];

  // Exit
  return 0;
}

#endif
