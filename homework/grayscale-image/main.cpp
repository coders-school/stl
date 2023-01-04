#include "compression.hpp"

int main() {
    auto ninja = generateNinja();
    printMap(ninja);
    auto compressed = compressGrayscale(ninja);
    auto decompressed = decompressGrayscale(compressed);
    // printMap(decompressed);

    return 0;
}
