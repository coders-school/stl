#include "palindrome.hpp"
#include <algorithm>
#include <codecvt>
#include <cwctype>
#include <functional>
#include <iostream>
#include <locale>
#include <vector>

bool is_palindrome(const std::string input) {
    if (input.size() == 1)
        return true;

    std::string input_str;
    std::copy(input.begin(), input.end(), std::back_inserter(input_str));

    auto remove_non_ascii_chars_whitespaces_and_punctation_chars = [](std::string& input_str) {
        input_str.erase(std::remove_if(input_str.begin(),
                                       input_str.end(),
                                       [](unsigned char x) {
                                    std::cout << "x = " << "\t" << std::to_string(x) << "\t" << x << "\t" << std::boolalpha << int(x == '\"') << "\t" << int('\"') << std::endl;
                                    return x >= 127 
                                            or std::ispunct(x) 
                                            or std::isspace(x); }),
                        input_str.end());
    };

    auto convert_all_chars_to_lower = [](std::string& input_str) {
        std::transform(input_str.begin(), input_str.end(), input_str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        ;
    };

    auto give_reversed_string = [](const std::string& input_str) {
        std::string reversed_str;
        std::copy(input_str.begin(), input_str.end(), std::back_inserter(reversed_str));
        std::reverse(reversed_str.begin(), reversed_str.end());
        return reversed_str;
    };

    remove_non_ascii_chars_whitespaces_and_punctation_chars(input_str);
    convert_all_chars_to_lower(input_str);
    auto reversed_str = give_reversed_string(input_str);

    if (input_str == reversed_str)
        return true;

    return false;
}