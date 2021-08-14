#include <algorithm>
#include <cwctype>

bool is_palindrome(std::string word) {
    std::transform(begin(word), end(word), begin(word), [](auto& el) {
        if (iswalnum(el)) {
            el = std::tolower(el);
            return el;
        } 
        el = 'A';
        return el;
    });
    word.erase(std::remove(begin(word), end(word), 'A'), end(word));

    return std::equal(begin(word), begin(word) + word.size()/2, rbegin(word));
}
