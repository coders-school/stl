#pragma once
#include<array>
#include<vector>
#include<utility> // pair
#include<iostream>
#include<cctype>
#include<cstdint>

constexpr size_t width = 32ul;
constexpr size_t height = 32ul;
std::vector<std::pair<uint8_t, uint8_t>>  compressGrayscale(std::array<std::array<uint8_t, width>, height>&);
void printMap(std::array<std::array<uint8_t, width>, height>);
void printMap(std::vector<std::pair<uint8_t, uint8_t>> );
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>);
void printMap3(std::array<std::array<uint8_t, width>, height> array);
void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap);
void printMap2(std::vector<std::pair<uint8_t, uint8_t>> bitmap);

//std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(std::array<std::array<uint8_t, width>, height> & bitmap);

// void printPair(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
//                std::vector<std::pair<uint8_t, uint8_t>> &bitmap2);

// bool equal(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
//                std::vector<std::pair<uint8_t, uint8_t>> &bitmap2);

// void whatDiffrent(std::vector<std::pair<uint8_t, uint8_t>> &bitmap1, 
//                std::vector<std::pair<uint8_t, uint8_t>> &bitmap);