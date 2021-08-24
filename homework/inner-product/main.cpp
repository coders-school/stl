#include <iostream>
#include <vector>

#include "arithmeticAverage.hpp"

int main() {

std::vector<int> vec1{7, 4, 3, 13};
std::vector<int> vec2{17, 6, 2, -2};

std::cout.precision(16);
std::cout << "averange: " <<  ArithmeticAverage(vec1, vec2) << '\n';

std::cout << "distance 18.16590212458495  : " << Distance(vec1, vec2) << '\n';

return 0;

}
