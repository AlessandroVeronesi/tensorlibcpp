#ifndef _LINEAR_TPP_
#define _LINEAR_TPP_

template <typename T>
int tensor_lib::debug::linear(
  std::vector<std::vector<T> > & InFvec,
  std::vector<std::vector<T> > & Kmat,
  std::vector<std::vector<T> > & Ovec
  )
{
  //* ================================ *//
  //  Behavioural Implementation 
  //  of the Linear operation 
  //* ================================ *//

  // Input Tensors Shapes
  unsigned BatchSize = InFvec.size();
  unsigned C = InFvec[0].size();

  unsigned K  = Kmat.size();
  unsigned Ck = Kmat[0].size();

  // Parameter Check
  if(C != Ck) {
    std::cerr << "\033[1;31mERROR: Filter-Input C shapes don't match\033[0m" << std::endl;
    return -1;
  }

  // Clear Output
  Ovec.clear();
  Ovec.resize(BatchSize, std::vector<T>(K, 0));

  // Linear Computation
  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned k=0; k<K; k++)
      for(unsigned c=0; c<C; c++)
        Ovec[batch_idx][k] += InFvec[batch_idx][c] * Kmat[k][c];

  // Exit
  return 0;
}

#endif
