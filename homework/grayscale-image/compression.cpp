#include "compression.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
    std::vector<std::pair <uint8_t, uint8_t>> compressed;
	compressed.reserve(width * height);
	for (auto line: bitmap) {
		uint8_t counter = 1;
		for (auto it = line.begin(); it != line.end(); it++) {
			if (it == line.end() - 1 || *it != *std::next(it)) {
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

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;
    return decompressed;
}