#include <array>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

template <typename Function, typename ... Args>
auto measure(std::string const& description, Function&& f, Args... args) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = f(std::forward<Args>(args)...);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << std::fixed << std::setprecision(9) << diff.count() << " s" << " - " << description << '\n';
    return result;
}

template <typename Container>
auto access(Container const& c, size_t size) {
    auto it = c.begin();
    std::advance(it, size/2);
    return it;
}

// template <typename Container>
// auto insert(Container const& c, size_t size) {
//     auto it = c.begin();
//     std::advance(it, size/2);
//     return *it;
// }

template <typename ContainerA, typename ContainerB>
void measureBoth(std::string const& description, ContainerA const& c1, ContainerB const& c2) {
    auto c1Size = c1.size();
    auto c2Size = c2.size();

    std::cout << "sizeof c1 " + description << " " << c1Size << ": " << sizeof(c1) << '\n';
    std::cout << "sizeof c2 " + description << " " << c2Size << ": " << sizeof(c2) << '\n';

    measure(description + " accessing " + std::to_string(c1Size/2),
            access<ContainerA>, c1, c1Size);
    measure(description + " accessing " + std::to_string(c2Size/2),
            access<ContainerB>, c2, c2Size);
}

int main() {
    constexpr int size = 500'00;
    constexpr int size2 = 5'000'00;
    constexpr int value = 1;

    std::vector<int> v(size, value);
    std::vector<int> v2(size2, value);
    std::array<int, size> a{};       // stack size limitation
    a.fill(value);
    std::array<int, size2> a2{};
    a2.fill(value);
    std::list<int> l(size, value);
    std::list<int> l2(size2, value);
    std::deque<int> d(size, value);
    std::deque<int> d2(size2, value);

    measure("Vector accessing with [] " + std::to_string(size/2),
            [&]{ return v[size/2]; });
    measure("Vector accessing with advance " + std::to_string(size/2),
            access<std::vector<int>>, v, size);

    measureBoth("vector", v, v2);
    measureBoth("array", a, a2);
    measureBoth("list", l, l2);
    measureBoth("deque", d, d2);

    return 0;
}

// 1. Write a measure function that takes a description and any other function (without parameters so far).
// It should measure the execution time of the given function. Use `std::chrono::high_resolution_clock()`.
// After the measurement it should print results + description.

// 2. Measure the time of accessing the middle element of the vectors of size 5M and 50M.

// 3. Measure the time of accessing the middle element of the lists of size 5M and 50M.

// 4. Refactor the code - write an `access` function. It should take a container and a size as parameters.
// You need to extend the functionality of `measure` function to take any number of parameters.
// Use variadic templates and perfect_forwarding.

// 5. Measure if accessing vector via index is faster than accessing it via advancing the begin iterator.

// 6. Add measurement for std::deque of size 5M and 50M.

// 7. Refactor the code. Write measureBoth
// ```cpp
// template <typename Container>
// void measureBoth(std::string const& description, Container const& c1, Container const& c2) {
// ```

// 8. Print sizeof c1 and c2 in measureBoth

// 9. Refactor measure to return the value returned from Function.

// 10. Add measuring the time of inserting an element at the middle position = problematic

// 11. Try compilation with -O3