#include "compression.hpp"
#include <algorithm>
#include <functional>

std::vector<uint8_t> compress(std::vector<uint8_t> v, const size_t& sizeUnique) {
    std::vector<int> v2(v.size());
    std::vector<uint8_t> v3;
    uint8_t old = v.at(0);
    int n = 0;
    int m = -1;
    int it = 1;
    int itEnd = width * height;
    auto f = [&](uint8_t x) {
        m = -1;
        if (old == x) {
            n++;
        } else {
            m = n;
            old = x;
            n = 1;
            it++;
            return m;
        }
        if (it == itEnd) {
            return n;
        }
        it++;

        return m;
    };

    std::transform(v.begin(), v.end(), v2.begin(), f);

    auto const is_even = [](int x) { return x > -1; };
    std::copy_if(v2.begin(), v2.end(), std::back_inserter(v3), is_even);
    if (v3.size() < sizeUnique) {
        v3.push_back(1);
    }

    return v3;
}

pairUint mergeVector(std::vector<uint8_t> v1, std::vector<uint8_t> v2) {
    pairUint returnPair;
    auto f = [](uint8_t x, uint8_t y) {
        return std::make_pair(x, y);
    };

    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(returnPair), f);
    return returnPair;
}

pairUint compressGrayscale(board2d array2D) {
    int s = width * height;

    pairUint vecFinal;
    if ((width == 0) || (height == 0)) {
        return vecFinal;
    } else {
        std::vector<uint8_t> vec1D(s);
        std::vector<uint8_t> vecUnique(s);
        std::vector<uint8_t> vecCompres;

        std::copy(array2D[0].begin(), array2D[height - 1].end(), vec1D.begin());
        auto re = std::unique_copy(vec1D.begin(), vec1D.end(), vecUnique.begin());
        vecUnique.erase(re, vecUnique.end());
        vecCompres = compress(vec1D, vecUnique.size());
        vecFinal = mergeVector(vecUnique, vecCompres);

        return vecFinal;
    }
}

board2d decompressGrayscale(pairUint vecPair) {
    board2d finalArray;
    std::vector<uint8_t> vec;

    for (auto x : vecPair) {
        std::fill_n(std::back_inserter(vec), x.second, x.first);
    }
    std::copy(vec.begin(), vec.end(), finalArray[0].begin());

    return finalArray;
}
