#include <deque>
#include <forward_list>
#include <functional>

using deq = std::deque<std::string>;
using flist = std::forward_list<std::string>;

auto cmp = [](const std::string str1, const std::string str2) {
    if (str1.length() == str2.length()) {
        return str1 < str2;
    } else
        return (str1.length() < str2.length());
};

deq lengthSort(const flist& flist);
