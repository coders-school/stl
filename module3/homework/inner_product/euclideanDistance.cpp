#include <cmath>
#include <functional>
#include <numeric>

#include "euclideanDistance.hpp"

double euclideanDistance(const std::vector<int>& vecA, const std::vector<int>& vecB) {
    return std::sqrt(std::inner_product(vecA.begin(), vecA.end(),
                                        vecB.begin(),
                                        0.0,
                                        std::plus<>(),
                                        [](const auto a, const auto b) {
                                            return std::pow(a - b, 2);
                                        }));
}
