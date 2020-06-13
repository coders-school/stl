#include <algorithm>
#include <array>
#include <utility>  // for std::pair<>
#include <vector>

// TODO: include
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
            bitmap.push_back({j, width / fraction});
        }
    }

    return bitmap;
}

TEST(compressionTests, ShouldCompressWholeLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            arr[i][j] = 0;

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height);
    expectBitmap(bitmap, 1);
}

TEST(compressionTests, ShouldCompressHalfLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 2; ++j)
            arr[i][j] = 0;
        for (int j = width / 2; j < width; ++j)
            arr[i][j] = 1;
    }

    auto bitmap = compressGrayscale(arr);
    expectBitmap(bitmap, 2);
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 4; ++j)
            arr[i][j] = 0;
        for (int j = width / 4; j < width / 2; ++j)
            arr[i][j] = 1;
        for (int j = width / 2; j < width / (4.0 / 3.0); ++j)
            arr[i][j] = 2;
        for (int j = width / (4.0 / 3.0); j < width; ++j)
            arr[i][j] = 3;
    }

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 4);
    expectBitmap(bitmap, 4);
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 8; ++j)
            arr[i][j] = 0;
        for (int j = width / 8; j < width / 4; ++j)
            arr[i][j] = 1;
        for (int j = width / 4; j < width / (8.0 / 3.0); ++j)
            arr[i][j] = 2;
        for (int j = width / (8.0 / 3.0); j < width / 2; ++j)
            arr[i][j] = 3;
        for (int j = width / 2; j < width / (8.0 / 5.0); ++j)
            arr[i][j] = 4;
        for (int j = width / (8.0 / 5.0); j < width / (4.0 / 3.0); ++j)
            arr[i][j] = 5;
        for (int j = width / (4.0 / 3.0); j < width / (8.0 / 7.0); ++j)
            arr[i][j] = 6;
        for (int j = width / (8.0 / 7.0); j < width; ++j)
            arr[i][j] = 7;
    }

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * 8);
    expectBitmap(bitmap, 8);
}

TEST(compressionTests, ShouldDecompressWholeLines) {
    constexpr size_t fraction = 1;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    constexpr size_t fraction = 2;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    constexpr size_t fraction = 4;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    constexpr size_t fraction = 8;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneSixteenLines) {
    constexpr size_t fraction = 16;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneThirtyTwoLines) {
    constexpr size_t fraction = 32;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

// TEST(compressionTests, ShouldDecompressOneSixtyFourLines) {
//     constexpr size_t fraction = 64;
//     auto bitmap = getBitmap(fraction);

//     auto map = decompressGrayscale(bitmap);
//     ASSERT_EQ(map.size(), height);
//     expectMap(map, fraction);
// }

TEST(compressionTests, ShouldCompressAndDecompress) {
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
