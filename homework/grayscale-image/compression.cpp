#include "compression.hpp"
#include <array>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arr) {
    std::vector<std::pair<uint8_t, uint8_t>> res;
    for (auto const row : arr) {
        std::pair<uint8_t, uint8_t> cell{0, 0};
        for (auto i = 0; i < row.size(); ++i) {
            if (i == 0) {
                cell.first == row[i];
                cell.second = 1;
                continue;
            }
            if (i == row.size() - 1) {
                if (cell.first != row[i]) {
                    res.push_back(cell);
                    cell.first = row[i];
                    cell.second = 1;
                    res.push_back(cell);
                } else {
                    cell.second++;
                    res.push_back(cell);
                }
                continue;
            }
            if (cell.first != row[i]) {
                res.push_back(cell);
                cell.first = row[i];
                cell.second = 1;
            } else {
                cell.second++;
            }
        }
    }
    return res;
}
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> arr) {
    std::array<std::array<uint8_t, width>, height> res;
    int count = 0, row = 0;
    for (auto const& item : arr) {
        for (size_t i = 0; i < item.second; ++i, ++count) {
            res[row][count] = item.first;
        }
        if (count == width) {
            count = 0;
            row++;
        }
    }
    return res;
}
void printMap(std::array<std::array<uint8_t, width>, height> arr) {
    for (auto const row : arr) {
        for (auto const col : row) {
            if (col <= ' ') {
                std::cout << " "
                          << " ";
            } else {
                std::cout << col << " ";
            }
        }
        std::cout << "\n";
    }
}