#include "compression.hpp"
#include <algorithm>
#include <utility>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
    std::vector<std::pair <uint8_t, uint8_t>> compressed;
	int rows = sizeof(bitmap) / sizeof(bitmap[0]);
	int cols = sizeof(bitmap[0]) / sizeof(bitmap[0][0]);
	uint8_t countNumber = 0;
	std::cout << rows << std::endl;
	std::cout << cols << std::endl;

	int counter = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols - 1; j++) {
			
			if (bitmap[i][j] != bitmap[i][j + 1]) {
				compressed.push_back(std::make_pair(bitmap[i][j], counter));
				counter = 1;
			}
			else {
				counter++;
			}
		}
	}
	return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    return decompressed;
}