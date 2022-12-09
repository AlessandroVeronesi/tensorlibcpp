#ifndef _TENSOR_MANIPULATE_LIB_TPP_
#define _TENSOR_MANIPULATE_LIB_TPP_

template <typename myType>
int tensor_lib::flattenFC_weights(std::vector<std::vector<std::vector<std::vector<myType> > > >& Kmap, std::vector<std::vector<myType> >& Kmatrix)
{
  if(Kmap[0][0][0].size() != 1) {
    std::cerr << "\033[1;31mERROR: Input Kmap X size is not 1\033[0m" << std::endl;
    return -1;
  }

  if(Kmap[0][0].size() != 1) {
    std::cerr << "\033[1;31mERROR: Input Kmap Y size is not 1\033[0m" << std::endl;
    return -1;
  }

  unsigned K = Kmap.size();
  unsigned C = Kmap[0].size();
  std::vector<std::vector<myType> > temp(K, std::vector<myType>(C, 0));

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      temp[k][c] = Kmap[k][c][0][0];

  Kmatrix = temp;

  return 0;
}

template <typename myType>
int tensor_lib::flattenFC_features(std::vector<std::vector<std::vector<myType> > >& Fmap, std::vector<myType>& Fvec)
{
  if(Fmap[0][0].size() != 1) {
    std::cerr << "\033[1;31mERROR: Input Fmap X size is not 1\033[0m" << std::endl;
    return -1;
  }

  if(Fmap[0].size() != 1) {
    std::cerr << "\033[1;31mERROR: Input Fmap Y size is not 1\033[0m" << std::endl;
    return -1;
  }

  unsigned C = Fmap.size();
  std::vector<myType> temp_vec(C, 0);

  for(unsigned c=0; c<C; c++)
    temp_vec[c] = Fmap[c][0][0];

  Fvec = temp_vec;
  return 0;
}

template <typename myType>
int tensor_lib::rollFC_features(std::vector<myType>& Fvec, std::vector<std::vector<std::vector<myType> > >& Fmap)
{
  unsigned C = Fvec.size();
  std::vector<std::vector<std::vector<myType> > > temp_vec(C, std::vector<std::vector<myType> >(1, std::vector<myType>(1, 0)));

  for(unsigned c=0; c<C; c++)
    temp_vec[c][0][0] = Fvec[c];

  Fmap = temp_vec;
  return 0;
}

#endif
