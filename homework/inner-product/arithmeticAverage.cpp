#include "arithmeticAverage.hpp"

double ArithmeticAverage(std::vector<int>& first, std::vector<int>& second)
{
    double firstsSum = std::accumulate(first.begin(), first.end(), 0);
    double secondsum = std::accumulate(second.begin(), second.end(), 0);

    double average = (firstsSum + secondsum) / (first.size() + second.size());
    return average;
}

double Distance(std::vector<int>& first, std::vector<int>& second)
{
    if(first.size() != second.size()){
        return 0; 
    }
    std::vector<int> temp(first.size());
    std::transform(first.begin(),
                   first.end(),
                   second.begin(),
                   temp.begin(),
                   [](auto x, auto y){
                       return std::pow(x-y, 2);
                       });
    double n = std::accumulate(temp.begin(), temp.end(), 0);
    n = std::sqrt(n);
    return myRound(n);
}


double myRound(double n)
{
    n *= 1000;
    n = std::round(n);
    return n / 1000;
}
