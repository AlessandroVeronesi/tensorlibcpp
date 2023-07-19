#ifndef _TENSOR_COMPARE_LIB_TPP_
#define _TENSOR_COMPARE_LIB_TPP_

template <typename T>
bool tensor_lib::compareArray(const T* A, const T* B, const unsigned Size)
{
  for(unsigned i=0; i<Size; i++)
    if(A[i] != B[i])
      return false;

  return true;
}

template <typename T>
bool tensor_lib::compare2Darray(const T** A, const T** B, const unsigned SizeY, const unsigned SizeX)
{
  for(unsigned i=0; i<SizeY; i++)
    for(unsigned j=0; j<SizeX; j++)
      if(A[i][j] != B[i][j])
        return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<T> & A, const std::vector<T> & B)
{
  unsigned C = A.size();

  if(C != B.size()) return false;

  for(unsigned c=0; c<C; c++)
    if(A[c] != B[c])
      return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<T> >& A,const std::vector<std::vector<T> >& B)
{
  unsigned H = A.size();
  unsigned W = A[0].size();

  if(H != B.size()) return false;
  if(W != B[0].size()) return false;

  for(unsigned h=0; h<H; h++)
    for(unsigned w=0; w<W; w++)
      if(A[h][w] != B[h][w])
        return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<std::vector<T> > >& A,const std::vector<std::vector<std::vector<T> > >& B)
{
  unsigned C = A.size();
  unsigned H = A[0].size();
  unsigned W = A[0][0].size();

  if(C != B.size()) return false;
  if(H != B[0].size()) return false;
  if(W != B[0][0].size()) return false;

  for(unsigned c=0; c<C; c++)
    for(unsigned h=0; h<H; h++)
      for(unsigned w=0; w<W; w++)
        if(A[c][h][w] != B[c][h][w])
          return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<std::vector<std::vector<T> > > >& A,const std::vector<std::vector<std::vector<std::vector<T> > > >& B)
{
  unsigned K = A.size();
  unsigned C = A[0].size();
  unsigned H = A[0][0].size();
  unsigned W = A[0][0][0].size();

  if(K != B.size()) return false;
  if(C != B[0].size()) return false;
  if(H != B[0][0].size()) return false;
  if(W != B[0][0][0].size()) return false;

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++)
          if(A[k][c][h][w] != B[k][c][h][w])
            return false;

  return true;
}

/////////////////////////////////////
template <typename T>
bool tensor_lib::compareArray(const T* A, const T* B, const unsigned Size, const T t)
{
  for(unsigned i=0; i<Size; i++)
    if(std::abs((A[i] - B[i]) / B[i]) > t)
      return false;

  return true;
}

template <typename T>
bool tensor_lib::compare2Darray(const T** A, const T** B, const unsigned SizeY, const unsigned SizeX, const T t)
{
  for(unsigned i=0; i<SizeY; i++)
    for(unsigned j=0; j<SizeX; j++)
      if(std::abs((A[i][j] - B[i][j]) / B[i][j]) > t)
        return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<T> & A,const std::vector<T> & B,const T t)
{
  unsigned C = A.size();

  if(C != B.size()) return false;

  for(unsigned c=0; c<C; c++)
    if(std::abs((A[c] - B[c]) / B[c]) > t)
      return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<T> >& A,const std::vector<std::vector<T> >& B,const T t)
{
  unsigned H = A.size();
  unsigned W = A[0].size();

  if(H != B.size()) return false;
  if(W != B[0].size()) return false;

  for(unsigned h=0; h<H; h++)
    for(unsigned w=0; w<W; w++)
      if(std::abs((A[h][w] - B[h][w]) / B[h][w]) > t)
        return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<std::vector<T> > >& A,const std::vector<std::vector<std::vector<T> > >& B,const T t)
{
  unsigned C = A.size();
  unsigned H = A[0].size();
  unsigned W = A[0][0].size();

  if(C != B.size()) return false;
  if(H != B[0].size()) return false;
  if(W != B[0][0].size()) return false;

  for(unsigned c=0; c<C; c++)
    for(unsigned h=0; h<H; h++)
      for(unsigned w=0; w<W; w++)
        if(std::abs((A[c][h][w] - B[c][h][w]) / B[c][h][w]) > t)
          return false;

  return true;
}

template <typename T>
bool tensor_lib::compareTensors(const std::vector<std::vector<std::vector<std::vector<T> > > >& A,const std::vector<std::vector<std::vector<std::vector<T> > > >& B,const T t)
{
  unsigned K = A.size();
  unsigned C = A[0].size();
  unsigned H = A[0][0].size();
  unsigned W = A[0][0][0].size();

  if(K != B.size()) return false;
  if(C != B[0].size()) return false;
  if(H != B[0][0].size()) return false;
  if(W != B[0][0][0].size()) return false;

  for(unsigned k=0; k<K; k++)
    for(unsigned c=0; c<C; c++)
      for(unsigned h=0; h<H; h++)
        for(unsigned w=0; w<W; w++)
          if(std::abs((A[k][c][h][w] - B[k][c][h][w]) / B[k][c][h][w]) > t)
            return false;

  return true;
}

#endif
