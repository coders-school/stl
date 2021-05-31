// Create std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Remove all duplicated values from v
// Print all elements using std::copy and std::ostream_iterator
// Shuffle all elements
// Print all elements once again

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <random>

template <typename Container>
void print(Container const& c) {
    for (auto&& el : c) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

// template <typename Container>
// void print(const Container& c) {
//     std::copy(c.cbegin(), c.cend(),
//               std::ostream_iterator<typename Container::value_type>(std::cout, " "));
//     std::cout << '\n';
// }

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::set<int> s(v.begin(), v.end());
    std::copy(s.cbegin(), s.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    return 0;
}
