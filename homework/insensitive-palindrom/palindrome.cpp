#include "palindrome.hpp"

bool is_palindrome(std::string sentence) {
    for (size_t i = 0; i < sentence.size(); i++) {
        if (!isalpha(sentence[i])) {
            sentence.erase(i, 1);
            i--;

        } else {
            sentence[i] = tolower(sentence[i]);
        }
    }
    auto iterators = std::mismatch(sentence.begin(), sentence.end(), sentence.rbegin(), sentence.rend());
    return (iterators.first == sentence.end() && iterators.second == sentence.rend());
}