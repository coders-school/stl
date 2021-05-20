#include <array>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

template <typename Function, typename ... Args>
auto measure(std::string const& description, Function&& f, Args &&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = f(std::forward<Args>(args)...);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << std::fixed << std::setprecision(9) << diff.count() << " s" << " - " << description << '\n';
    return result;
}

template <typename Container>
typename Container::const_iterator access(Container const& c, size_t size) {
    auto it = c.begin();
    std::advance(it, size/2);
    return it;
}

template <typename Container>
typename Container::iterator insert(Container & c, typename Container::const_iterator pos, typename Container::value_type value) {
    return c.insert(pos, value);
}

template <typename ContainerA, typename ContainerB>
void measureBoth(std::string const& description, ContainerA & c1, ContainerB & c2) {
    auto c1Size = c1.size();
    auto c2Size = c2.size();

    std::cout << "sizeof c1 " + description << " " << c1Size << ": " << sizeof(c1) << '\n';
    std::cout << "sizeof c2 " + description << " " << c2Size << ": " << sizeof(c2) << '\n';

    auto it = measure(description + " accessing " + std::to_string(c1Size/2),
            access<ContainerA>, c1, c1Size);
    measure(description + " inserting " + std::to_string(c1Size/2),
            insert<ContainerA>, c1, it, 42);
    it = measure(description + " accessing " + std::to_string(c2Size/2),
            access<ContainerB>, c2, c2Size);
    measure(description + " inserting " + std::to_string(c2Size/2),
            insert<ContainerB>, c2, it, 42);

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

    auto it = access(v, size/2);
    insert(v, it, 42);

    measure("Vector accessing with [] " + std::to_string(size/2),
            [&]{ return v[size/2]; });
    measure("Vector accessing with advance " + std::to_string(size/2),
            access<std::vector<int>>, v, size);

    measureBoth("vector", v, v2);
//    measureBoth("array", a, a2);
    measureBoth("list", l, l2);
    measureBoth("deque", d, d2);

    return 0;
}
