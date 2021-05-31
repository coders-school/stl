// Create a vector v1 with numbers from 1 to 1000
// Calculate the sum of all numbers from 1 to 1000
// Create a vector v2 with 1000 numbers in a repeating sequence: -1, 0, 1, 0, -1, 0, 1, 0...
// Calculate an inner product of vectors v1 and v2
// Calculate the sum of all numbers from v1, that have the corresponding value 1 in v2

#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// template <typename Container>
// void print(Container const & c) {
//     for (auto && el : c) {
//         std::cout << el << " ";
//     }
//     std::cout << '\n';
// }

int main() {
    auto print = [](auto const& c) {
        for (auto&& el : c) {
            std::cout << el << " ";
        }
        std::cout << '\n';
    };

    std::vector<int> v1(1000);
    std::iota(begin(v1), end(v1), 1);
    print(v1);

    std::cout << std::accumulate(begin(v1), end(v1), 0) << "\n";
    std::cout << std::reduce(begin(v1), end(v1)) << "\n";

    // std::vector<int> v2(1000);
    // std::generate(begin(v2), end(v2), [i = 0]() mutable { return (const int[]){-1, 0, 1, 0 }[i++ & 0x03];});
    // constexpr std::array<int,4> a{-1, 0, 1, 0};
    // std::vector<int> v2;
    // std::generate_n(std::back_inserter(v2), 1000, [&a,i{0}]() mutable {return a[i++ % a.size()];});

    // std::generate(begin(v2), end(v2), [i{0}]() mutable { return ( (i++)%3)-1; });
    // std::for_each(begin(v2), end(v2), [](int el) {std::cout << el << ", "; });
    // std::cout << "\n" << "\n";

    // std::generate_n(std::back_inserter(v2), 1000, [i = 2]() mutable { return std::abs(i++ % 4 - 2) - 1; });
    // std::generate_n(std::back_inserter(v2), 1000,
    //                 [n = -1]() mutable {
    //                     return std::sin(n++ * std::acos(-1) / 2);
    //                 });

    std::generate_n(std::back_inserter(v2), 1000, [i{0}]() mutable { return 90 * i++; });
    std::transform(v2.begin(), v2.end(), v2.begin(), [](int i) { return std::round(cos(i * PI / 180.0)) * -1; });

    std::vector<int> v2(1000);
    std::generate(begin(v2), end(v2), [i = -1]() mutable {
        ++i;
        if (i % 4 == 0) { return -1; }
        if (i % 4 == 2) { return 1; }
        return 0;
    });
    print(v2);

    std::cout << std::inner_product(v1.begin(), v1.end(), v2.begin(), 0) << '\n';
    std::cout << std::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0) << '\n';

    // std::replace(begin(v2), end(v2), -1, 0);
    // int sum2 = std::inner_product(begin(v1), end(v1), begin(v2), 0);
    // std::cout << sum2 << '\n';

    auto sum3 = std::transform_reduce(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>{}, [](auto first, auto second){
        if (second == 1) {
            return first;
        }
        return 0;
    });
    std::cout << sum3 << '\n';

    return 0;
}
