#include <iostream>
#include <vector>

#include "arithmeticAverage.hpp"

int main(){
    const std::vector<int> v1 = {1,2,3,4};
    const std::vector<int> v2 = {1,2,3,4};

    std::cout<<ArithmeticAverage(v1, v2)<<'\n';
    
    return 0;
}