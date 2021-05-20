#include <array>
#include <chrono>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <vector>

template <typename Function, typename... Args>
void measure(std::string const& description, Function f, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    f(std::forward<Args>(args)...);  // f(forward(arg1), forward(arg2), forward(...), forward(argN))
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = stop - start;
    std::cout << std::fixed << std::setprecision(10) << diff.count()
              << " s - " << description << '\n';
}

void map_testing() {
    std::map<int, char> m;
    m[1];
    m[2] = 'b';
    m.insert(std::make_pair(3, 'c'));
    m.insert({4, 'd'});

    for (auto el : m) {
        std::cout << el.first << ": " << el.second << '\n';
    }

    m[5];
    m[2] = 'z';

    for (auto [key, value] : m) {
        std::cout << key << ": " << value << '\n';
    }
}

int main() {
    constexpr size_t size1 = 100'000;
    constexpr size_t size2 = 1'000'000;

    std::vector<int> v1(size1);
    std::vector<int> v2(size2);
    // std::array<int, size1> a1;
    // std::array<int, size2> a2;
    std::list<int> l1(size1);
    std::list<int> l2(size2);
    std::forward_list<int> fl1(size1);
    std::forward_list<int> fl2(size2);

    std::iota(v1.begin(), v1.end(), 1);
    std::iota(v2.begin(), v2.end(), 1);
    // std::iota(a1.begin(), a1.end(), 1);
    // std::iota(a2.begin(), a2.end(), 1);
    std::iota(l1.begin(), l1.end(), 1);
    std::iota(l2.begin(), l2.end(), 1);
    std::iota(fl1.begin(), fl1.end(), 1);
    std::iota(fl2.begin(), fl2.end(), 1);

    std::deque<int> d1(v1.begin(), v1.end());
    std::deque<int> d2(v2.begin(), v2.end());
    std::set<int> s1(d1.begin(), d1.end());
    std::set<int> s2(d2.begin(), d2.end());
    std::multiset<int> ms1(d1.begin(), d1.end());
    std::multiset<int> ms2(d2.begin(), d2.end());

    auto random_access = [&](auto& container, auto index) {
        // std::cout << sizeof(container) << '\n';
        auto it = container.begin();
        std::advance(it, index);
        return *it;
    };

    auto insert = [&](auto& container, auto position, auto value) {
        container.insert(position, value);
    };

    auto index_insert = [&](auto& container, auto index, auto element) {
        auto it = container.begin();
        std::advance(it, index);
        container.insert(it, element);
    };

    auto insert_after = [&](auto& container, auto position, auto value) {
        container.insert_after(position, value);
    };

    measure("vector " + std::to_string(size1), random_access, v1, size1 / 2);
    measure("vector " + std::to_string(size2), random_access, v2, size2 / 2);
    // measure("array " + std::to_string(size1), random_access, a1, size1/2);
    // measure("array " + std::to_string(size2), random_access, a2, size2/2);
    measure("list " + std::to_string(size1), random_access, l1, size1 / 2);
    measure("list " + std::to_string(size2), random_access, l2, size2 / 2);
    measure("forward_list " + std::to_string(size1), random_access, fl1, size1 / 2);
    measure("forward_list " + std::to_string(size2), random_access, fl2, size2 / 2);
    measure("deque " + std::to_string(size1), random_access, d1, size1 / 2);
    measure("deque " + std::to_string(size2), random_access, d2, size2 / 2);

    measure("vector insert " + std::to_string(size1), insert, v1, std::next(v1.begin(), size1 / 2), 42);
    measure("vector insert " + std::to_string(size2), insert, v2, std::next(v2.begin(), size2 / 2), 42);
    measure("list insert " + std::to_string(size1), insert, l1, std::next(l1.begin(), size1 / 2), 42);
    measure("list insert " + std::to_string(size2), insert, l2, std::next(l2.begin(), size2 / 2), 42);
    measure("deque insert " + std::to_string(size1), insert, d1, std::next(d1.begin(), size1 / 2), 42);
    measure("deque insert " + std::to_string(size2), insert, d2, std::next(d2.begin(), size2 / 2), 42);

    measure("vector insert " + std::to_string(size1), index_insert, v1, size1 / 2, 42);
    measure("vector insert " + std::to_string(size2), index_insert, v2, size2 / 2, 42);
    measure("list insert " + std::to_string(size1), index_insert, l1, size1 / 2, 42);
    measure("list insert " + std::to_string(size2), index_insert, l2, size2 / 2, 42);
    measure("deque insert " + std::to_string(size1), index_insert, d1, size1 / 2, 42);
    measure("deque insert " + std::to_string(size2), index_insert, d2, size2 / 2, 42);

    measure("forward_list insert " + std::to_string(size1), insert_after, fl1, std::next(fl1.begin(), size1 / 2), 42);
    measure("forward_list insert " + std::to_string(size2), insert_after, fl2, std::next(fl2.begin(), size2 / 2), 42);

    measure("set insert " + std::to_string(size1), insert, s1, std::next(s1.begin(), size1 / 2), 42);
    measure("set insert " + std::to_string(size2), insert, s2, std::next(s2.begin(), size2 / 2), 42);
    measure("multiset insert " + std::to_string(size1), insert, ms1, std::next(ms1.begin(), size1 / 2), 42);
    measure("multiset insert " + std::to_string(size2), insert, ms2, std::next(ms2.begin(), size2 / 2), 42);

    measure("set " + std::to_string(size1), random_access, s1, size1 / 2);
    measure("set " + std::to_string(size2), random_access, s2, size2 / 2);
    measure("multiset " + std::to_string(size1), random_access, ms1, size1 / 2);
    measure("multiset " + std::to_string(size2), random_access, ms2, size2 / 2);

    return 0;
}
