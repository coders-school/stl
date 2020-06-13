#include <algorithm>
#include <array>
#include <utility>  // for std::pair<>
#include <vector>

// TODO: include
#include "compression.hpp"
#include "gtest/gtest.h"

void expectBitmap(const CompressedBitmap& bitmap, size_t fraction){

    for (int j = 0; j < fraction; j++){

        for (int i = j; i < height * fraction; i += fraction){

            EXPECT_EQ(bitmap[i].first, j);
            EXPECT_EQ(bitmap[i].second, width / fraction);
        }
    }
}

CompressedBitmap getBitmap(size_t fraction){

    CompressedBitmap bitmap;
    bitmap.reserve(height * fraction);

    for (size_t i = 0; i < height; ++i){

        for (size_t j = 0; j < fraction; ++j){

            bitmap.push_back({j, width / fraction});
        }
    }

    return bitmap;
}

Bitmap buildBitmap(size_t fraction){

    Bitmap bmp;
    Line line;
    Line::iterator lineIt = line.begin();
    Bitmap::iterator bitmapIt = bmp.begin();

    for(int i = 0; i < fraction; i++){

        lineIt = std::fill_n(lineIt, width / fraction, i);
    }

    bitmapIt = std::fill_n(bmp.begin(), height, line);

    return bmp;
}

class Compression : public ::testing::TestWithParam<int> { };

TEST_P(Compression, ShouldCompressBitmap){

    const Bitmap bmp = buildBitmap(GetParam());
    auto bitmap = compressGrayscale(bmp);
    ASSERT_EQ(bitmap.size(), height * GetParam());
    expectBitmap(bitmap, GetParam());
}

TEST_P(Compression, ShouldDecompressBitmap){
    
    const auto bitmap = getBitmap(GetParam());

    auto map = decompressGrayscale(bitmap);
    ASSERT_EQ(map.size(), height);
    auto generatedMap = buildBitmap(GetParam());
    EXPECT_EQ(map, generatedMap);
}

INSTANTIATE_TEST_SUITE_P(CompressionTest, Compression, ::testing::Values(1, 2, 4, 8, 16));

TEST(compressionTests, ShouldCompressAndDecompress){

    constexpr size_t fraction = 16;
    auto input = getBitmap(fraction);
    auto map = decompressGrayscale(input);
    auto bitmap = compressGrayscale(map);
    ASSERT_TRUE(bitmap.size() == input.size());
    EXPECT_EQ(bitmap, input);
}
