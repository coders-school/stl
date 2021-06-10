#include "compression.hpp"

CompressedBitmap compressGrayscale(const Bitmap& bitmap) {
    CompressedBitmap compressed;
    compressed.reserve(width * height);
    for (const auto& line : bitmap) {
        uint8_t count{ 1 };
        uint8_t pixel{ line.front() };
        for (auto it = line.begin(); it != line.end(); ++it) {
            auto next_pixel_it{ std::next(it) };
            if (pixel != *next_pixel_it || next_pixel_it == line.end()) {
                compressed.push_back( {pixel, count} );
                pixel = *next_pixel_it;
                count = 1;
            } else {
                ++count;
            }
        }
    }
    compressed.shrink_to_fit();

    return compressed;
}
