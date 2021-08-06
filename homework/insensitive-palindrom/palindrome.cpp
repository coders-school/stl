#include <algorithm>
#include <string>

bool is_palindrome(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), [](const auto c) { return std::toupper(c); });
    auto it = std::remove_if(str.begin(), str.end(), [](const auto c) {
        return c < 'A' || c > 'Z';
    });
    str.erase(it, str.end());
    std::string result = str;
    std::reverse(result.begin(), result.end());
    return result == str;
}
