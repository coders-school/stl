#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

template <typename Iter>
auto middle(Iter first, Iter last) {
    auto size = std::distance(first, last);
    std::advance(first, size / 2);
    return *first;
}

// auto middle(std::vector<int>::iterator first, std::vector<int>::iterator last) {
//     auto size = std::distance(first, last);
//     std::advance(first, size / 2);
//     return *first;
// }

// auto middle(std::forward_list<int>::iterator first, std::forward_list<int>::iterator last) {
//     auto size = std::distance(first, last);
//     std::advance(first, size / 2);
//     return *first;
// }

int main() {
    std::vector v = {1, 2, 3, 4, 5};
    std::list l = {1, 2, 3, 4, 5};
    std::forward_list fl = {1, 2, 3, 4, 5};

    std::cout << middle(v.begin(), v.end());
    std::cout << middle(l.begin(), l.end());
    std::cout << middle(fl.begin(), fl.end());

    return 0;
}
