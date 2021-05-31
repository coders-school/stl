// Create std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
// Create a lambda that captures this vector and displays its contents
// Create a lambda that takes an int as an argument and displays it
// Use this lambda in the std::for_each() algorithm to display the entire container

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //                   [b                             e)
    auto print = [&v](){
        for (auto el : v) {
            std::cout << el << " ";
        }
        std::cout << '\n';
    };
    print();

    std::for_each(v.begin() + 2, v.end(), [](int i){
        std::cout << i << " ";
    });

    for_each(std::begin(v), std::end(v), [](int i){
        std::cout << i << " ";
    });


    return 0;
}
