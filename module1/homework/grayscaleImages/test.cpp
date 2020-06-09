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

class Compression : public ::testing::TestWithParam<int> { };

TEST_P(Compression, ShouldCompressBitmap)
{
    auto bitmap = compressGrayscale(buildBitmap(GetParam()));
    ASSERT_EQ(bitmap.size(), height * GetParam());
    expectBitmap(bitmap, GetParam());
}

TEST_P(Compression, ShouldDecompressBitmap)
{
    auto bitmap = getBitmap(GetParam());
    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    auto generatedMap = buildBitmap(GetParam());
    EXPECT_EQ(map, generatedMap);
}

INSTANTIATE_TEST_SUITE_P(CompressionTest, Compression, ::testing::Values(1, 2, 4, 8, 16));

TEST(compressionTests, ShouldCompressAndDecompress)
{
    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
