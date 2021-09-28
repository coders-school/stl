#include <chrono>
#include <iostream>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> first(10000, 2);
    std::vector<int> second(10000, 2);

    auto start = std::chrono::high_resolution_clock::now();
    Distance(first, second);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Distance(): " << elapsed.count() << " s\n";
    
    start = std::chrono::high_resolution_clock::now();
    DistanceRecurrent(first, second);
    stop = std::chrono::high_resolution_clock::now();
    elapsed = stop - start;
    std::cout << "DistanceRecurrent(): " << elapsed.count() << " s\n";
}
