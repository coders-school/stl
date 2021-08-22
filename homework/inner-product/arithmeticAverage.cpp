#include "arithmeticAverage.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

double ArithmeticAverage(std::vector<int> vec1, std::vector<int> vec2) {
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec1));

    double sum = std::accumulate(vec1.begin(), vec1.end(), 0);
    int count = vec1.size();
    return sum / count;
}

double Distance(std::vector<int> vec1, std::vector<int> vec2) {
    std::transform(begin(vec1),
                   end(vec1),
                   begin(vec2),
                   begin(vec1),
                   [](double el_vec1, double el_vec2) {
                       return el_vec1 - el_vec2;
                   });
    auto results = vec1 | std::views::transform([](int i) { return abs(i); }) 
                        | std::views::transform([](int i) { return pow(i, 2); });
    return sqrt(std::accumulate(results.begin(), results.end(), 0));
}