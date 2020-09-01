#include "arithmeticAverage.hpp"

#include "cmath"
#include "functional"
#include "numeric"

double ArithmeticAverage(const std::vector<int>& firstVec, const std::vector<int>& secondVec) {
    const double numberOfElements = firstVec.size() + secondVec.size();
    double init{};

    if (numberOfElements == 0) {
        return numberOfElements;
    }

    double arithmeticAverage = std::inner_product(firstVec.begin(), firstVec.end(),
                                                  secondVec.begin(), init, std::plus<double>(),
                                                  [numberOfElements](const int numberFromFirstVec, const int numberFromSecondVec) {
                                                      return double(numberFromFirstVec + numberFromSecondVec) / numberOfElements;
                                                  });

    return arithmeticAverage;
}
double Distance(const std::vector<int>& firstVec, const std::vector<int>& secondVec) {
    const uint8_t exponent = 2;
    double init{};

    if (firstVec.size() != secondVec.size()) {
        return 0;
    }

    double squareOfTheSumOfProducts = std::inner_product(firstVec.begin(), firstVec.end(),
                                                         secondVec.begin(), init, std::plus<double>(),
                                                         [](const int numberFromFirstVec, const int numberFromSecondVec) {
                                                             return pow(fabs(double(numberFromFirstVec - numberFromSecondVec)), exponent);
                                                         });

    return std::sqrt(squareOfTheSumOfProducts);
}