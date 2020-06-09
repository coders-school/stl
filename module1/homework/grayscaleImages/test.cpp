#include <algorithm>
#include <array>
#include <utility> // for std::pair<>
#include <vector>

#include "compression.hpp"
#include "gtest/gtest.h"

void expectBitmap(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap, size_t fraction)
{
    for (int j = 0; j < fraction; j++)
    {
        for (int i = j; i < height * fraction; i += fraction)
        {
            EXPECT_EQ(bitmap[i].first, j);
            EXPECT_EQ(bitmap[i].second, width / fraction);
        }
    }
}

std::vector<std::pair<uint8_t, uint8_t>> getBitmap(size_t fraction)
{
    std::vector<std::pair<uint8_t, uint8_t>> bitmap;
    bitmap.reserve(height * fraction);
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < fraction; ++j)
        {
            bitmap.push_back({j, width / fraction});
        }
    }

    return bitmap;
}

Bitmap buildBitmap(unsigned int fraction)
{
    Bitmap bmp;
    Line line;
    Line::iterator lineIter = std::begin(line);
    Bitmap::iterator bitmapIter = std::begin(bmp);

    for (int i = 0; i < fraction; i++)
    {
        lineIter = std::fill_n(lineIter, width / fraction, i);
    }

    bitmapIter = std::fill_n(std::begin(bmp), height, line);
    return bmp;
}

class Compression : public ::testing::TestWithParam<int>
{
};

TEST_P(Compression, ShouldCompressBitmap)
{
    auto bitmap = compressGrayscale(buildBitmap(GetParam()));
    ASSERT_EQ(bitmap.size(), height * GetParam());
    expectBitmap(bitmap, GetParam());
}

INSTANTIATE_TEST_SUITE_P(CompressionTest, Compression, ::testing::Values(1, 2, 4, 8, 16));

TEST(compressionTests, ShouldDecompressWholeLines)
{
    constexpr size_t fraction = 1;
    auto bitmap = getBitmap(fraction);

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(bitmap.size(), height);
    for (const auto& row : map)
    {
        for (const uint8_t color : row)
        {
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
    for (const auto& row : map)
    {
        for (size_t i = 0; i < row.size() / fraction; ++i)
        {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / fraction; i < row.size(); ++i)
        {
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
    for (const auto& row : map)
    {
        for (size_t i = 0; i < row.size() / fraction; ++i)
        {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / fraction; i < row.size() / fraction * 2; ++i)
        {
            EXPECT_EQ(row[i], 1);
        }
        for (size_t i = row.size() / fraction * 2; i < row.size() / (fraction / 3.0); ++i)
        {
            EXPECT_EQ(row[i], 2);
        }
        for (size_t i = row.size() / (fraction / 3.0); i < row.size(); ++i)
        {
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
    for (const auto& row : map)
    {
        for (size_t i = 0; i < row.size() / fraction; ++i)
        {
            EXPECT_EQ(row[i], 0);
        }
        for (size_t i = row.size() / (fraction / 1.0); i < row.size() / (fraction / 2.0); ++i)
        {
            EXPECT_EQ(row[i], 1);
        }
        for (size_t i = row.size() / (fraction / 2.0); i < row.size() / (fraction / 3.0); ++i)
        {
            EXPECT_EQ(row[i], 2);
        }
        for (size_t i = row.size() / (fraction / 3.0); i < row.size() / (fraction / 4.0); ++i)
        {
            EXPECT_EQ(row[i], 3);
        }
        for (size_t i = row.size() / (fraction / 4.0); i < row.size() / (fraction / 5.0); ++i)
        {
            EXPECT_EQ(row[i], 4);
        }
        for (size_t i = row.size() / (fraction / 5.0); i < row.size() / (fraction / 6.0); ++i)
        {
            EXPECT_EQ(row[i], 5);
        }
        for (size_t i = row.size() / (fraction / 6.0); i < row.size() / (fraction / 7.0); ++i)
        {
            EXPECT_EQ(row[i], 6);
        }
        for (size_t i = row.size() / (fraction / 7.0); i < row.size(); ++i)
        {
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
