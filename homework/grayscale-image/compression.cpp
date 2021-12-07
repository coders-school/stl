#pragma once
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <utility>
#include <cstddef>

constexpr size_t height = 32;
constexpr size_t width = 32;

std::vector<std::pair<uint8_t,uint8_t>> compressGrayscale(const std::array<std::array<uint8_t,width>,height> & arrayTemp) {
    std::pair<uint8_t, uint8_t> p_test;
    std::vector<std::pair<uint8_t,uint8_t>> vec2;
        std::all_of(arrayTemp.begin(), arrayTemp.end(), [&vec2, &p_test](std::array<uint8_t, width> a){
            auto itBegin = a.begin();
            std::transform(a.begin(),a.end(),std::back_inserter(vec2), [&p_test, &itBegin, &a](const auto & x) {
                p_test.first = x;
                auto itEnd = std::find_if(itBegin, a.end(),[&p_test, &itBegin](const auto & num) {return num != p_test.first;});
                auto dist = std::distance(itBegin, itEnd);
                p_test.second = dist;
                itBegin = itEnd;
                return p_test;
            });
            vec2.erase(std::remove_if(vec2.begin(),vec2.end(),[](const std::pair<uint8_t, uint8_t> & pair){ return pair.second == 0;} ), vec2.end());
        return a.size() > 0;}
    );
    vec2.shrink_to_fit();
    return vec2;
}

std::array<std::array<uint8_t, width>,height> decompressGrayscale(const std::vector<std::pair<uint8_t,uint8_t>> & vectorTemp) {
    std::array<std::array<uint8_t, width>, height> a_t;
    std::vector<uint8_t> v_t;
    uint8_t row = 0;
    uint8_t column = 0;

    std::all_of(vectorTemp.begin(), vectorTemp.end(), [&](std::pair<uint8_t,uint8_t> p) mutable {
        std::fill_n(std::back_inserter(v_t), p.second, p.first);
        column += p.second;
        if (column == width) {
            std::copy(v_t.begin(), v_t.end(), a_t[row].begin());
            v_t.clear();
            row++;
            column = 0;
        }
        return p.second > 0;
    });
    return a_t;
}