#include "compression.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>

CompressedImgPixelInserter&
CompressedImgPixelInserter::operator=(const Pixel pixel) {
    if (columnIdx_ == 0 or (pixel != img_.back().first)) {
        img_.emplace_back(std::make_pair(pixel, 1));
    } else {
        img_.back().second++;
    }

    columnIdx_++;
    if (columnIdx_ == width)
        columnIdx_ = 0;

    return *this;
}

DecompressedBitmapInserter&
DecompressedBitmapInserter::operator=(const CompressedPixel pixel) {
    std::fill(filler_, std::next(filler_, pixel.second), pixel.first);
    std::advance(filler_, pixel.second);
    return *this;
}

CompressedImg compressGrayscale(const PGMBitMap& bitMap) {
    CompressedImg compressedImg;
    compressedImg.reserve(height * width);
    std::copy(bitMap[0].begin(), bitMap[width - 1].end(), CompressedImgPixelInserter(compressedImg, 0));
    compressedImg.shrink_to_fit();
    return compressedImg;
}

PGMBitMap decompressGrayscale(const CompressedImg& compressedImg) {
    PGMBitMap decompressed;
    std::copy(compressedImg.begin(), compressedImg.end(), DecompressedBitmapInserter(decompressed[0].begin()));
    return decompressed;
}

void printMap(const PGMBitMap& img) {
    std::stringstream ss;
    for (const auto& row : img) {
        for (const Pixel pixel : row) {
            ss << std::setw(4) << std::setfill(' ') << std::to_string(pixel);
        }
        ss << '\n';
    }
    std::cout << ss.str();
}
void printCompressed(const CompressedImg& img) {
    std::cout << "Compressed: ";
    std::for_each(img.begin(), img.end(), [](const auto& pair) { std::cout << "{" << pair.first << " : " << (int)pair.second << '}'; });
    std::cout << '\n';
}
