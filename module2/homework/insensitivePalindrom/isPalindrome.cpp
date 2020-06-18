#include "isPalindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string testedString) {
    auto removedChars = std::remove_if(testedString.begin(), testedString.end(), [](unsigned char c) {
        return !std::isalpha(c);
    });

    std::transform(testedString.begin(), removedChars, testedString.begin(), [](unsigned char c) {
        return std::tolower(c);
    });

    std::string reversedInput = "";
    auto halfOfRemainedChars = testedString.begin() + (removedChars - testedString.begin()) / 2;
    std::reverse_copy(testedString.begin(), halfOfRemainedChars, std::back_inserter(reversedInput));

    return equal(testedString.begin(), halfOfRemainedChars, reversedInput.begin());
}

int main() {
    return 0;
}
