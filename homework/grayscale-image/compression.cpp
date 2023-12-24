#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>>
    compressGrayscale(const std::array<std::array<uint8_t, width>, height>& pixelArray) {
        std::vector<std::pair<uint8_t, uint8_t>> forCompresion;
        auto counter{1};
        for (auto i = pixelArray.begin(); i != pixelArray.end(); ++i) {
            for (auto j = i->begin(); j != i->end(); ++j) {
                auto it = std::next(j);
                if (*j == *it) {
                    counter++;
                    if (it == i->end()) {
                        forCompresion.push_back(std::make_pair(*j, counter - 1));
                        counter = 1;
                    }
                } else {
                    forCompresion.push_back(std::make_pair(*j, counter));
                    counter = 1;
                }
            }
            std::cout << std::endl;
        }
    return forCompresion;
    }

std::array<std::array<uint8_t, width>, height>
    decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& pixelVector) {
        std::array<std::array<uint8_t, width>, height> deCompresion;
        std::vector<uint8_t> temVec;
        for (auto const& element : pixelVector) {
            std::fill_n(std::back_inserter(temVec), element.second, element.first);
        }
        auto it = temVec.begin();
        for (auto i = 0; i != height; ++i) {
            for (auto j = 0; j != width; ++j) {
                deCompresion[i][j] = *it;
                it++;
            }
        }
        return deCompresion;
    }

void printMap(std::array<std::array<uint8_t, width>, height>& pixelPrint) {
    for (auto el : pixelPrint) {
        for (auto el2 : el) {
            std::cout << el2;
        }
    }
}
