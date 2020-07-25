#include <forward_list>
#include <iostream>
#include <string>
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

template <typename Container>
void printCollection(const Container& collection) {
    for (const auto& element : collection) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

deq lengthSort(const flist& flist) {
    auto tmpList = flist;
    tmpList.sort(cmp);
    deq deque(tmpList.begin(), tmpList.end());
    return deque;
}

int main() {
    std::forward_list<std::string> words = {"Somebody", "once",  "told", "me",
                                              "the",      "world", "is",   "gonna",
                                              "roll",     "me"};

    printCollection(words);
    auto sorted = lengthSort(words);
    printCollection(sorted);

    return 0;
}
