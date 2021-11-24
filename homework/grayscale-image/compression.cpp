
#include "compression.hpp"

#include <algorithm>

//compressedGrayscaleImage - vector

compressedGrayscaleImage compressGrayscale(const grayscaleImage& arr) {
 
    compressedGrayscaleImage compressed;
    compressed.reserve(height * width);

  for (auto& row : arr) {
        for (auto it = std::next(row.begin()); it != row.end(); ++it) {
            auto& value = *it;
            static unsigned int samePrevValueCount = 1;

            if (*std::prev(it) == value) {
                samePrevValueCount++;
            } else {
                compressed.push_back({*std::prev(it), samePrevValueCount});
                samePrevValueCount = 1;
            }

            if (it == std::prev(row.end())) {
                compressed.push_back({*std::prev(it), samePrevValueCount});
                samePrevValueCount = 1;
            }
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}

grayscaleImage decompressGrayscale(const compressedGrayscaleImage& decompressed) {

grayscaleImage newArr;   
size_t index = 0;
size_t value = 0; 
    for(const auto& it : decompressed)
    {
        for(size_t i = 0; i < it.second; i++){
        newArr.at(index).at(value) = it.first;
        value++;
    
            if(value == width){
                index++;
                value = 0;
            }
        }
    }
    return newArr;
}