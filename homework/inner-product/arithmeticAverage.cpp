#include "arithmeticAverage.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>
#include <stdexcept>

double ArithmeticAverage(std::vector<int> vec1, std::vector<int> vec2) {
    vec1.reserve(vec1.size() + vec2.size());
    std::copy(begin(vec2), end(vec2), std::back_inserter(vec1));
    double sum_of_all_items = std::accumulate(begin(vec1), end(vec1), 0);
    auto number_of_elements = vec1.size();
    return sum_of_all_items / number_of_elements;
}

double Distance(std::vector<int> vec1, std::vector<int> vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::logic_error("points from different dimensional spaces.");
    }
    std::transform(begin(vec1),
                   end(vec1),
                   begin(vec2),
                   begin(vec1),
                   [](double el_vec1, double el_vec2) {
                       return el_vec1 - el_vec2;
                   });
    auto result = vec1 | std::views::transform([](int i) { return pow(i, 2); });
    return sqrt(std::accumulate(result.begin(), result.end(), 0));
}