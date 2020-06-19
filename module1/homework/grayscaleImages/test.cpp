#include <algorithm>
#include <array>
#include <utility>  // for std::pair<>
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

void fillArray(std::array<std::array<uint8_t, width>, height>& input_array, size_t fraction) {
    std::array<uint8_t, width> new_lines;
    std::array<uint8_t, width>::iterator it = std::begin(new_lines);
    for (int i = 0; i < fraction; ++i) {
        it = std::fill_n(it, width / fraction, i);
    }
    std::fill_n(std::begin(input_array), height, new_lines);
}

TEST(compressionTests, ShouldCompressWholeLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 1);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height);
    expectBitmap(bitmap, 1);
}

TEST(compressionTests, ShouldCompressHalfLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 2);
    auto bitmap = compressGrayscale(arr);
    expectBitmap(bitmap, 2);
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 4);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 4);
    expectBitmap(bitmap, 4);
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 8);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 8);
    expectBitmap(bitmap, 8);
}

TEST(compressionTests, ShouldCompressOneSixteenLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 16);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 16);
    expectBitmap(bitmap, 16);
}

TEST(compressionTests, ShouldCompressOneThirtytwoLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    fillArray(arr, 32);
    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 32);
    expectBitmap(bitmap, 32);
}

TEST(compressionTests, ShouldDecompressWholeLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 1;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(bitmap.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 2;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 4;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 8;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldDecompressOneSixteenLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 16;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldDecompressOneThirtytwoLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    constexpr size_t fraction = 32;
    auto bitmap = getBitmap(fraction);
    fillArray(arr, fraction);
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    ASSERT_EQ(map, arr);
}

TEST(compressionTests, ShouldCompressAndDecompress) {
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
