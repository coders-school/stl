// Create std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
// Remove all duplicated values from v
// Print all elements using std::copy and std::ostream_iterator
// Shuffle all elements
// Print all elements once again

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
#include <vector>

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::set<int> s(v.begin(), v.end());
    std::copy(s.begin(), s.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    return 0;
}
