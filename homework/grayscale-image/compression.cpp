#include "compression.hpp"

#include <algorithm>

Compressed compressGrayscale(const Decompressed& input) {
    Compressed result;

    auto compression = [&result](const auto& value) { 
        if (value == result.back().first) {
            ++(result.back().second);
            return;
        }
        result.emplace_back(value, 1);
    };
    auto processRows = [&result, compression](const auto& row) {
        result.emplace_back(row.front(), 0);
        std::for_each(row.begin(), row.end(), compression);
    };
    std::for_each(input.begin(), input.end(), processRows);
    return result;
}

Decompressed decompressGrayscale(const Compressed& input) {
    Decompressed result;
    auto position = result.begin()->begin();
    
    auto decompression = [&position](const auto& pair) {
        const auto& [value, number] = pair;
        std::fill_n(position, number, value);
        position += number;        
    };
    std::for_each(input.begin(), input.end(), decompression);
    return result;
}
