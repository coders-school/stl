#include "compress.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& paint) {
    std::vector<std::pair<uint8_t, uint8_t>> vec1;
    std::vector<uint8_t> vec;

    auto print = [&vec](const int n) { vec.push_back(n); };
    std::for_each(paint.begin(), paint.end(), [&](std::array<uint8_t, width> arr) { std::for_each(arr.begin(), arr.end(), print); });

    int i = 0;
    int counter = 1;

    // Second Idea it work but test doesnt pass
    //  std::for_each(vec.begin(), vec.end(), [&](uint8_t& n) {
    //      if (i < vec.size()) {
    //          std::for_each_n(vec.begin(), width, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;}
    //                                                                    else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;}
    //                                                                    if(i % width == 0) {vec1.push_back(std::make_pair(vec[i], counter - 1));} });
    //      }
    //      counter = 1;
    //  });

    // FIRST Idea
    std::for_each_n(vec.begin(), 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 32;
    counter = 1;
    std::for_each_n(vec.begin() + 31, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 64;
    counter = 1;
    std::for_each_n(vec.begin() + 63, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 96;
    counter = 1;
    std::for_each_n(vec.begin() + 95, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 128;
    counter = 1;
    std::for_each_n(vec.begin() + 127, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 160;
    counter = 1;
    std::for_each_n(vec.begin() + 159, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 192;
    counter = 1;
    std::for_each_n(vec.begin() + 191, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 224;
    counter = 1;
    std::for_each_n(vec.begin() + 223, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 256;
    counter = 1;
    std::for_each_n(vec.begin() + 255, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 288;
    counter = 1;
    std::for_each_n(vec.begin() + 287, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 320;
    counter = 1;
    std::for_each_n(vec.begin() + 319, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 352;
    counter = 1;
    std::for_each_n(vec.begin() + 351, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 384;
    counter = 1;
    std::for_each_n(vec.begin() + 383, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 416;
    counter = 1;
    std::for_each_n(vec.begin() + 415, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 448;
    counter = 1;
    std::for_each_n(vec.begin() + 447, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 480;
    counter = 1;
    std::for_each_n(vec.begin() + 479, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 512;
    counter = 1;
    std::for_each_n(vec.begin() + 511, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 544;
    counter = 1;
    std::for_each_n(vec.begin() + 543, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 576;
    counter = 1;
    std::for_each_n(vec.begin() + 575, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 608;
    counter = 1;
    std::for_each_n(vec.begin() + 607, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 640;
    counter = 1;
    std::for_each_n(vec.begin() + 639, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 672;
    counter = 1;
    std::for_each_n(vec.begin() + 671, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 704;
    counter = 1;
    std::for_each_n(vec.begin() + 703, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 736;
    counter = 1;
    std::for_each_n(vec.begin() + 735, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 768;
    counter = 1;
    std::for_each_n(vec.begin() + 767, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 800;
    counter = 1;
    std::for_each_n(vec.begin() + 799, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 832;
    counter = 1;
    std::for_each_n(vec.begin() + 831, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 864;
    counter = 1;
    std::for_each_n(vec.begin() + 863, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 896;
    counter = 1;
    std::for_each_n(vec.begin() + 895, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 928;
    counter = 1;
    std::for_each_n(vec.begin() + 927, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 960;
    counter = 1;
    std::for_each_n(vec.begin() + 959, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));
    i = 992;
    counter = 1;
    std::for_each_n(vec.begin() + 991, 31, [&](uint8_t& n) { if(vec[i] == vec[i + 1]) {counter++; ++i;} else {vec1.push_back(std::make_pair(vec[i], counter)); counter = 1; i++;} });
    vec1.push_back(std::make_pair(vec[i], counter));

    for (auto n : vec1) {
        std::cout << n.first << " " << n.second;
    }

    return vec1;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& vec) {
    std::array<std::array<uint8_t, width>, height> arr1;

    auto it = begin(*begin(arr1));

    std::for_each(vec.begin(), vec.end(), [&](std::pair<int, int> pair) { it = std::fill_n(it, pair.second, pair.first); });

    for (auto n : arr1) {
        std::cout << '\n';
        for (auto m : n) {
            std::cout << m;
        }
    }

    return arr1;
}