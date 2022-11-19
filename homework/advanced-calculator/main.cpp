#include <functional>
#include <iostream>
#include <string>
#include "advancedCalculator.hpp"
#include <cmath>

bool checkIfDoublee(const double a){

    if(static_cast<int>(a * 10000) % 10000 == 0)
        return false;
    return true;
}

int main(){
    int a  = 0;
    double b = 0.5;
    if(checkIfDoublee(b))
        std::cout<<"DOUBLE";
    else
        std::cout<<"INT";
    return 0;
}