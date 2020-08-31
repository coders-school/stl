#include "arithmeticAverage.hpp"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include <functional>

double ArithmeticAverage(std::vector<int> vec1, std::vector<int> vec2){
    double members = vec1.size() + vec2.size();
    //std::cout << "members" << members << std::endl;

    double value = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, std::plus<>(), std::plus<>())/members;
    return value;
}


double Distance(std::vector<int> vec1, std::vector<int> vec2){

    double distance = std::inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0, 
    [](auto const& el1, auto const& el2){
        return el1 + el2;
    }, 
    [](auto const& el1, auto const& el2){
        return std::pow((el1 - el2),2);
    });

    distance = std::sqrt(distance);

    return distance;

}

