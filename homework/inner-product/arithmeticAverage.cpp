#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int> first,const std::vector<int> second){
  return std::inner_product(first.begin(),
                            first.end(),
                            second.begin(), 
                            0,
                            std::plus<>(),std::plus<>()) / 
                            static_cast<double>((first.size() + second.size()));
}

double Distance(const std::vector<int> first,const std::vector<int> second){
  auto minusPow = [](const int & x, const int & y){
    return pow(x - y,2);
  };
  return sqrt(std::inner_product(first.begin(),
                                 first.end(),
                                 second.begin(),
                                 0,
                                 std::plus<>(), minusPow));
}