#include "compression.hpp"

compressedGrayscaleImage compressGrayscale(const grayscaleImage& bitmap) {
    compressedGrayscaleImage compressed;
    compressed.reserve(width * height);
    for (const auto& line : bitmap) {
        uint8_t counter = 1;
        for (auto it = line.begin(); it != line.end(); it++) {
            if (it == line.end() - 1 || *it != *std::next(it)) {
                compressed.emplace_back(std::make_pair(*it, counter));
                counter = 1;               
            } else {
                counter++;               
            }
        }
    }
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& compressed) {
    grayscaleImage decompressed;
    size_t i = 0;
    for (auto it : compressed) {
        for (size_t j = 0; j < it.second; ++j, ++i) {
            decompressed[0][i] = it.first;
        }
    }
    return decompressed;
}
