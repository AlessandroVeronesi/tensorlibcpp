#ifndef _LEAKY_RELU_TPP_DEBUG_
#define _LEAKY_RELU_TPP_DEBUG_

template <typename T>
int tensor_lib::debug::leaky_relu(
  const std::vector<std::vector<T> > & InFvec,
  const T scalePos,
  const T scaleNeg,
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
      if(InFvec[batch_idx][c] > 0)
        Ovec[batch_idx][c] = scalePos*std::max(InFvec[batch_idx][c], (T)0) + scaleNeg*std::min(InFvec[batch_idx][c], (T)0);

  // Exit
  return 0;
}

template <typename T>
int tensor_lib::debug::leaky_relu(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  const T scalePos,
  const T scaleNeg,
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
          if(InFmap[batch_idx][c][h][w] > 0)
            Omap[batch_idx][c][h][w] = scalePos*std::max(InFmap[batch_idx][c][h][w], (T)0) + scaleNeg*std::min(InFmap[batch_idx][c][h][w], (T)0);

  // Exit
  return 0;
}

#endif
