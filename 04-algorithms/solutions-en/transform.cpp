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

int main() {
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    std::vector<int> v2;
    std::transform(begin(v), end(v), back_inserter(v2), [](auto pair) { return pair.first; });
    std::for_each(begin(v2), end(v2), [](int el) { std::cout << el << ", "; });
    std::cout << "\n";

    std::vector<std::string> v3;
    std::transform(begin(v), end(v), std::back_inserter(v3), [](auto p) { return p.second + ":" + std::to_string(p.first); });
    std::for_each(begin(v3), end(v3), [](auto el) { std::cout << el << ", "; });
    std::cout << "\n";

    std::vector<char> v4(13);
    std::generate_n(begin(v4), 13, [c = 'a' - 2]() mutable { return c += 2; });
    std::for_each(begin(v4), end(v4), [](auto el) { std::cout << el << ", "; });
    std::cout << "\n";

    int i = 'A' - 2;
    std::generate(begin(v4), end(v4), [&i]() { return i += 2; });

    std::vector<char> v5;
    std::cout << "Chars\n";
    std::generate_n(std::back_inserter(v5), ('z' - 'a') / 2, [i{0}]() mutable { char ret = 'a' + i; i += 2; return ret; });
    for (const auto& item : v5)
        std::cout << item << " ";
    std::cout << std::endl;

    return 0;
}
