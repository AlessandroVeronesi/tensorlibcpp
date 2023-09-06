#ifndef _AVG_POOL_TPP_DEBUG_
#define _AVG_POOL_TPP_DEBUG_

template <typename T>
int tensor_lib::debug::avg_pool(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned KernelSize
  )
{
  unsigned BatchSize = InFmap.size();
  unsigned C = InFmap[0].size();
  unsigned H = InFmap[0][0].size();
  unsigned W = InFmap[0][0][0].size();

  //* ===== PARAMETERS CHECK ===== *//
  if(H != W) {
    std::cerr << "\033[1;31mERROR: H != W shapes are not supported\033[0m" << std::endl;
    return -1;
  }
  if(H % KernelSize) {
    std::cerr << "\033[1;31mERROR: Size mod KernelSize must be 0\033[0m" << std::endl;
    return -1;
  }

  //* ===== BODY ===== *//
  unsigned H_ = H / KernelSize;
  unsigned W_ = W / KernelSize;
  Omap.clear();

  for(unsigned batch_idx=0; batch_idx < BatchSize; batch_idx++) {
    std::vector<std::vector<std::vector<T> > > cube;
    for(unsigned c=0; c<C; c++) {
      std::vector<std::vector<T> > surface(H_, std::vector<T>(W_, 0));
      for(unsigned h=0; h<H_; h++)
        for(unsigned w=0; w<W_; w++)
          for(unsigned i=0; i<KernelSize; i++)
            for(unsigned j=0; j<KernelSize; j++) {

              if((i==0) && (j==0)) {
                surface[h][w] = InFmap[batch_idx][c][h*KernelSize + i][w*KernelSize + j] / (KernelSize*KernelSize);
              }
              else {
                surface[h][w] += InFmap[batch_idx][c][h*KernelSize + i][w*KernelSize + j] / (KernelSize*KernelSize);
              }
            }
      cube.push_back(surface);
    }
    Omap.push_back(cube);
  }

  return 0;
}

#endif
