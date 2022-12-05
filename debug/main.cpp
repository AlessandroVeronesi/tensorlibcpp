
#include <iostream>
#include <random>

#include "tensor_lib.h"

int main(int argc, char* argv[])
{
  long unsigned maxval, minval;

  maxval = tensor_lib::maxBitVal(2);
  minval = tensor_lib::minNegBitVal(2);
  std::cout << "-I: 2-bits, max uvalue is: " << maxval << ", min ivalue is: " << minval << std::endl;

  maxval = tensor_lib::maxBitVal(8);
  minval = tensor_lib::minNegBitVal(8);
  std::cout << "-I: 8-bits, max uvalue is: 0x" << std::hex << maxval << ", min ivalue is: 0x" << std::hex << minval << std::endl;

  maxval = tensor_lib::maxBitVal(16);
  minval = tensor_lib::minNegBitVal(16);
  std::cout << "-I: 16-bits, max uvalue is: 0x" << std::hex << maxval << ", min ivalue is: 0x" << std::hex << minval << std::endl;

  std::vector<std::vector<char> > test(2, std::vector<char>(3, 0));

  tensor_lib::randTensor<char, 4>(test);

  for(unsigned i=0; i<test.size(); i++) {
    for(unsigned j=0; j<test[0].size(); j++)
      std::cout << " " << (int) test[i][j] << std::flush;
    std::cout << std::endl;
  }

  return 0;
}
