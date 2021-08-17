#include <algorithm>

#include "insensitive-palindrome.hpp"

bool is_palindrome(const std::string& input) {
    if (input.empty()) {
        return true;
    }

    std::string potential_palindrome;
    std::copy_if(begin(input),
                 end(input),
                 back_inserter(potential_palindrome),
                 [](char ch) {
                     return std::isalpha(ch) || std::isdigit(ch);
                 });
    std::transform(begin(potential_palindrome),
                   end(potential_palindrome),
                   begin(potential_palindrome),
                   ::tolower);

    return std::mismatch(potential_palindrome.begin(),
                         potential_palindrome.end(),
                         potential_palindrome.rbegin()).first
            == potential_palindrome.end();
}
