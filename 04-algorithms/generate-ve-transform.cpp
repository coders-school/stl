#include <algorithm>
#include <iostream>
#include <vector>

template <typename Container>
void print(Container const & c) {
    for (auto && element : c) {
        std::cout << element << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::pair<int, std::string>> v {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };

    std::vector<int> v2(v.size());
    std::transform(begin(v), end(v), v2.begin(), [](const auto& pair) {
        return pair.first;
    });
    print(v2);

    std::vector<std::string> v3;
    std::transform(begin(v),
                   end(v),
                   std::back_inserter(v3),
                   [](const auto& pair){
                       return pair.second + " : " + std::to_string(pair.first);
                   });
    print(v3);

    std::vector<char> v4;
    std::generate_n(std::back_inserter(v4), 13, [c = 'a' - 2]() mutable { return c+=2; });
    print(v4);

    return 0;
}