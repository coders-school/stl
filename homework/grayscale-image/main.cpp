#include <array>
#include <forward_list>
#include <iostream>
#include "compression.hpp"

int main() {
      std::array<std::array<uint8_t, width>, height> tab1 = {

    };

    printMap(tab1);

    auto compressed = compressGrayscale(tab1);

    std::cout << compressed.size() << std::endl;
    for (auto x : compressed) {
        std::cout << "{" << int(x.first) << ',' << int(x.second) << "} ";
    }

    auto decompressed = decompressGrayscale(compressed);
    std::cout << std::endl;
    printMap(decompressed);

    return 0;
}
