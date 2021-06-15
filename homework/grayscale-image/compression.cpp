#include "compression.hpp"

image_compressed_t compressGrayscale(image_t& image) {
    image_compressed_t compressedImage;
  
    for (size_t y = 0u; y < image.size(); y++) {

        compressedImage.push_back( {image[y][0], 1u});

        for (size_t x = 0u; x < image[y].size(); x++) {

            // skip 1st element for each line
            if (x == 0 ) {
                continue;
            }

            auto color = image[y][x];
            auto lastColorFromVector = compressedImage.back().first;
            if (lastColorFromVector == color) {
                compressedImage.back().second++;
            }
            else {
                compressedImage.push_back({ image[y][x], 1u });
            } 
        }
    }

    return compressedImage;
}

image_t decompressGrayscale(image_compressed_t& imageCompressed) {
    image_t image;

    auto elementCount = 0u;
    for (auto element : imageCompressed) {
        auto count = element.second;
        auto color = element.first;

        for (size_t i = 0; i < count; i++) {
            auto x = elementCount % width;
            auto y = elementCount / width;
            image[y][x] = color;

            elementCount++;
        }
    }
    return image;
}