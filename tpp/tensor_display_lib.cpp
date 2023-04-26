#ifndef _TENSOR_DISPLAY_LIB_TPP_
#define _TENSOR_DISPLAY_LIB_TPP_

template <typename T>
void tensor_lib::print(std::vector<T> tensor)
{
  const unsigned Stride = tensor.size();
  for(unsigned pos=0; pos<Stride; pos++) {
    const auto value = (std::is_same<T, char>::value)? static_cast<unsigned>(tensor[pos]) : tensor[pos];
    std::cout << " " << value << std::flush;
  }
  std::cout << std::endl;
}

template <typename T>
void tensor_lib::print(std::vector<std::vector<T> > tensor)
{
  const unsigned lineStride = tensor.size();
  for(unsigned line=0; line<lineStride; line++)
    print(tensor[line]);
}

template <typename T>
void tensor_lib::print(std::vector<std::vector<std::vector<T> > > tensor)
{
  const unsigned surfaceStride = tensor.size();
  std::cout << "[" << std::endl;
  for(unsigned plane=0; plane<surfaceStride; plane++)
    print(tensor[plane]);
  std::cout << "]" << std::endl;
}

template <typename T>
void tensor_lib::print(std::vector<std::vector<std::vector<std::vector<T> > > > tensor)
{
  const unsigned cubeStride = tensor.size();
  for(unsigned cube=0; cube<cubeStride; cube++) {
    print(tensor[cube]);
    if(cube<(cubeStride-1))
      std::cout << "---------------" << std::endl;
  }
}

#endif
