#include <iostream>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
	std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
	std::pair<uint8_t, uint8_t> tempPair{image.front().front(), 0};

	for (const auto& verticalElement : image) {
		for (const auto& horizontalElement : verticalElement) {
			if (horizontalElement == tempPair.first) {
				++tempPair.second;
			} else { 
				compressedImage.push_back(tempPair);
				tempPair.first = horizontalElement;
				tempPair.second = 1;
			}
		}
		compressedImage.push_back(tempPair);
		tempPair.first = verticalElement.front();
		tempPair.second = 0;
	}
	return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImage) {
	std::array<std::array<uint8_t, width>, height> image;
	auto compressedImageIt = compressedImage.begin();
	std::pair<uint8_t, uint8_t> tempPair = *compressedImageIt++;
	
	for (auto itVert = image.begin(); itVert != image.end(); ++itVert) {
		for (auto itHoriz = (*itVert).begin(); itHoriz != (*itVert).end(); ++itHoriz) {
			if (tempPair.second == 0) {
				tempPair = *compressedImageIt++;
			}
			--tempPair.second;
            *itHoriz = tempPair.first;
		}
	    tempPair = *compressedImageIt++;
	}
	return image;
}

void printMap(const std::array<std::array<uint8_t, width>, height>& map) {
    for (const auto& rowElement : map) {
        for (const auto& columnElement : rowElement) {
            std::cout << columnElement;
        }
        std::cout << '\n';
    }
}