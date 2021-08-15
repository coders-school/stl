#include "compression.hpp"
#include <algorithm>
#include <functional>
#include <numeric>

std::vector<uint8_t> compress(std::vector<uint8_t> vec1d, std::vector<uint8_t> vecunique) {
    std::vector<uint8_t> v3;

    auto f = [vec1d](int x) {
        auto i = std::find(vec1d.begin(), vec1d.end(), x);
        int index = std::distance(vec1d.begin(), i);
        return index;
    };
    std::transform(vecunique.begin(), vecunique.end(), std::back_inserter(v3), f);
    v3.push_back(v3.size());

    adjacent_difference(begin(v3), end(v3), begin(v3));
    v3.erase(v3.begin());

    return v3;
}

pairUint mergeVector(std::vector<uint8_t> v1, std::vector<uint8_t> v2) {
    pairUint vectorPair;
    auto f = [](uint8_t x, uint8_t y) {
        return std::make_pair(x, y);
    };

    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(vectorPair), f);
    return vectorPair;
}

pairUint compressGrayscale(board2d array2D) {
    int vectorsize = width * height;

    pairUint vecFinal;
    if ((width == 0) || (height == 0)) {
        return vecFinal;
    } else {
        std::vector<uint8_t> vec1D(vectorsize);
        std::vector<uint8_t> vecUnique(vectorsize);
        std::vector<uint8_t> vecCompres;

        std::copy(array2D[0].begin(), array2D[height - 1].end(), vec1D.begin());
        auto re = std::unique_copy(vec1D.begin(), vec1D.end(), vecUnique.begin());
        vecUnique.erase(re, vecUnique.end());
        vecCompres = compress(vec1D, vecUnique);
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
