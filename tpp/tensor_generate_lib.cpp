#ifndef _TENSOR_GENERATE_LIB_TPP_
#define _TENSOR_GENERATE_LIB_TPP_

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<myType> & foo)
{
  unsigned C = foo.size();

  for(unsigned c=0; c<C; c++)
    do {
//      foo[c] = rand() % 0xFFFF - 0x8000;
      foo[c] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
    } while(!foo[c]);
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<myType> > & foo)
{
  unsigned H = foo.size();
  unsigned W = foo[0].size();

  for(unsigned h=0; h<H; h++)
    for(unsigned w=0; w<W; w++) {
      do {
//        foo[h][w] = rand() % 0xFFFF - 0x8000;
        foo[h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
      } while(!foo[h][w]);
    }
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<std::vector<myType> > >& foo)
{
  unsigned C = foo.size();
  unsigned H = foo[0].size();
  unsigned W = foo[0][0].size();

  for(unsigned c=0; c<C; c++)
    for(unsigned h=0; h<H; h++)
      for(unsigned w=0; w<W; w++) {
        do {
//          foo[c][h][w] = rand() % 0xFFFF - 0x8000;
          foo[c][h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
        } while(!foo[c][h][w]);
      }
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<std::vector<std::vector<myType> > > >& foo)
{
  unsigned K = foo.size();
  unsigned C = foo[0].size();
  unsigned H = foo[0][0].size();
  unsigned W = foo[0][0][0].size();

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++) {
          do {
//            foo[k][c][h][w] = rand() % 0xFFFF - 0x8000;
            foo[k][c][h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
          } while(!foo[k][c][h][w]);
        }
}

#endif
