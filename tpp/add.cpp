#ifndef _ADD_CPP_
#define _ADD_CPP_

template <typename T>
int tensor_lib::debug::add(
  const std::vector<std::vector<T> >& Imap,
  const T scalar,
  std::vector<std::vector<T> >& Omap
  )
{
  unsigned BatchSize = Imap.size();
  unsigned C = Imap[0].size();

  //* ===== BODY ===== *//
  Omap.clear();
  Omap.resize(BatchSize, std::vector<T>(C, 0));

  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++)
      Omap[batch_idx][c] = Imap[batch_idx][c] + scalar;

  return 0;
}

template <typename T>
int tensor_lib::debug::add(
  const std::vector<std::vector<std::vector<std::vector<T> > > >& Imap,
  const T scalar,
  std::vector<std::vector<std::vector<std::vector<T> > > >& Omap
  )
{
  unsigned BatchSize = Imap.size();
  unsigned C = Imap[0].size();
  unsigned H = Imap[0][0].size();
  unsigned W = Imap[0][0][0].size();

  //* ===== BODY ===== *//
  Omap.clear();
  Omap.resize(BatchSize, std::vector<std::vector<std::vector<T> > >(C, std::vector<std::vector<T> >(H, std::vector<T>(W, 0))));

  for(unsigned batch_idx=0; batch_idx<BatchSize; batch_idx++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++)
          Omap[batch_idx][c][h][w] = Imap[batch_idx][c][h][w] + scalar;

  return 0;
}

#endif
