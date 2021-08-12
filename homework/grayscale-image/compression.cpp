#include "compression.hpp"

#include <algorithm>
#include <functional>

Compressed compressGrayscale(const Decompressed& input) {
    Compressed result;

    auto rowIterator = input.begin();
    const uint8_t* colIterator; // = rowIterator->begin();

    std::function<void()> compression;
    compression = [&]() { 
        if (*colIterator == result.back().first) {
            ++(result.back().second);
        }
        else {
            result.emplace_back(*colIterator, 1);
        }
        if (++colIterator != rowIterator->end()) {
            std::invoke(compression);
        }
    };
    std::function<void()> processRows;
    processRows = [&]() {
        result.emplace_back(rowIterator->front(), 0);

        colIterator = rowIterator->begin();
        std::invoke(compression);

        if (++rowIterator != input.end()) {
            std::invoke(processRows);
        }
    };
    std::invoke(processRows);

    return result;
}

Decompressed decompressGrayscale(const Compressed& input) {
    Decompressed result;
    std::function<void()> decompression;
    auto it = input.begin();
    auto position = result.begin()->begin();
    
    decompression = [&position, &decompression, &it, &input]() {
        const auto& [value, number] = *it;
        std::fill_n(position, number, value);
        position += number;        
        
        if (++it != input.end()) {
            std::invoke(decompression);
        }
    };
    std::invoke(decompression);
    return result;
}
