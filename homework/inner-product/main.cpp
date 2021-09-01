#include "arithmeticAverage.hpp"
#include <iostream>

int main()
{
    std::vector<int> v1 {1, 2, 3, 4};
    std::vector<int> v2 {1, 2, 3, 4};
        
    std::vector<int> v3 {7,4,3};
    std::vector<int> v4 {17,6,2};
    
    std::cout<<ArithmeticAverage(v1,v2)<<"\n";
    std::cout<<Distance(v3,v4)<<"\n";
    
    return 0;
}
