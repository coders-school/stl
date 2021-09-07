#include "compression.hpp"
#include <array>
#include <forward_list>
#include <algorithm>
#include <iostream>

std::array<std::array<uint8_t, 32>, 32> generateNinja() {
    return {
        std::array<uint8_t, 32>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 29, 52, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 51, 29, 10, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 12, 6, 21, 43, 64, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 64, 47, 25, 8, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 33, 93, 61, 46, 57, 87, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 76, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 15, 53, 71, 79, 81, 127, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 87, 52, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 33, 75, 91, 107, 153, 162, 162, 142, 150, 162, 162, 162, 162, 162, 148, 145, 162, 89, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 33, 93, 61, 90, 156, 180, 185, 185, 61, 129, 185, 185, 185, 185, 185, 112, 93, 185, 100, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 87, 113, 0, 0, 13, 47, 43, 101, 178, 184, 185, 185, 163, 172, 185, 185, 185, 185, 185, 169, 166, 185, 100, 34, 0, 0, 0, 0, 118, 88, 0},
        {0, 85, 112, 72, 39, 0, 0, 35, 92, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 162, 163, 89, 34, 0, 0, 32, 57, 142, 107, 0},
        {0, 41, 64, 137, 80, 0, 0, 35, 44, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 55, 59, 66, 49, 34, 0, 0, 97, 158, 81, 54, 0},
        {0, 8, 21, 78, 105, 108, 0, 35, 44, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 55, 59, 66, 49, 34, 0, 121, 121, 107, 42, 25, 0},
        {0, 0, 4, 45, 93, 103, 42, 42, 44, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 55, 59, 66, 49, 61, 90, 130, 115, 66, 4, 0, 0},
        {0, 0, 0, 0, 44, 62, 77, 54, 44, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 55, 59, 66, 49, 95, 158, 76, 43, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 23, 60, 70, 67, 43, 50, 51, 51, 51, 51, 51, 51, 51, 52, 57, 62, 61, 44, 68, 72, 68, 29, 12, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 10, 41, 62, 64, 50, 47, 47, 47, 47, 47, 47, 47, 47, 47, 51, 54, 57, 61, 67, 61, 41, 8, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 49, 58, 58, 45, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 51, 77, 63, 47, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 18, 42, 49, 51, 51, 51, 54, 57, 57, 62, 66, 66, 66, 62, 42, 18, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 24, 35, 47, 46, 48, 51, 51, 52, 54, 54, 58, 61, 61, 56, 54, 57, 38, 23, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 44, 51, 44, 45, 51, 51, 51, 51, 51, 54, 57, 57, 48, 48, 66, 49, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 44, 51, 44, 45, 51, 51, 51, 51, 51, 51, 52, 57, 48, 48, 66, 49, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 44, 51, 44, 45, 51, 51, 51, 51, 51, 51, 52, 57, 48, 48, 66, 49, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 44, 51, 44, 45, 51, 51, 51, 51, 51, 51, 52, 57, 48, 47, 64, 48, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 44, 51, 44, 45, 51, 51, 51, 51, 51, 51, 52, 57, 48, 46, 57, 46, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 35, 43, 44, 42, 60, 85, 85, 85, 85, 85, 85, 85, 86, 60, 43, 46, 43, 34, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 28, 34, 34, 41, 59, 82, 92, 88, 82, 82, 82, 83, 85, 60, 40, 34, 34, 27, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 45, 51, 89, 77, 51, 51, 51, 53, 66, 51, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 45, 51, 89, 77, 51, 51, 54, 57, 66, 51, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 45, 51, 76, 67, 51, 51, 54, 58, 66, 51, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 45, 51, 51, 51, 51, 51, 54, 58, 66, 51, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 45, 51, 51, 47, 43, 43, 51, 58, 66, 51, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 44, 47, 47, 40, 29, 29, 41, 51, 56, 47, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 41, 41, 41, 28, 0, 0, 29, 41, 41, 41, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
}

int main() {
    // auto ninja = generateNinja();
    // // printMap(ninja);
    // auto compressed = compressGrayscale(ninja);
    // auto decompressed = decompressGrayscale(compressed);
    // // printMap(decompressed);

    // auto vecIt = vec.begin();
    // for (auto arrIt = arr.cbegin(); arrIt != arr.cend();) {
    //     tempPair.first = *arrIt;
    //     tempPair.second = std::count(arrIt, arr.cend(), *arrIt);
    //     vec.push_back(tempPair);
    //     std::advance(arrIt, tempPair.second);
    // }

    ///zleeeee
    // auto arrIt = arr.begin();
    // // std::transform(arr.begin(), arr.end(), std::back_inserter(vec), [arrIt, arr](auto first) mutable {
    // std::transform(arr.begin(), arr.end(), std::back_inserter(vec), [arrIt, arr](auto element) mutable {
    //                                                                 std::pair<int, int> tempPair;
    //                                                                 tempPair.first = element;
    //                                                                 std::cout << element << ' ';
    //                                                                 // tempPair.second = std::count(arrIt, arr.end(), element;
    //                                                                 // std::advance(arrIt, tempPair.second);
    //                                                                 return tempPair;
    //                                                            }
    // );

    std::array<int, 10> arr = {1, 1, 1, 4, 5, 5, 2, 8, 9, 9};
    
    std::vector<int> tempVec1;
    std::vector<int> tempVec2(arr.size());
    // std::pair<int, int> tempPair;
    // tempVec2.push_back(1);
    // tempVec2.push_back(1);

    std::fill(tempVec2.begin(), tempVec2.end(), 1);
    auto vec2It = tempVec2.begin();
    std::unique_copy(arr.begin(), arr.end(), std::back_inserter(tempVec1), [&vec2It](int num1, int num2) mutable {
        if (num1 == num2) {
            std::cout << "@ ";
            std::cout << *vec2It << "  ";
            (*vec2It)++;
            // vec2It++;
            // std::advance(vec2It, 1);
        } else {
            std::cout << "% ";
            // tempVec2.push_back(1);
            // tempVec2.size();
            std::advance(vec2It, 1);
            // auto bckIt = std::back_inserter(tempVec2);
            // *bckIt = 1;
        }
        return num1 == num2;
    });
    // std::cout << "\nkokoko";
    std::vector<std::pair<int, int>> vec(tempVec1.size());
    // std::transform(tempVec1.begin(), tempVec1.end(), tempVec2.begin(), vec.begin(), [](auto first, auto second){std::pair<int, int> {first, second}});
    std::transform(tempVec1.begin(), tempVec1.end(), tempVec2.begin(), vec.begin(), [](auto first, auto second){std::pair<int, int> tempPair{first, second}; return tempPair;});

    


    // std::copy_if(arr.begin(),
    //              arr.end(),
    //              std::back_inserter(vec),
    //              [](){}
    //             );

    std::cout << '\n';
    for (auto& el : tempVec1) {
        std::cout << el << '_';
    }
    std::cout << "\nsize: " << tempVec2.size() << '\n';
    for (auto& el : tempVec2) {
        std::cout << el << '-';
    }

    std::cout << '\n';
    for (auto& el : vec) {
        std::cout << el.first << " : " << el.second << '\n';
    }
    


    return 0;
}
