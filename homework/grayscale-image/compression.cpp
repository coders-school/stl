#include "compression.hpp"

#include <algorithm>
#include <iostream>

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

void printMap(const Decompressed& map) {
    for (const auto& row : map) {
        for (const auto& value : row) {
            std::cout << value;
        }
        std::cout << '\n';
    }
}

void printMap(const Compressed& map) {
    size_t colCount = 0;
    
    for (const auto& [value, number] : map) {
        std::cout << std::string(number, value);
        colCount += number;
        if (colCount == width) {
            colCount = 0;
            std::cout << "\n";
        }
    }
}
