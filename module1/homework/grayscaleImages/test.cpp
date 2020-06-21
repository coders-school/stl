#include <array>
#include <utility>  // for std::pair<>
#include <vector>

#include "compression.hpp"
#include "gtest/gtest.h"

void expectBitmap(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap, size_t fraction) {
    for (int j = 0; j < fraction; j++) {
        for (int i = j; i < height * fraction; i += fraction) {
            EXPECT_EQ(bitmap[i].first, j);
            EXPECT_EQ(bitmap[i].second, (width * (j + 1) / fraction) - (width * j / fraction));
        }
    }
}

void expectMap(const std::array<std::array<uint8_t, width>, height>& map,
               size_t fraction) {
    for (size_t k = 0; k < fraction; ++k) {
        for (int i = 0; i < height; ++i) {
            for (int j = k * width / fraction; j < (k + 1) * width / fraction; ++j) {
                EXPECT_EQ(map[i][j], k);
            }
        }
    }
}

std::vector<std::pair<uint8_t, uint8_t>> getBitmap(size_t fraction) {
    std::vector<std::pair<uint8_t, uint8_t>> bitmap;
    bitmap.reserve(height * fraction);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < fraction; ++j) {
            bitmap.push_back({j, (width * (j + 1) / fraction) - (width * j / fraction)});
        }
    }

    return bitmap;
}

std::array<std::array<uint8_t, width>, height> getMap(size_t fraction) {
    std::array<std::array<uint8_t, width>, height> map;
    for (size_t k = 0; k < fraction; ++k) {
        for (size_t i = 0; i < height; ++i) {
            for (size_t j = k * width / fraction; j < (k + 1) * width / fraction; ++j) {
                map[i][j] = k;
            }
        }
    }
    return map;
}

void adjustFraction(size_t& fraction) {
    while (fraction > width) {
        fraction /= 2;
    }
}

class compression : public ::testing::TestWithParam<size_t> {
};

TEST_P(compression, ShouldCompressLines) {
    size_t fraction = GetParam();

    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

class decompression : public ::testing::TestWithParam<size_t> {
};

TEST_P(decompression, ShouldDecompressLines) {
    size_t fraction = GetParam();
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

INSTANTIATE_TEST_CASE_P(
    compressionTests,
    compression,
    ::testing::Values(
        1,
        2,
        4,
        8,
        16,
        32,
        64));

INSTANTIATE_TEST_CASE_P(
    decompressionTests,
    decompression,
    ::testing::Values(
        1,
        2,
        4,
        8,
        16,
        32,
        64));
