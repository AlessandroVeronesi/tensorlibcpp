#ifndef _MAX_POOL_TPP_
#define _MAX_POOL_TPP_

template <typename T>
int tensor_lib::debug::max_pool(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& InFmap,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap,
  const unsigned KernelSizeW, const KernelStrideW,
  const unsigned KernelSizeH, const KernelStrideH
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
  if(H % KernelSizeH) {
    std::cerr << "\033[1;31mERROR: Size H mod KernelSize H must be 0\033[0m" << std::endl;
    return -1;
  }

  if(W % KernelSizeW) {
    std::cerr << "\033[1;31mERROR: Size W mod KernelSize W must be 0\033[0m" << std::endl;
    return -1;
  }

  //* ===== BODY ===== *//
  unsigned H_ = H / KernelSizeH;
  unsigned W_ = W / KernelSizeW;

  Omap.clear();

  for(unsigned batch_idx=0; batch_idx < BatchSize; batch_idx++) {
    std::vector<std::vector<std::vector<T> > > cube;
    for(unsigned c=0; c<C; c++) {
      std::vector<std::vector<T> > surface(H_, std::vector<T>(W_, 0));
      for(unsigned h=0; h<H_; h++)
        for(unsigned w=0; w<W_; w++)
          for(unsigned i=0; i<KernelSizeiH; i++)
            for(unsigned j=0; j<KernelSizeW; j++) {

              if((i==0) && (j==0)) {
                surface[h][w] = InFmap[batch_idx][c][h*KernelStrideH + i][w*KernelStrideW + j];
              }
              else {
                surface[h][w] = std::max(surface[h][w], InFmap[batch_idx][c][h*KernelStrideH + i][w*KernelStrideW + j]);
              }
            }
      cube.push_back(surface);
    }
    Omap.push_back(cube);
  }

  return 0;
}

#endif
