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

std::array<std::array<uint8_t, width>, height> createArray(size_t fraction) {
    std::array<std::array<uint8_t, width>, height> arr;
    for (int i = 0; i < height; ++i) {
        arr[i] = std::array<uint8_t, width>{};
        for (int fragment = 0; fragment < fraction; ++fragment) {
            int from = (width * fragment) / fraction;
            int to = (width * (fragment + 1)) / fraction;
            for (int j = from; j < to; ++j) {
                arr[i][j] = fragment;
            }
        }
    }
    return arr;
}

void testDecompresion(const std::array<uint8_t, width>& line, size_t fraction) {
    for (int i = 0; i < fraction; ++i) {
        int from = line.size() * i / fraction;
        int to = line.size() * (i + 1) / fraction;
        for (size_t part = from; part < to; ++part) {
            EXPECT_EQ(line[part], i);
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
    constexpr int fraction = 2;
    auto arr = createArray(fraction);

    auto bitmap = compressGrayscale(arr);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressQuaterLines) {
    constexpr int fraction = 4;
    auto arr = createArray(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneEighthLines) {
    constexpr int fraction = 8;
    auto arr = createArray(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneSixteenLines) {
    constexpr int fraction = 16;
    auto arr = createArray(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneThirtyTwoLines) {
    constexpr int fraction = 32;
    auto arr = createArray(fraction);

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height * fraction);
    expectBitmap(bitmap, fraction);
}

TEST(compressionTests, ShouldCompressOneSixtyFourLines) {
    constexpr int fraction = 64;
    
    if constexpr (fraction > width) {
        GTEST_SKIP_("Test Redundant");
    }

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
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressHalfLines) {
    constexpr size_t fraction = 2;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressQuaterLines) {
    constexpr size_t fraction = 4;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneEighthLines) {
    constexpr size_t fraction = 8;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneSixteenLines) {
    constexpr size_t fraction = 16;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneThirtyTwoLines) {
    constexpr size_t fraction = 32;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
    }
}

TEST(compressionTests, ShouldDecompressOneSixtyFourLines) {
    constexpr size_t fraction = 64;

    if constexpr (fraction > width) {
        GTEST_SKIP_("Test Redundant");
    }

    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        testDecompresion(row, fraction);
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
