#include <chrono>
#include <iostream>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> first(1000, -10);
    std::vector<int> second(1000, 10);

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << Distance(first, second) << '\n';
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Distance(): " << elapsed.count() << " s\n";
    
    start = std::chrono::high_resolution_clock::now();
    std::cout << DistanceRecurrent(first, second) << '\n';
    stop = std::chrono::high_resolution_clock::now();
    elapsed = stop - start;
    std::cout << "DistanceRecurrent(): " << elapsed.count() << " s\n";
}
