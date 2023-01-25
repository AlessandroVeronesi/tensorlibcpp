#ifndef _EW_ADD_CPP_
#define _EW_ADD_CPP_

template <typename T>
int tensor_lib::debug::ew_add(
  std::vector<std::vector<T> >& Amap,
  std::vector<std::vector<T> >& Bmap,
  std::vector<std::vector<T> >& Omap
  )
{
  unsigned BatchSize = Amap.size();
  unsigned C = Amap[0].size();

  //* ===== PARAMETERS CHECK ===== *//
  if(BatchSize != Bmap.size()) {
    std::cerr << "\033[1;31mERROR: Batch size not corresponding\033[0m" << std::endl;
    return -1;
  }

  if(C != Bmap[0].size()) {
    std::cerr << "\033[1;31mERROR: C size not corresponding\033[0m" << std::endl;
    return -1;
  }

  //* ===== BODY ===== *//
  Omap.clear();
  Omap.resize(BatchSize, std::vector<T>(C, 0));

  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++)
      Omap[batch_idx][c] = Amap[batch_idx][c] + Bmap[batch_idx][c];

  return 0;
}

template <typename T>
int tensor_lib::debug::ew_add(
  std::vector<std::vector<std::vector<std::vector<T> > > >& Amap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Bmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  )
{
  unsigned BatchSize = Amap.size();
  unsigned C = Amap[0].size();
  unsigned H = Amap[0][0].size();
  unsigned W = Amap[0][0][0].size();

  //* ===== PARAMETERS CHECK ===== *//
  if(BatchSize != Bmap.size()) {
    std::cerr << "\033[1;31mERROR: Batch size not corresponding\033[0m" << std::endl;
    return -1;
  }

  if(C != Bmap[0].size()) {
    std::cerr << "\033[1;31mERROR: C size not corresponding\033[0m" << std::endl;
    return -1;
  }

  if(H != Bmap[0][0].size()) {
    std::cerr << "\033[1;31mERROR: H size not corresponding\033[0m" << std::endl;
    return -1;
  }

  if(W != Bmap[0][0][0].size()) {
    std::cerr << "\033[1;31mERROR: W size not corresponding\033[0m" << std::endl;
    return -1;
  }

  //* ===== BODY ===== *//
  Omap.clear();
  Omap.resize(BatchSize, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::Vector<T> >(H, std::vector<T>(W, 0))));

  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++)
          Omap[batch_idx][c][h][w] = Amap[batch_idx][c][h][w] + Bmap[batch_idx][c][h][w];

  return 0;
}

#endif
