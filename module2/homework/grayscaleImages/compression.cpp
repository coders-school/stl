#include "compression.hpp"

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <utility>

compressedImage compressGrayscale(decompressedImage& input) {
    compressedImage result;
    result.reserve(width * height);

    std::for_each(begin(input), end(input), [&result](decompressedLine& line){
        compressedImage compressedLine = compressSingleLine(line);
        std::transform(begin(compressedLine), end(compressedLine), std::back_inserter(result), [](const auto& pair){
            return std::make_pair(pair.first, pair.second);
        });
    });

    result.shrink_to_fit();
    return result;
}

compressedImage compressSingleLine(decompressedLine& line) {
    compressedImage buffer;
    buffer.reserve(width);
    colourAndLength current = {line.front(), 0};

    std::for_each(begin(line), end(line), [&buffer, &current, &line](const uint8_t& pixel){
        if (pixel == current.first) {
            current.second++;
        }
        if (pixel != current.first || &pixel == &line.back()) {
            buffer.push_back(current);
            current = {pixel, 1};
        }
    });

    buffer.shrink_to_fit();
    return buffer;
}

decompressedImage decompressGrayscale(compressedImage& input) {
    decompressedImage result;

    auto it = std::begin(result.front());
    std::for_each(begin(input), end(input), [&it, &result](const colourAndLength & pair){
        it = std::fill_n(it, pair.second, pair.first);
    });

    return result;
}
