// Create std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Find all elements greater than 6 and print them
// Find all elements equal to 2, 4, 6 or 8 and print them
// Search the vector v for a range {6, 6} and {7, 7}
// Run std::adjacent_find on the vector v

#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    auto greaterThanSix = [](const auto& el) { return el > 6; };

    std::copy_if(
        v.cbegin(), v.cend(),
        std::ostream_iterator<int>(std::cout, "\t"),
        greaterThanSix);
    std::cout << '\n';

    auto first = v.cbegin();
    while (first != v.cend()) {
        auto found = std::find_if(first, v.cend(), greaterThanSix);
        if (found != v.cend()) {
            std::cout << *found << '\t';
            first = ++found;
        }
    }
    std::cout << '\n';

    constexpr std::array<int, 4> a = {2, 4, 6, 8};
    first = v.cbegin();
    while (first != v.cend()) {
        auto found = std::find_first_of(first, v.cend(), a.cbegin(), a.cend());
        if (found == v.cend()) {
            break;
        }
        std::cout << *found << '\t';
        first = ++found;
    }
    std::cout << '\n';

    // std::set<int> s = {2, 4, 6, 8};
    // std::copy_if(
    //     v.cbegin(), v.cend(),
    //     std::ostream_iterator<int>(std::cout, "\t"),
    //     [](auto & el){ return s.contains(el); });
    // std::cout << '\n';

    std::array<int, 2> a2 {7, 7};
    auto found = std::search(begin(v), end(v), begin(a2), end(a2));
    if (found != end(v)) {
        std::cout << *found << '\t';
    }
    std::cout << '\n';

    // C++20 auto found = std::search(v, {6, 6});

    found = std::adjacent_find(begin(v), end(v));
    if (found != end(v)) {
        std::cout << *found << '\t';
        std::cout << *++found << '\t';
        std::cout << *++found << '\t';
    }
    std::cout << '\n';

    return 0;
}
