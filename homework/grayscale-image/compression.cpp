#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
	std::vector<std::pair<uint8_t, uint8_t>> compressedImage;

	// std::pair<uint8_t, uint8_t> tempPair{image.front().front(), 0};

	for (auto verticalIter = image.cbegin(); verticalIter != image.cend(); verticalIter++) {
		std::array<uint8_t, width> imageRow = *verticalIter;
		std::vector<uint8_t> elements;
		std::vector<uint8_t> amounts(width);
		std::fill(amounts.begin(), amounts.end(), 1);
		auto amountsIt = amounts.begin();
		std::unique_copy(imageRow.cbegin(),
				 		 imageRow.cend(),
						 std::back_inserter(elements),
						 [&amountsIt](auto current, auto next) mutable {
							 std::cout << (int)current << "|";     // uuuuuuuuu
							 if (current == next) {
								 (*amountsIt)++;
							 } else {
								 std::advance(amountsIt, 1);
							 }
						 return current == next;
						 });
		std::cout << '\n';     /// uuuuuuuuuuuuuuuuuuu
		std::vector<std::pair<uint8_t, uint8_t>> compressedRow(elements.size());
		// std::cout << " comprEEEE size:  " << elements.size() << '\n';	
		// std::cout << "compr row size: " << compressedRow.size() << ", compr size:  " << compressedImage.size() << '\n';	
		std::transform(elements.cbegin(),
					   elements.cend(),
					   amounts.cbegin(),
					//    std::back_inserter(compressedRow),
					   std::back_inserter(compressedImage),
					   [](auto first, auto second) -> std::pair<uint8_t, uint8_t> {
						   return {first, second};
					   });
		// compressedImage.insert(compressedImage.end(), compressedRow.cbegin(), compressedRow.cend());
		std::cout << "compr row size: " << compressedRow.size() << ", compr size:  " << compressedImage.size() << '\n';	
	}

	// for (const auto& verticalElement : image) {
	// 	for (const auto& horizontalElement : verticalElement) {
	// 		if (horizontalElement == tempPair.first) {
	// 			++tempPair.second;
	// 		} else { 
	// 			compressedImage.push_back(tempPair);
	// 			tempPair.first = horizontalElement;
	// 			tempPair.second = 1;
	// 		}
	// 	}
	// 	compressedImage.push_back(tempPair);
	// 	tempPair.first = verticalElement.front();
	// 	tempPair.second = 0;
	// }
	return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImage) {
	std::array<std::array<uint8_t, width>, height> image;
	// auto compressedImageIt = compressedImage.begin();
	// std::pair<uint8_t, uint8_t> tempPair = *compressedImageIt++;
	
	// for (auto itVert = image.begin(); itVert != image.end(); ++itVert) {
	// 	for (auto itHoriz = (*itVert).begin(); itHoriz != (*itVert).end(); ++itHoriz) {
	// 		if (tempPair.second == 0) {
	// 			tempPair = *compressedImageIt++;
	// 		}
	// 		--tempPair.second;
    //         *itHoriz = tempPair.first;
	// 	}
	//     tempPair = *compressedImageIt++;
	// }
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