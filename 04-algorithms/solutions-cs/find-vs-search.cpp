#include <algorithm>
#include <array>
#include <vector>
#include <iostream>


int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    auto first = begin(v);
    while (first != end(v)) {
        auto position = std::find_if(first, end(v), [](auto item){ return item > 6; });
        if (position != end(v)) {
            std::cout << *position << '\n';
            first = ++position;
        }
    }

    constexpr std::array<int, 4> a = {2, 4, 6, 8};
    first = v.begin();
    while (first != v.end()) {
        auto found = std::find_first_of(first, end(v), begin(a), end(a));
        if (found == v.end()) {
            break;
        }
        std::cout << "Found : " << *found << '\n';
        first = ++found;
    }

    std::vector range = {7, 7};
    auto found = std::search(begin(v), end(v), range.begin(), range.end());
    if (found != v.end()) {
        std::cout << *found++ << '\n';
        std::cout << *found++ << '\n';
        std::cout << *found++ << '\n';
    }

    // C++20 found = std::ranges::search(v, {7, 7});

    return 0;
}
