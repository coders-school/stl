#include "compression.hpp"
#include <iostream>


void print_line(const std::array<uint8_t, width>& v)
{
     for (size_t i = 0; i < std::size(v); ++i) {
           std::cout << unsigned(v.at(i)) << " ";
    }
    std::cout << std::endl;
}

std::vector<std::pair<uint8_t, uint8_t>> process_line(const std::array<uint8_t, width>& v)
{
    std::vector<std::pair<uint8_t, uint8_t>>  output;
    uint8_t current_value = v[0];
    uint8_t old_value = v[0];
    int cnt = 0;
    std::cout << " s " << std::endl;
    for (size_t i = 0; i < std::size(v); ++i) {
           current_value = v[i];
           std::cout << " c = " << unsigned(current_value) << "\t";
           std::cout << " i = " << i << std::endl;
           if(current_value == old_value)
           {
                ++cnt;
           }
           else
           {
                output.push_back({old_value, cnt});
                old_value = current_value;
                cnt = 0;
           }
    }

    if(output.empty() or cnt > 0)
    {
        output.push_back({old_value, ++cnt});
    }
    std::cout << output.size() << std::endl;
    return output;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> pp;

    for (size_t h = 0; h < height; ++h) {
        print_line(input[h]);
        process_line(input[h]);
    }


    return pp;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::array<std::array<uint8_t, width>, height> output{};
    return output;
}