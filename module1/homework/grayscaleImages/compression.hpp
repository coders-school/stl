#pragma once

#include <array>
#include <iterator>
#include <utility>
#include <vector>

namespace {
typedef uint8_t Pixel;
typedef uint8_t WidthType;
typedef uint8_t HeightType;
constexpr WidthType width = 32;
constexpr HeightType height = 32;
typedef std::array<Pixel, width> PGMRow;
typedef std::array<PGMRow, height> PGMBitMap;
typedef std::pair<Pixel, WidthType> CompressedPixel;
typedef std::vector<CompressedPixel> CompressedImg;
}  // namespace

CompressedImg compressGrayscale(const PGMBitMap&);
PGMBitMap decompressGrayscale(const CompressedImg&);

void printMap(const PGMBitMap&);
void printCompressed(const CompressedImg& img);

struct CompressedImgPixelInserter : std::iterator<std::output_iterator_tag, Pixel, void, void, void> {
public:
    CompressedImgPixelInserter(CompressedImg& img, size_t startOffset)
        : img_(img),
          columnIdx_(startOffset){};
    explicit CompressedImgPixelInserter(CompressedImg& img)
        : CompressedImgPixelInserter(img, 0){};

    CompressedImgPixelInserter&
    operator=(const Pixel pixel);

    CompressedImgPixelInserter&
    operator++() {
        return *this;  // no point moving - we're almost back_inserter
    }
    CompressedImgPixelInserter&
    operator*() {
        return *this;
    }

private:
    CompressedImg& img_;
    size_t columnIdx_;
};

struct DecompressedBitmapInserter : std::iterator<std::output_iterator_tag, CompressedPixel, void, void, void> {
    explicit DecompressedBitmapInserter(PGMRow::iterator filler)
        : filler_(filler){};

    DecompressedBitmapInserter&
    operator=(const CompressedPixel);

    DecompressedBitmapInserter&
    operator++() {
        return *this;  // we don't move, we only insert
    }
    DecompressedBitmapInserter&
    operator*() {
        return *this;
    }

private:
    PGMRow::iterator filler_;
};
