#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
    std::vector<std::pair <uint8_t, uint8_t>> compressed;
	compressed.reserve(width * height);
	for (auto line: bitmap) {
		uint8_t counter = 1;
		for (auto it = line.begin(); it != line.end(); it++) {
			if (*it != *std::next(it) || it == line.end() - 1 ) {
				compressed.push_back(std::make_pair(*it, counter));
				counter = 1;
			}
			else {
				counter++;
			}
		}
	}
	return compressed;
}

void printVecPair(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
	for (const auto& el : vec) {
		std::cout << el.first << " | " << el.second << ' ';
	}
	std::cout << '\n';
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    size_t i=0;
    for(auto it : compressed){
        for(size_t j=0; j<it.second; ++j, ++i){
            decompressed[i/width][i%width]=it.first;
        }
    }
    return decompressed;
}
