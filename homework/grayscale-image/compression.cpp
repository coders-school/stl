#include "compression.hpp"
CompressedBitmap compressGrayscale(const Bitmap& decompressed) {
    CompressedBitmap output;

    output.reserve(width*height);
 for (const auto& line : decompressed) {
        for (auto color = line.begin(); color != line.end();) {
            auto nextColor = std::adjacent_find(color, line.end(), std::not_equal_to<int>{});
            if (nextColor != line.end()) {
                nextColor++;
            }
            output.emplace_back(*color, std::distance(color, nextColor));
            color = nextColor;
        }
    }
    output.shrink_to_fit();
    return output;
}   
// input: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2}, {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}
// ```
// output: {{0 0 0 1 1 2 3 0 0 0},
//         {0 0 4 4 4 1 1 1 1 1},
//         {2 2 2 2 2 1 2 2 2 2}}

Bitmap decompressGrayscale(const CompressedBitmap& compressed) {
    Bitmap output{};
    for_each(compressed.cbegin(), compressed.cend(), [count = 0, it = output.begin()](const auto& pair) mutable {
        std::fill_n(it->begin() + count, pair.second, pair.first);
        count += pair.second;
        if (count >= width) {
            ++it;
            count = 0;
        }
    });

    return output;
}

// CompressedBitmap compressGrayscale(const Bitmap& decompressed) {
//     CompressedBitmap output;

//     std::transform(begin(decompressed), end(decompressed), output,[](auto row) {

//         std::transform(
//             row.cbegin(), row.cend(), std::back_inserter(row), [counter{0}, lastEl = row[0]](const auto& item) mutable {
//                 if (lastEl == item) {
//                     counter++;
//                     return std::make_pair(0,0);
//                 } else {
//                     auto resVal = counter;
//                     counter = 0;
//                     auto resEl = lastEl;
//                     lastEl = item;
//                     return std::make_pair(resEl, resVal);
//                 }
//             });
//             std::array<std::pair>
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
