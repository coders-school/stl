#include <algorithm>
#include <string>

bool is_palindrome(const std::string& str) {
  std::string new_str;
  std::copy_if(begin(str), end(str), std::back_inserter(new_str), ::isalpha);
  std::transform(begin(new_str), end(new_str), begin(new_str), ::tolower);
  return std::equal(begin(new_str), std::next(begin(new_str), new_str.size()),
                    rbegin(new_str));
}
