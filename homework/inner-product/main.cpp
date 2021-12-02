#include "arithmeticAverage.hpp"
#include <algorithm>

int main()
{
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 2, 3, 4};
    std::cout<<"\nArithemtic Average: "<< ArithmeticAverage(a, b);
    a = {7, 4, 3}; 
    b = {17, 6, 2};
    std::cout<<"\nDistance: "<< Distance(a, b);

}