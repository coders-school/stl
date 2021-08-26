#include "arithmeticAverage.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <stdexcept>

double ArithmeticAverage(const std::vector<int>& vector_first, const std::vector<int>& vector_second) {
    if (vector_first.size() == 0 && vector_second.size() == 0) {
        throw std::logic_error("no numbers in the sets ");
    }
    double sum_of_the_first_set = std::reduce(begin(vector_first), end(vector_first));
    double the_sum_of_the_second_set = std::reduce(begin(vector_second), end(vector_second));
    double amount_of_elements = (vector_first.size()) + (vector_second.size());
    return (sum_of_the_first_set + the_sum_of_the_second_set) / amount_of_elements;
}

double Distance(std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::logic_error("points from different dimensional spaces.");
    }
    double sum = 0;
    std::transform(begin(vec1),
                   end(vec1),
                   begin(vec2),
                   begin(vec1),
                   [&sum](double el_vec1, double el_vec2) {
                       double result = pow((el_vec1 - el_vec2), 2);
                       sum += result;
                       return result;
                   });

    return sqrt(sum);
}
