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

TEST(compressionTests, ShouldCompressWholeLines) {
    size_t fraction = 1;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressHalfLines) {
    size_t fraction = 2;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    size_t fraction = 4;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    size_t fraction = 8;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneSixteenLines) {
    size_t fraction = 16;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneThirtyTwoLines) {
    size_t fraction = 32;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneSixtyFourLines) {
    size_t fraction = 64;
    adjustFraction(fraction);
    std::array<std::array<uint8_t, width>, height> arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldDecompressWholeLines) {
    size_t fraction = 1;
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    size_t fraction = 2;
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    size_t fraction = 4;
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    size_t fraction = 8;
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldDecompressOneSixteenLines) {
    size_t fraction = 16;
    adjustFraction(fraction);
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

TEST(compressionTests, ShouldDecompressOneSixtyFourLines) {
    size_t fraction = 64;
    adjustFraction(fraction);
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    expectMap(map, fraction);
}

TEST(compressionTests, ShouldCompressAndDecompress) {
    size_t fraction = 16;
    adjustFraction(fraction);
    auto input = getBitmap(fraction);

    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
