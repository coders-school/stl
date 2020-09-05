#include <cmath>
#include <functional>
#include <numeric>
#include <vector>

double ArithmeticAverage(std::vector<int>& v1, std::vector<int>& v2) {
    double size = v1.size() + v2.size();
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(), std::plus<>()) / size;
}

double Distance(std::vector<int>& v1, std::vector<int>& v2) {
    return std::sqrt(std::inner_product(v1.begin(), v1.end(), v2.begin(), 0, std::plus<>(), [](auto x, auto y) { return std::pow((y - x), 2); }));
}
