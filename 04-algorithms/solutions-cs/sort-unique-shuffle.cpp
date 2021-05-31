#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <random>

int main() {
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::sort(begin(v), end(v));
    auto it = std::unique(begin(v), end(v));
    v.erase(it, v.end());
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(begin(v), end(v), rng);
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    return 0;
}
