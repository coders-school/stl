#include "compression.hpp"

#include <algorithm>
#include <iostream>

pairVector compressGrayscale(const twoDimensionalArray& inputMap) {
    pairVector outputVec;
    outputVec.reserve(width * height);

    std::all_of(inputMap.begin(), inputMap.end(),
                [&outputVec](auto mapRow) {
                    for (auto tempIt = mapRow.begin(); tempIt != mapRow.end(); ++tempIt) {
                        auto it = std::adjacent_find(tempIt, mapRow.end(), std::not_equal_to<int>{});
                        if (it == mapRow.end()) {
                            it--;
                        }
                        outputVec.emplace_back(std::make_pair(*it, (std::distance(tempIt, it) + 1)));
                        tempIt = it;
                    }

                    return true;
                });
    outputVec.shrink_to_fit();
    return outputVec;
}

twoDimensionalArray decompressGrayscale(const pairVector& inputVec) {
    twoDimensionalArray outputArr;
    auto arrIt = outputArr.begin()->begin();

    std::all_of(inputVec.begin(), inputVec.end(),
                [arrIt](const auto& pair) mutable {
                    arrIt = std::fill_n(arrIt, pair.second, pair.first);
                    return true;
                });
    return outputArr;
}

void printMap(const twoDimensionalArray& inputMap) {
    std::all_of(inputMap.begin(), inputMap.end(), [](auto mapRow) {
        std::all_of(mapRow.begin(), mapRow.end(), [](auto rowElement) {
            if (rowElement < 33)
                std::cout << " ";
            else
                std::cout << rowElement;
            return true;
        });
        std::cout << '\n';
        return true;
    });
}
