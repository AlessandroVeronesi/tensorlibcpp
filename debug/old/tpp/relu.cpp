#ifndef _RELU_TPP_DEBUG_
#define _RELU_TPP_DEBUG_

template <typename T>
int tensor_lib::debug::relu(
  const std::vector<std::vector<T> > & InFvec,
  std::vector<std::vector<T> > & Ovec
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the ReLU operation 
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFvec.size();
  unsigned C = InFvec[0].size();

  // Output Preparation
  Ovec.resize(BatchSize, std::vector<T>(C, 0));

  // ReLU Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      Ovec[batch_idx][c] = std::max(InFvec[batch_idx][c], (T) 0);

  // Exit
  return 0;
}

template <typename T>
int tensor_lib::debug::relu(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the ReLU operation 
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFmap.size();
  unsigned C = InFmap[0].size();
  unsigned H = InFmap[0][0].size();
  unsigned W = InFmap[0][0][0].size();

  // Output Preparation
  Omap.resize(BatchSize, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::vector<T> >(H, std::vector<T>(W, 0) ) ) );

  // ReLU Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      for(unsigned h=0; h<H; h++) 
        for(unsigned w=0; w<W; w++) 
          Omap[batch_idx][c][h][w] = std::max(InFmap[batch_idx][c][h][w], (T) 0);

  // Exit
  return 0;
}

#endif
