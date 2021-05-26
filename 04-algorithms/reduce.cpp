#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename Container>
void print(Container const & c) {
    for (auto && el : c) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v1(1000);
    std::iota(begin(v1), end(v1), 1);
    print(v1);
    // auto sum = std::reduce(begin(v1), end(v1));
    auto sum = std::accumulate(begin(v1), end(v1), 0);
    std::cout << sum << '\n';

    std::vector<int> v2(1000);
    std::generate(begin(v2), end(v2), [i = -1]() mutable {
        ++i;
        if (i % 4 == 0) { return -1; }
        if (i % 4 == 2) { return 1; }
        return 0;
    });
    print(v2);

    // auto product = std::transform_reduce(begin(v1), end(v1), begin(v2), 0);
    auto product = std::inner_product(begin(v1), end(v1), begin(v2), 0);
    std::cout << product << '\n';

    auto sum1 = [](const auto & lhs, const auto & rhs) {
        if (rhs == 1) {
            return lhs;
        }
        return 0;
    };
    auto sumOfOnes = std::inner_product(begin(v1),
                                        end(v1),
                                        begin(v2),
                                        0,
                                        std::plus<>(),
                                        sum1);
    std::cout << sumOfOnes << '\n';
    return 0;
}
