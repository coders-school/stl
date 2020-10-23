#include <algorithm>
#include <utility>

#include "compression.hpp"
#include "gtest/gtest.h"

void expectBitmap(const SqueezedMap& bitmap, size_t fraction)
{
    for (int j = 0; j < fraction; j++) {
        for (int i = j; i < height * fraction; i += fraction) {
            EXPECT_EQ(bitmap[i].first, j);
            EXPECT_EQ(bitmap[i].second, width / fraction);
        }
    }
}

SqueezedMap getBitmap(size_t fraction)
{
    SqueezedMap bitmap;
    bitmap.reserve(height * fraction);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < fraction; ++j) {
            bitmap.push_back({j, width / fraction});
        }
    }

    return bitmap;
}

TEST(compressionTests, ShouldCompressWholeLines)
{
    DiffusedMap arr;
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            arr[i][j] = 0;

    auto bitmap = compressGrayscale(arr);
    ASSERT_EQ(bitmap.size(), height);
    expectBitmap(bitmap, 1);
}

TEST(compressionTests, ShouldCompressHalfLines)
{
    DiffusedMap arr;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width / 2; ++j)
            arr[i][j] = 0;
        for (int j = width / 2; j < width; ++j)
            arr[i][j] = 1;
    }

    auto bitmap = compressGrayscale(arr);
    expectBitmap(bitmap, 2);
}

TEST(compressionTests, ShouldCompressQuaterLines)
{
    DiffusedMap arr;
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

TEST(compressionTests, ShouldCompressOneEighthLines)
{
    DiffusedMap arr;
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

TEST(compressionTests, ShouldDecompressWholeLines)
{
    constexpr size_t fraction = 1;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(bitmap.size(), height);
    for (const auto& row : map) {
        for (const uint8_t color : row) {
            EXPECT_EQ(color, 0);
        }
    }
}

TEST(compressionTests, ShouldDecompressHalfLines)
{
    constexpr size_t fraction = 2;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        for (size_t i = 0; i < row.size() / fraction; ++i) {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / fraction; i < row.size(); ++i) {
            EXPECT_EQ(row[i], 1);
        }
    }
}

TEST(compressionTests, ShouldDecompressQuaterLines)
{
    constexpr size_t fraction = 4;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        for (size_t i = 0; i < row.size() / fraction; ++i) {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / fraction; i < row.size() / fraction * 2; ++i) {
            EXPECT_EQ(row[i], 1);
        }
        for (size_t i = row.size() / fraction * 2; i < row.size() / (fraction / 3.0); ++i) {
            EXPECT_EQ(row[i], 2);
        }
        for (size_t i = row.size() / (fraction / 3.0); i < row.size(); ++i) {
            EXPECT_EQ(row[i], 3);
        }
    }
}

TEST(compressionTests, ShouldDecompressOneEighthLines)
{
    constexpr size_t fraction = 8;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    for (const auto& row : map) {
        for (size_t i = 0; i < row.size() / fraction; ++i) {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / (fraction / 1.0); i < row.size() / (fraction / 2.0); ++i) {
            EXPECT_EQ(row[i], 1);
        }
        for (size_t i = row.size() / (fraction / 2.0); i < row.size() / (fraction / 3.0); ++i) {
            EXPECT_EQ(row[i], 2);
        }
        for (size_t i = row.size() / (fraction / 3.0); i < row.size() / (fraction / 4.0); ++i) {
            EXPECT_EQ(row[i], 3);
        }
        for (size_t i = row.size() / (fraction / 4.0); i < row.size() / (fraction / 5.0); ++i) {
            EXPECT_EQ(row[i], 4);
        }
        for (size_t i = row.size() / (fraction / 5.0); i < row.size() / (fraction / 6.0); ++i) {
            EXPECT_EQ(row[i], 5);
        }
        for (size_t i = row.size() / (fraction / 6.0); i < row.size() / (fraction / 7.0); ++i) {
            EXPECT_EQ(row[i], 6);
        }
        for (size_t i = row.size() / (fraction / 7.0); i < row.size(); ++i) {
            EXPECT_EQ(row[i], 7);
        }
    }
}

TEST(compressionTests, ShouldCompressAndDecompress)
{
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
