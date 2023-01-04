#ifndef _RELU_TPP_
#define _RELU_TPP_

template <typename T>
int tensor_lib::debug::relu(
  std::vector<std::vector<T> > & InFvec
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the ReLU operation 
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFvec.size();
  unsigned C = InFvec[0].size();

  // Linear Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      if(InFvec[batch_idx][c] < 0)
        InFvec[batch_idx][c] = (T) 0; 

  // Exit
  return 0;
}

template <typename T>
int tensor_lib::debug::relu(
  std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the ReLU operation 
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFvec.size();
  unsigned C = InFvec[0].size();
  unsigned H = InFvec[0][0].size();
  unsigned W = InFvec[0][0][0].size();

  // Linear Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++) 
      for(unsigned h=0; h<H; h++) 
        for(unsigned w=0; w<W; w++) 
          if(InFvec[batch_idx][c][h][w] < 0)
            InFvec[batch_idx][c][h][w] = (T) 0; 

  // Exit
  return 0;
}

#endif
