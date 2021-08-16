#include "arithmeticAverage.h"

#include <numeric>
#include <complex>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
	int sum = std::accumulate(first.begin(), first.end(), 0);
	return std::accumulate(second.begin(), second.end(), sum) / static_cast<double>(first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
	auto calculate = []( const auto& val1, const auto& val2) { return std::pow(val1 - val2, 2); };
	auto innerProduct = std::inner_product(first.begin(), first.end(), second.begin(), 0, std::plus<>(), calculate);
	return std::sqrt(innerProduct);
}