#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap)
{
	std::vector<std::pair<uint8_t, uint8_t>> compressed;
	compressed.reserve(height * width);
	uint8_t counter{ 1 };
	for (const auto& line : bitmap) {
		for (auto it = line.begin(); it != line.end(); ++it) {
			if (*it != *std::next(it) || it == line.end()-1) {
				compressed.emplace_back(*it, counter);
				counter = 1;
			}
			else
			{
				++counter;
			}
		}
	}
	compressed.shrink_to_fit();
	return compressed;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> bitmap)
{
	std::array<std::array<uint8_t, width>, height> decompressed;
	size_t i{ 0 };
	for (const auto& vec : bitmap) {
		for (size_t j = 0; j < vec.second; ++j) {
			decompressed[0][i] = vec.first;
			++i;
		}
	}
	return decompressed;
}
