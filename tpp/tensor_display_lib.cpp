#ifndef _TENSOR_DISPLAY_LIB_TPP_
#define _TENSOR_DISPLAY_LIB_TPP_

template <typename T>
inline void tensor_lib::print(std::vector<T> tensor)
{
  unsigned Stride = tensor.size();
  for(unsigned pos=0; pos<Stride; pos++)
    std::cout << " " << tensor[pos] << std::flush;
  std::cout << std::endl;
}

template <typename T>
inline void tensor_lib::print(std::vector<std::vector<T> > tensor)
{
  unsigned lineStride = tensor.size();
  for(unsigned line=0; line<lineStride; line++)
    print(tensor[line]);
}

template <typename T>
inline void tensor_lib::print(std::vector<std::vector<std::vector<T> > > tensor)
{
  unsigned surfaceStride = tensor.size();
  std::cout << "[" << std::endl;
  for(unsigned plane=0; plane<surfaceStride; plane++)
    print(tensor[plane]);
  std::cout << "]" << std::endl;
}

template <typename T>
inline void tensor_lib::print(std::vector<std::vector<std::vector<std::vector<T> > > > tensor)
{
  unsigned cubeStride = tensor.size();
  for(unsigned cube=0; cube<cubeStride; cube++) {
    print(tensor[cube]);
    if(cube<(cubeStride-1))
      std::cout << "---------------" << std::endl;
  }
}

#endif
