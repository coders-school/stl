#include <algorithm>
#include <utility>

#include "compression.hpp"
#include "gtest/gtest.h"

const std::vector<size_t> fractions{1, 2, 4, 8, 16, 32, 64};

void expectBitmap(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap, size_t fraction) {
    for (int j = 0; j < fraction; j++) {
        for (int i = j; i < height * fraction; i += fraction) {
            EXPECT_EQ(bitmap[i].first, j);
            EXPECT_EQ(bitmap[i].second, width / fraction);
        }
    }
}

std::vector<std::pair<uint8_t, uint8_t>> getBitmap(size_t fraction) {
    std::vector<std::pair<uint8_t, uint8_t>> bitmap;
    bitmap.reserve(height * fraction);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < fraction; ++j) {
            bitmap.push_back({j, width / fraction});
        }
    }

    return bitmap;
}

std::array<std::array<uint8_t, width>, height> createTestBitmap(size_t fraction) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (auto& el : arr) {
        size_t position = 0;
        for (uint8_t i = 0; i < fraction; i++) {
            for (size_t j = 0; j < width / fraction; j++) {
                el[position] = i;
                position++;
            }
        }
    }

    return arr;
}

TEST(compressionTests, ShouldCompress) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (const auto& fraction : fractions) {
        if (fraction <= height && (width % fraction == 0)) {
            auto bitmap = compressGrayscale(createTestBitmap(fraction));
            ASSERT_EQ(bitmap.size(), height * fraction);
            expectBitmap(bitmap, fraction);
        }
    }
}

TEST(compressionTests, ShouldDecompress) {
    for (const auto& fraction : fractions) {
        if (fraction <= height && (width % fraction == 0)) {
            auto bitmap = getBitmap(fraction);
            auto map = decompressGrayscale(bitmap);
            ASSERT_EQ(bitmap.size(), height * fraction);
            for (const auto& row : map) {
                size_t position = 0;
                for (size_t i = 0; i < fraction; i++) {
                    for (size_t j = 0; j < width / fraction; j++) {
                        EXPECT_EQ(row[position], i);
                        position++;
                    }
                }
            }
        }
    }
}

TEST(compressionTests, ShouldCompressAndDecompress) {
    for (const auto& fraction : fractions) {
        if (fraction <= height && (width % fraction == 0)) {
            auto input = getBitmap(fraction);
            auto map = decompressGrayscale(input);
            auto bitmap = compressGrayscale(map);
            ASSERT_TRUE(bitmap.size() == input.size());
            EXPECT_EQ(bitmap, input);
        }
    }
}
