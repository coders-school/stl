#include "palindrome.hpp"

#include <algorithm>
#include <functional>
#include <locale>
#include <numeric>
#include <vector>
namespace {
}
bool is_palindrome(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), std::not1(std::ptr_fun(isalpha))),
              str.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return std::equal(str.begin(), std::next(str.begin(), str.size() / 2), str.rbegin());
}
