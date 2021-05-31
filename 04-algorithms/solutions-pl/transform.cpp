// Create a below vector

// std::vector<std::pair<int, std::string>> v {
//     {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
// };
// Create a vector of ints v2 and fill it with all ints (first item of pair) from v

// Create a vector of strings v3 and fill it with concatenated string + colon + int from all pairs from v

// Create a vector of chars v4 and fill it with every other letter of the alphabet

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

template <typename Container>
void print(Container const& c) {
    for (auto&& el : c) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::pair<int, std::string>> v{{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    std::vector<int> v2(v.size());
    std::transform(v.cbegin(), v.cend(), v2.begin(), [](auto&& p) { return p.first; });
    print(v2);

    std::vector<std::string> v3;
    std::transform(v.cbegin(), v.cend(), std::back_inserter(v3), [](auto&& p) { return p.second + ":" + std::to_string(p.first); });
    print(v3);

    // std::vector<int> v2(v.size());
    // std::generate(begin(v2), end(v2), [it{begin(v)}]() mutable { return it++->first; });

    // std::vector<char> v4;
    // for (char c = 'a'; c <= 'z'; c += 2) v4.push_back(c);

    // std::vector<char> v4(13);
    // char c = 'a';
    // std::generate_n(v4.begin(), v4.size(), [&]() { char result = c; c+=2; return result; });

    std::vector<char> v4;
    std::generate_n(std::back_inserter(v4), 13, [c = 'A' - 2]() mutable { return c += 2; });
    print(v4);

    return 0;
}
