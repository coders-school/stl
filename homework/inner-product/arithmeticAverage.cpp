#include "arithmeticAverage.hpp"
#include <numeric>
#include <cmath>

float ArithmeticAverage(const std::vector<int>& v1, const std::vector<int>& v2){
    float sum = 0.f;
    float length = v1.size() + v2.size();
    
    for(const auto el : v1){
        sum += el;
    }
    
    for(const auto el : v2){
        sum += el;
    }
    
    return sum/length;
}

float Distance(const std::vector<int>& v1, const std::vector<int>& v2){
    if(v1.size() != v2.size()){
        return 0.f;
    }
    float sum = 0.f;
    
    for(int i = 0; i < v1.size(); i++){
        sum += pow(v1[i] - v2[i], 2);
    }
    
    return sqrt(sum);
}