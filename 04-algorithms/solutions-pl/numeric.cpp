// Create a vector v1 with numbers from 1 to 1000
// Calculate the sum of all numbers from 1 to 1000
// Create a vector v2 with 1000 numbers in a repeating sequence: -1, 0, 1, 0, -1, 0, 1, 0...
// Calculate an inner product of vectors v1 and v2
// Calculate the sum of all numbers from v1, that have the corresponding value 1 in v2

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

template <typename Container>
void print(Container const& c) {
    for (auto&& el : c) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v1(1000);
    std::iota(v1.begin(), v1.end(), 1);
    print(v1);
    auto sum = std::accumulate(v1.begin(), v1.end(), 0);
    std::cout << sum << '\n';
    auto sum2 = std::reduce(v1.begin(), v1.end());
    std::cout << sum2 << '\n';

    int operator<=>() {

    }

    ==
    !=
    <
    >
    <=
    >-

    // std::vector<int> v2;
    // v2.reserve(1000);
    // std::generate_n(std::back_inserter(v2), 1000, [i = 2]() mutable { return std::abs(i++ % 4 - 2) - 1; });
    // print(v2);

    // std::vector<int> v2(1000);
    // std::generate_n(std::back_inserter(v2), 1000,
    //                 [n = -1]() mutable {
    //                     // sin(n* PI / 2)
    //                     return std::sin(n++ * std::acos(-1) / 2);
    //                 });
    // print(v2);

    // size_t i = 0;
    // std::vector<int> init_values = {-1, 0, 1, 0};
    // std::generate(v2.begin(), v2.end(), [&]() { return init_values[i++ % init_values.size()]; });
    // print(v2);

    std::vector<int> v2(1000);
    std::generate(begin(v2), end(v2), [i = -1]() mutable {
        ++i;
        if (i % 4 == 0) {
            return -1;
        }
        if (i % 4 == 2) {
            return 1;
        }
        return 0;
    });
    print(v2);

    auto result = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout << result << '\n';
    auto result2 = std::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout << result2 << '\n';

    std::cout << "filtered sum:" << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<int>(), [](auto a, auto b) { return b == 1 ? a : 0; }) << "\n";

    std::cout << std::transform_reduce(v1.begin(),
                                    v1.end(),
                                    v2.begin(),
                                    0,
                                    std::plus<>(),
                                    [](const auto& v1_elem, const auto& v2_elem) {
                                        return v2_elem == 1 ? v1_elem : 0;
                                    });

    return 0;
}
