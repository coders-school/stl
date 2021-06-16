#include <iostream>   // poprawic includy
#include "compression.hpp"

// const int imageWidth = 240;
// const int imageHeight = 160;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
	
	std::vector<std::pair<uint8_t, uint8_t>> resultVector;
	// resultVector.reserve(imageHeight * imageWidth); // bez sensu
	
	std::pair<uint8_t, uint8_t> tempPair{image.at(0).at(0), 0};   // druga wartosc 1 or 0 ?
	
	for (size_t i = 0; i < height; ++i) {  // uwaga na width height
		for (size_t j = 0; j < width; ++j) {
			if (image.at(i).at(j) == tempPair.first) {  // pierwsza wartosc
				tempPair.second += 1;
                // std::cout << " " << i << "- " << (int)tempPair.second << "  ";
			} else {
				resultVector.push_back(tempPair);
				tempPair.first = image.at(i).at(j); // first: nowa wartosc
				tempPair.second = 1;			// second 1 
			}
			
		}
	    resultVector.push_back(tempPair);
        tempPair.first = image.at(i).at(0);
		tempPair.second = 0;
	}
	
	return resultVector;
	
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImage) {
	 
	std::array<std::array<uint8_t, width>, height> image;
	
	auto compressedImageIt = compressedImage.begin();   // zmienic na interator
    // ++compressedImageIt;
	// std::pair<uint8_t, uint8_t> tempPair = compressedImage.front();
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

	// ::::::: DZIALA ::::::::::wersyjka ble ble ble ble
	// for (size_t i = 0; i < height; ++i) {
	// 	for (size_t j = 0; j < width; ++j) {
	// 		if (tempPair.second > 0) {
	// 			--tempPair.second;
	// 		} else {
	// 			tempPair = *compressedImageIt;
	// 			++compressedImageIt;
	// 			--tempPair.second;
	// 		}
	// 		image.at(i).at(j) = tempPair.first;
	// 	}
	// 	tempPair = *compressedImageIt;
	// 	++compressedImageIt;
	// }
	// ::::::::: DZIALA ::::::::::::::::::
	
	return image;
}

void printMap(std::array<std::array<uint8_t, 32>, 32> map) {
    // for (auto rowElement : map) {
    //     for (auto columnElement : rowElement) {
    //         std::cout << columnElement;
    //     }
    //     std::cout << '\n';
    // }

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            std::cout << static_cast<char>(map[i][j]);
        }
        std::cout << '\n';
    }


}