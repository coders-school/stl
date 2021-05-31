// Create std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Find all elements greater than 6 and print them
// Find all elements equal to 2, 4, 6 or 8 and print them
// Search the vector v for a range {6, 6} and {7, 7}
// Run std::adjacent_find on the vector v

#include <array>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

    auto it = v.begin();
    while (it != v.end()) {
        it = find_if(it, v.end(), [](const int& x) { return x > 6; });
        if (it != v.end()) {
            cout << *it << " ";
            it++;
        }
    }
    std::cout << '\n';

    std::copy_if(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "), [](const int& x) { return x > 6; });
    std::cout << '\n';

    constexpr std::array<int, 4> a = {2, 4, 6, 8};
    it = v.begin();
    while (it != v.end()) {
        it = find_first_of(it, v.end(), a.begin(), a.end());
        if (it == v.end()) {
            break;
        }
        cout << *it << " ";
        it++;
    }
    std::cout << '\n';

    // constexpr std::array<int, 2> a2 = {6, 6};
    // auto found = search(begin(v), end(v), begin(a2), end(a2));
    auto found = search_n(begin(v), end(v), 2, 6);
    if (found != end(v)) {
        std::cout << *found << '\n';
        std::cout << *++found << '\n';
        std::cout << *++found << '\n';
    }
    std::cout << '\n';

    found = std::adjacent_find(begin(v), end(v));
    if (found != end(v)) {
        std::cout << *found << '\n';
    }

    return 0;
}