#include <algorithm>
#include <iostream>
#include <vector>

// Create std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
// Create a lambda that captures this vector and displays its contents
// Create a lambda that takes an int as an argument and displays it
// Use this lambda in the std::for_each() algorithm to display the entire container

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto lambda = [&](){
        for (auto && el : v) {
            std::cout << el << " ";
        }
        std::cout << '\n';
    };
    lambda();

    std::for_each(v.begin(), v.end(), [](int a){ std::cout << a << " "; });
    return 0;
}
