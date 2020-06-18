#include <algorithm>
#include <array>
#include <utility>  // for std::pair<>
#include <vector>

#include "gtest/gtest.h"
#include "compression.hpp"

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

std::array<std::array<uint8_t, width>, height> getMap(size_t fraction) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (size_t i = 0; i < height; ++i) {
        size_t j = 0;
        for (size_t f = 0; f < fraction; ++f) {
            for (size_t k = 0; k < width/fraction; ++k) {
                arr[i][j++] = f;
            }
        }
    }

    return arr;
}

void testCompressedBitmap(size_t fraction) {
    auto arr = getMap(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

void testDecompressedMap(size_t fraction) {
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        size_t j = 0;
        for (size_t f = 0; f < fraction; ++f) {
            for (size_t k = 0; k < width/fraction; ++k) {
                EXPECT_EQ(row[j++], f);
            }
        }
    }
}

TEST(compressionTests, ShouldCompressWholeLines) {
    size_t fraction = 1;
    testCompressedBitmap(fraction);
}

TEST(compressionTests, ShouldCompressHalfLines) {
    std::array<std::array<uint8_t, width>, height> arr;
    size_t fraction = 2;
    if (width >= fraction) {
        testCompressedBitmap(fraction);   
    }
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    size_t fraction = 4;
    if (width >= fraction) {
        testCompressedBitmap(fraction);
    }
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    size_t fraction = 8;
    if (width >= fraction) {
        testCompressedBitmap(fraction);
    }
}

TEST(compressionTests, ShouldCompressOneSixteenthLines) {
    size_t fraction = 16;
    if (width >= fraction) {
        testCompressedBitmap(fraction);
    }
}

TEST(compressionTests, ShouldCompressOneThirtySecondLines) {
    size_t fraction = 32;
    if (width >= fraction) {
        testCompressedBitmap(fraction);
    }
}

TEST(compressionTests, ShouldCompressOneSixtyFourthLines) {
    size_t fraction = 64;
    if (width >= fraction) {
        testCompressedBitmap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressWholeLines) {
    constexpr size_t fraction = 1;
    testDecompressedMap(fraction);
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    constexpr size_t fraction = 2;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    constexpr size_t fraction = 4;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    constexpr size_t fraction = 8;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneSixteenthLines) {
    constexpr size_t fraction = 16;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneThirtySecondLines) {
    constexpr size_t fraction = 32;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneSixtyFourthLines) {
    constexpr size_t fraction = 64;
    if (width >= fraction) {
        testDecompressedMap(fraction);
    }
}

TEST(compressionTests, ShouldCompressAndDecompress) {
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
