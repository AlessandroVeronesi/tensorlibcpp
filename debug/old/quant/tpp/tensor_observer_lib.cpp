#ifndef _TENSOR_QUANT_OBSERVER_LIB_TPP_
#define _TENSOR_QUANT_OBSERVER_LIB_TPP_

//// MinMaxObserver

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  const std::vector<T> & tensor,
  T& min,
  T& max
  )
{
  max = *std::max_element(std::begin(tensor), std::end(tensor));
  min = *std::min_element(std::begin(tensor), std::end(tensor));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  const std::vector<std::vector<T> > & tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned row=0; row<tensor.size(); row++)
    temp.push_back(*std::max_element(std::begin(tensor[row]), std::end(tensor[row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned row=0; row<tensor.size(); row++)
    temp.push_back(*std::min_element(std::begin(tensor[row]), std::end(tensor[row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  const std::vector<std::vector<std::vector<T> > > & tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned ch=0; ch<tensor.size(); ch++)
    for(unsigned row=0; row<tensor[0].size(); row++)
      temp.push_back(*std::max_element(std::begin(tensor[ch][row]), std::end(tensor[ch][row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned ch=0; ch<tensor.size(); ch++)
    for(unsigned row=0; row<tensor[0].size(); row++)
      temp.push_back(*std::min_element(std::begin(tensor[ch][row]), std::end(tensor[ch][row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}

template <typename T>
void tensor_lib::quantization::MaxMinObserver(
  const std::vector<std::vector<std::vector<std::vector<T> > > > & tensor,
  T& min,
  T& max
  )
{
  std::vector<T> temp;

  for(unsigned k=0; k<tensor.size(); k++)
    for(unsigned ch=0; ch<tensor[0].size(); ch++)
      for(unsigned row=0; row<tensor[0][0].size(); row++)
        temp.push_back(*std::max_element(std::begin(tensor[k][ch][row]), std::end(tensor[k][ch][row])));
  max = *std::max_element(std::begin(temp), std::end(temp));

  for(unsigned k=0; k<tensor.size(); k++)
    for(unsigned ch=0; ch<tensor[0].size(); ch++)
      for(unsigned row=0; row<tensor[0][0].size(); row++)
        temp.push_back(*std::min_element(std::begin(tensor[k][ch][row]), std::end(tensor[k][ch][row])));
  min = *std::min_element(std::begin(temp), std::end(temp));
}


#endif
