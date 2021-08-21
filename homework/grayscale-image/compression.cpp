#include "compression.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed{};
    compressed.reserve(width * height);

    std::for_each(bitmap.begin(), bitmap.end(), [&](auto& array) {
		    					for ( auto it = array.begin(); it != array.end(); ) {
								auto new_value_ptr = std::find_if(it,array.end(), [&](const auto& value){
														return *it != value;
														});
								compressed.emplace_back(*it, std::distance(it, new_value_ptr));
								it = new_value_ptr;
							} 
							return;	
		    				});
    

    compressed.shrink_to_fit();
    return compressed;
}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap bitmap{};

    auto it = bitmap.begin();
    int count{0};
    for (const auto& [Val, N] : compressed) {
        std::fill_n(it->begin() + count, N, Val);
        count += N;
        if (count >= width) {
            ++it;
            count = 0;
        }
    }

    return bitmap;
}

uint8_t getGrayScale(uint8_t code) {
    static constexpr int scale{255};
    static constexpr std::array<uint8_t, 10> grayScaleChars{' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

    std::array<uint8_t, 10>::size_type index{index = code * grayScaleChars.size() / (scale + 1)};

    return grayScaleChars[index];
}

void printMap(const Bitmap& bitmap) {
    for (const auto& row : bitmap) {
        for (const auto chCode : row) {
            std::cout << getGrayScale(chCode);
        }
        std::cout << '\n';
    }
}
