#include <string>

inline constexpr uint8_t ASCII_digits_range_start = 48;
inline constexpr uint8_t ASCII_digits_range_end = 57;

inline constexpr uint8_t ASCII_small_letters_range_start = 97;
inline constexpr uint8_t ASCII_small_letters_range_end = 122;

inline constexpr uint8_t ASCII_Capital_letters_range_start = 65;
inline constexpr uint8_t ASCII_Capital_letters_range_end = 90;

bool is_palindrome(std::string word);