#include "compression.hpp"

// input: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2}, {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}
// ```
// output: {{0 0 0 1 1 2 3 0 0 0},
//         {0 0 4 4 4 1 1 1 1 1},
//         {2 2 2 2 2 1 2 2 2 2}}

// Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
//     Bitmap output{};

//     std::transform(compressed.cbegin(), compressed.cend(), output.begin(), [counter{0}, nextPair{0}](const auto& pair) mutable {
//         if (counter < pair[nextPair].second) {
//             counter++;
//         } else {
//         }
//     });

//     return output;
// }

// CompressedBitmap compressGrayscale(const Bitmap& decompressed) {
//     CompressedBitmap output;
    
//     std::transform(begin(decompressed), end(decompressed), output,[](auto row) {

        // std::transform(
        //     row.cbegin(), row.cend(), std::back_inserter(row), [counter{0}, lastEl = row[0]](const auto& item) mutable {
        //         if (lastEl == item) {
        //             counter++;
        //             return std::make_pair(0,0);
        //         } else {
        //             auto resVal = counter;
        //             counter = 0;
        //             auto resEl = lastEl;
        //             lastEl = item;
        //             return std::make_pair(resEl, resVal);
        //         }
        //     });
            //std::array<std::pair>
//             return row;
//     });

//         return output;
// }

char grayscaleToAscii(uint8_t grayscale) {
        static constexpr std::array<char, 10> asciiChars{
            '.', ':', '-', '=', '+', '*', '#', '%', '@'};

        return asciiChars[grayscale * 10 / 256];
}

void printMap(const Bitmap& map) {
        std::for_each(map.cbegin(), map.cend(), [](const auto& row) {
            std::transform(row.cbegin(), row.cend(), std::ostream_iterator<char>{std::cout},
                           [](const auto grayscale) { return grayscaleToAscii(grayscale); });
            std::cout << '\n';
        });
}




// std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> arr) {
//     std::vector<std::pair<uint8_t, uint8_t>> resVec;
//     uint8_t numOfOcurrences;
//     uint8_t prevNum;
//     bool firstNum;
//     for (auto& it : arr) {
//         firstNum = true;
//         numOfOcurrences = 1;
//         for (auto& iter : it) {
//             if (firstNum) {
//                 prevNum = iter;
//                 firstNum = !firstNum;

//             } else if (prevNum == iter) {
//                 numOfOcurrences++;
//             } else if (prevNum != iter) {
//                 resVec.push_back({prevNum, numOfOcurrences});
//                 prevNum = iter;
//                 numOfOcurrences = 1;
//             }
//         }
//         resVec.push_back({prevNum, numOfOcurrences});
//     }
//     return resVec;
// }
//Transfrom zamiast 2 pętli
// int main() {
//         std::vector<std::string> vec{
//             "ZeRo", "ONe", "TwO", "ThREe", "FoUr", "FiVe"};
//         std::transform(begin(vec), end(vec), begin(vec), [](auto str) {
//             std::transform(begin(str), end(str), begin(str), [](auto c) {
//                 return std::tolower(c);
//             });
//             return str;
//         });
//         print(vec);
//         return 0;
// }