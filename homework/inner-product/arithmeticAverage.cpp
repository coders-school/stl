#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    if (first.empty() && second.empty()) {
        return 0.0;
    }
    int size = first.size() + second.size();
    double average = 0.0;
    for (auto num: first) {
        average += num;
    }
    for (auto num: second) {
        average += num;
    }
    return average / size;
}

double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    return 0;
}
