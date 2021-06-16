#include <iostream>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
	
	std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
	std::pair<uint8_t, uint8_t> tempPair{image.at(0).at(0), 0};
	
	for (size_t i = 0; i < height; ++i) { 
		for (size_t j = 0; j < width; ++j) {
			if (image.at(i).at(j) == tempPair.first) {  
				tempPair.second += 1;
			} else {
				compressedImage.push_back(tempPair);
				tempPair.first = image.at(i).at(j);
				tempPair.second = 1;
			}
		}
	    compressedImage.push_back(tempPair);
        tempPair.first = image.at(i).at(0);
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

void printMap(std::array<std::array<uint8_t, width>, height> map) {
    for (auto rowElement : map) {
        for (auto columnElement : rowElement) {
            std::cout << columnElement;
        }
        std::cout << '\n';
    }
}