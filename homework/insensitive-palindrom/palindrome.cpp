#include "palindrome.hpp"

bool is_palindrome(std::string input_str)
{
    auto it = std::remove_if(begin(input_str), end(input_str), [](auto ch) {return !(std::isalpha(ch));});
    input_str.erase(it, end(input_str));  
    std::transform(begin(input_str), end(input_str), begin(input_str), [](auto ch){ return std::tolower(ch);});

    std::string output_str {};
    std::reverse_copy(begin(input_str), end(input_str), std::back_inserter(output_str));

    return std::equal(begin(input_str), end(input_str), begin(output_str));
}
