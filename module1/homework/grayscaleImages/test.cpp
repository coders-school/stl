#include <algorithm>
#include <array>
#include <utility>
#include <vector>

#include "compression.hpp"
#include "gtest/gtest.h"

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

std::array<std::array<uint8_t, width>, height> createArray(size_t fraction) {
    std::array<std::array<uint8_t, width>, height> array;
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            array[i][j] = j / (width / fraction);
        }
    }

    return array;
}

void checkMap(std::array<std::array<uint8_t, width>, height> arr, size_t fraction) {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            EXPECT_EQ(arr[i][j], j / (width / fraction));
        }
    }
}

TEST(compressionTests, ShouldCompressWholeLines) {
    constexpr size_t fraction = 1;
    auto arr = createArray(fraction);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressHalfLines) {
    constexpr size_t fraction = 2;
    auto arr = createArray(fraction);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    constexpr size_t fraction = 4;
    auto arr = createArray(fraction);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    constexpr size_t fraction = 8;
    auto arr = createArray(fraction);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldDecompressWholeLines) {
    constexpr size_t fraction = 1;
    auto bitmap = getBitmap(fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(bitmap.size(), height);
    checkMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    constexpr size_t fraction = 2;
    auto bitmap = getBitmap(fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    checkMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    constexpr size_t fraction = 4;
    auto bitmap = getBitmap(fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    checkMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    constexpr size_t fraction = 8;
    auto bitmap = getBitmap(fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    checkMap(map, fraction);
}

TEST(compressionTests, ShouldCompressAndDecompress) {
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
