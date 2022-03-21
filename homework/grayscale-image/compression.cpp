#include "compression.hpp"
#include <algorithm>

compressedType compressGrayscale(bitmapType& pgm) {
    compressedType output(width * height);
    uint8_t counter{0}, counterLine{0};
    auto iter = begin(pgm)->begin();
    std::transform(iter, (end(pgm) - 1)->end(), begin(output), [&](auto pixel) {
        if (counterLine == height) {
            counterLine = 0;
            counter = 0;
        }
        if (pixel != *std::prev(iter)) {
            counter = 1;
        } else {
            counter++;
        }
        counterLine++;
        iter++;
        return std::make_pair(pixel, counter);
    });
    auto it = begin(output);
    output.erase(std::remove_if(begin(output),
                end(output),
                [&](auto el) { 
                    it++; 
                    return el.first == (*it).first && el.second == (*it).second - 1; }),
                end(output));
    return output;
}
bitmapType decompressGrayscale(compressedType& compressedImage) {
    bitmapType output;
    auto it = begin(*begin(output));
    std::for_each(begin(compressedImage),end(compressedImage), [&](auto pair){it = std::fill_n(it, pair.second, pair.first);});
    return output;
}