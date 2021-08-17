#include <array>
#include <forward_list>
#include "compression.hpp"


int main() {
    
pairUint vec;
board2d test ={};

vec=compressGrayscale(test);
decompressGrayscale(vec);
    
  return 0;
}
