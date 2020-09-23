#include "arithmeticAverage.hpp"

#include <functional>
#include <numeric>
#include <math.h>

double ArithmeticAverage(std::vector<int> & first, std::vector<int>  & second){
    double result = std::inner_product(first.begin(), first.end() ,second.begin(),0
                                    , std::plus<>(), std::plus<>());
    return result / (first.size() * 2);
}

double Distance(std::vector<int> & first, std::vector<int>  & second){
    double result = std::inner_product(first.begin(), first.end() ,second.begin(),0,
                                    std::plus<>(),
                                    [](double a, double b){ return pow(a - b, 2);}
    );
    return sqrt(result);
}
