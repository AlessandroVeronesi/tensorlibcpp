#ifndef _TENSOR_GENERATE_LIB_TPP_
#define _TENSOR_GENERATE_LIB_TPP_

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<myType> & foo)
{
  static_assert(std::is_integral<myType>(), "randTensor: T must be integral to accept bitwidth");

  unsigned C = foo.size();

  for(unsigned c=0; c<C; c++)
    do {
      foo[c] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
    } while(!foo[c]);
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<myType> > & foo)
{
  static_assert(std::is_integral<myType>(), "randTensor: T must be integral to accept bitwidth");

  unsigned H = foo.size();
  unsigned W = foo[0].size();

  for(unsigned h=0; h<H; h++)
    for(unsigned w=0; w<W; w++) {
      do {
        foo[h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
      } while(!foo[h][w]);
    }
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<std::vector<myType> > >& foo)
{
  static_assert(std::is_integral<myType>(), "randTensor: T must be integral to accept bitwidth");

  unsigned C = foo.size();
  unsigned H = foo[0].size();
  unsigned W = foo[0][0].size();

  for(unsigned c=0; c<C; c++)
    for(unsigned h=0; h<H; h++)
      for(unsigned w=0; w<W; w++) {
        do {
          foo[c][h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
        } while(!foo[c][h][w]);
      }
}

template <typename myType, unsigned bitwidth>
void tensor_lib::randTensor(std::vector<std::vector<std::vector<std::vector<myType> > > >& foo)
{
  static_assert(std::is_integral<myType>(), "randTensor: T must be integral to accept bitwidth");

  unsigned K = foo.size();
  unsigned C = foo[0].size();
  unsigned H = foo[0][0].size();
  unsigned W = foo[0][0][0].size();

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++) {
          do {
            foo[k][c][h][w] = rand() % maxBitVal(bitwidth) - minNegBitVal(bitwidth);
          } while(!foo[k][c][h][w]);
        }
}

template <typename myType>
void tensor_lib::randTensor(
  std::vector<myType> & foo,
  const myType low_bound, const myType high_bound
  )
{
  //static_assert(std::is_floating_point<myType>(), "randTensor: T integral type needs bitwidth");
  //internal::uniform_distribution<myType> distr(low_bound, high_bound);

  unsigned C = foo.size();

  for(unsigned c=0; c<C; c++)
    do {
      //foo[c] = distr.rand();
      foo[c] = internal::uniform_rand(low_bound, high_bound);
    } while(!foo[c]);
}

template <typename myType>
void tensor_lib::randTensor(
  std::vector<std::vector<myType> > & foo,
  const myType low_bound, const myType high_bound
  )
{
//  static_assert(std::is_floating_point<myType>(), "randTensor: T integral type needs bitwidth");
//  internal::uniform_distribution<myType> distr(low_bound, high_bound);

  unsigned H = foo.size();
  unsigned W = foo[0].size();

  for(unsigned h=0; h<H; h++)
    for(unsigned w=0; w<W; w++) {
      do {
        //foo[h][w] = distr.rand();
        foo[h][w] = internal::uniform_rand(low_bound, high_bound);
      } while(!foo[h][w]);
    }
}

template <typename myType>
void tensor_lib::randTensor(
  std::vector<std::vector<std::vector<myType> > >& foo,
  const myType low_bound, const myType high_bound
  )
{
//  static_assert(std::is_floating_point<myType>(), "randTensor: T integral type needs bitwidth");
  //internal::uniform_distribution<myType> distr(low_bound, high_bound);


  unsigned C = foo.size();
  unsigned H = foo[0].size();
  unsigned W = foo[0][0].size();

  for(unsigned c=0; c<C; c++)
    for(unsigned h=0; h<H; h++)
      for(unsigned w=0; w<W; w++) {
        do {
          //foo[c][h][w] = distr.rand();
          foo[c][h][w] = internal::uniform_rand(low_bound, high_bound);
        } while(!foo[c][h][w]);
      }
}

template <typename myType>
void tensor_lib::randTensor(
  std::vector<std::vector<std::vector<std::vector<myType> > > >& foo,
  const myType low_bound, const myType high_bound
  )
{
  //internal::uniform_distribution<myType> distr(low_bound, high_bound);

  unsigned K = foo.size();
  unsigned C = foo[0].size();
  unsigned H = foo[0][0].size();
  unsigned W = foo[0][0][0].size();

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++) {
          do {
            //foo[k][c][h][w] = distr.rand();
            foo[k][c][h][w] = internal::uniform_rand(low_bound, high_bound);
          } while(!foo[k][c][h][w]);
        }
}

#endif
