#include "arithmeticAverage.h"

#include <numeric>
#include <complex>

double ArithmeticAverage(std::vector<int> first, std::vector<int> second) {
	int sum = std::accumulate(first.begin(), first.end(), 0);
	return std::accumulate(second.begin(), second.end(), sum) / static_cast<double>(first.size() + second.size());
}

double Distance(std::vector<int> first, std::vector<int> second) {
	double result = 0;
	for (size_t i = 0; i < first.size(); ++i) {
		double calculation = first.at(i) - second.at(i);
		calculation *= calculation;
		result += calculation;
	}
	return std::sqrt(result);
}