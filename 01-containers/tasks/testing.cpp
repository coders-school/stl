#include <array>
#include <chrono>
#include <list>
#include <iostream>
#include <iomanip>
#include <vector>

template <typename Function, typename... Args>
void measure(std::string const & description,
             Function f, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    f(std::forward<Args>(args)...); // f(arg1, arg2, arg3, ..., argN)
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << "Time : " << std::fixed << std::setprecision(10)
              << diff.count() << " s - " << description << '\n';
}

template <size_t SIZE>
auto access_a(std::array<int, SIZE> const & c, size_t index) {
    return c[index];
}

auto access(std::vector<int> const & c, size_t index) {
    return c[index];
}

int main() {
    constexpr int size1 = 100'000;
    constexpr int size2 = 1'000'000;
    std::vector<int> v1(size1);
    std::vector<int> v2(size2);
    std::array<int, size1> a1;
    std::array<int, size2> a2;
    std::list<int> l1(size1);
    std::list<int> l2(size2);



    measure("vector advance " + std::to_string(size1) + " - accessing the middle element",
            [&]{
                auto it = v1.begin();
                std::advance(it, size1/2);
                return *it;
            });
    measure("vector " + std::to_string(size1) + " - accessing the middle element",
            [&]{ return v1[size1/2]; });
    measure("vector " + std::to_string(size2) + " - accessing the middle element",
            [&]{ return v2[size2/2]; });
    measure("array " + std::to_string(size1) + " - accessing the middle element",
            [&]{ return a1[size1/2]; });
    measure("array " + std::to_string(size2) + " - accessing the middle element",
            [&]{ return a2[size2/2]; });
    measure("list " + std::to_string(size1) + " - accessing the middle element",
            [&]{
                auto it = l1.begin();
                std::advance(it, size1/2);
                return *it;
            });
    measure("list " + std::to_string(size2) + " - accessing the middle element",
            [&]{
                auto it = l2.begin();
                std::advance(it, size2/2);
                return *it;
            });
    // measure("vector " + std::to_string(size1) + " - accessing the middle element",
    //         access, v1, size1/2);
    // measure("array " + std::to_string(size1) + " - accessing the middle element",
    //         access_a<size1>, a1, size1/2);


    return 0;
}
