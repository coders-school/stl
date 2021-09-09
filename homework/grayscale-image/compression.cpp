#include "compression.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image) {
	std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
	compressedImage.reserve(width * height);
	for (auto verticalIter = image.cbegin(); verticalIter != image.cend(); verticalIter++) {
		std::vector<uint8_t> elements;
		elements.reserve(width);
		std::vector<uint8_t> amounts(width);
		std::fill(amounts.begin(), amounts.end(), 1);
		auto amountsIt = amounts.begin();
		std::unique_copy((*verticalIter).cbegin(),
				 		 (*verticalIter).cend(),
						 std::back_inserter(elements),
						 [&amountsIt](auto current, auto next) mutable {
							 if (current == next) {
								 (*amountsIt)++;
							 } else {
								 std::advance(amountsIt, 1);
							 }
						 return current == next;
						 });
		std::transform(elements.cbegin(),
					   elements.cend(),
					   amounts.cbegin(),
					   std::back_inserter(compressedImage),
					   [](auto first, auto second) -> std::pair<uint8_t, uint8_t> {
						   return {first, second};
					   });
	}
	compressedImage.shrink_to_fit();
	return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressedImage) {
	std::array<std::array<uint8_t, width>, height> image;
	auto imageRowIt = image.begin();
	auto imageElemIt = (*imageRowIt).begin();
	for (auto compressedImageIt = compressedImage.cbegin(); compressedImageIt != compressedImage.cend(); compressedImageIt++) {
		imageElemIt = std::fill_n(imageElemIt, (*compressedImageIt).second, (*compressedImageIt).first);
		if (imageElemIt == (*imageRowIt).end()) {
			imageRowIt++;
			imageElemIt = (*imageRowIt).begin();
		}
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