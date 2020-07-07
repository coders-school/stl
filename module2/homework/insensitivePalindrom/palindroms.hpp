#pragma once

#include <string>

constexpr uint8_t ASCII_digits_range_start = 48;
constexpr uint8_t ASCII_digits_range_end = 57;

constexpr uint8_t ASCII_small_letters_range_start = 97;
constexpr uint8_t ASCII_small_letters_range_end = 122;

constexpr uint8_t ASCII_Capital_letters_range_start = 65;
constexpr uint8_t ASCII_Capital_letters_range_end = 90;

constexpr uint8_t ASCII_Capital_small_distance = 32;

bool is_palindrome(const std::string& word);

