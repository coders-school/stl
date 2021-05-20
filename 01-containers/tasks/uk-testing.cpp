#include <array>
#include <algorithm>
#include <chrono>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <vector>

template <typename Function, typename... Args>
void measure(std::string const & description,
             Function&& f, Args&&... args) {
    // for (int i = 0; i < 3; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        f(std::forward<Args>(args)...); // f(arg1, arg2, arg3, ..., argN)
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = stop - start;
        std::cout << "Time : " << std::fixed << std::setprecision(10)
                  << diff.count() << " s - " << description << '\n';
        // return result;
    // }
}

template <typename Container>
typename Container::value_type access(Container const & c, size_t index) {
    auto it = c.begin();
    std::advance(it, index);
    return *it;
}

template <typename Container>
void insert(Container & c, typename Container::const_iterator pos, typename Container::value_type val) {
    c.insert(pos, val);
}

template <typename ContainerA, typename ContainerB>
void measureBoth(std::string const & description, ContainerA & c1, size_t size1, ContainerB & c2, size_t size2) {
    measure(description + " access " + std::to_string(size1),
            access<ContainerA>, c1, size1/2);
    measure(description + " access " + std::to_string(size2),
            access<ContainerB>, c2, size2/2);

    measure(description + " insert " + std::to_string(size1),
            insert<ContainerA>, c1, c1.end(), 42);
    measure(description + " insert " + std::to_string(size2),
            insert<ContainerB>, c2, c2.end(), 42);

    std::cout << "sizeof(c1) " << sizeof(c1) << '\n';
    std::cout << "sizeof(c2) " << sizeof(c1) << '\n';
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
    std::forward_list<int> fl1(size1);
    std::forward_list<int> fl2(size2);
    std::deque<int> d1(size1);
    std::deque<int> d2(size2);
    std::map<int, char> m1{};
    std::map<int, char> m2{};
    // std::generate_n(std::back_insert_iterator(m1), size1, []{ return std::pair(1, 'a'); });
    for (int i = 0; i < size1; ++i) {
        m1[i] = 'a' + i;
    }
    for (int i = 0; i < size2; ++i) {
        m2[i] = 'a' + i;
    }

    measureBoth("vector ", v1, size1, v2, size2);
    // measureBoth("array ", a1, size1, a2, size2);
    // measureBoth("forward_list ", fl1, size1, fl2, size2);
    measureBoth("list ", l1, size1, l2, size2);
    measureBoth("deque ", d1, size1, d2, size2);
    // measureBoth("map ", m1, size1, m2, size2);

    return 0;
}
