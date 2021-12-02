#include "arithmeticAverage.hpp"

float ArithmeticAverage(std::vector<int>& first, const std::vector<int>& second)
{
    size_t size_first = first.size();
    size_t size_second = second.size();
    int accumulated_first = std::accumulate(first.begin(), first.end(), 0);
    int accumulated_second = std::accumulate(second.begin(), second.end(), 0);

    return (float)( accumulated_first + accumulated_second) / (size_first + size_second);
}
float Distance(const std::vector<int>& first, const std::vector<int>& second)
{
    size_t size = 0;
    if (first.size() != second.size()){
        return -1;
    } 
    else {
        size = first.size();
    }

    std::vector<int> distV(size);
    std::transform(first.begin(), 
                   first.end(), 
                   second.begin(), 
                   distV.begin(),
                   [](int a, int b){return abs(a - b);});
    
    std::transform(distV.begin(), distV.end(), distV.begin(), [](int a){return a*a;});
    int accumulatedDist = std::accumulate(distV.begin(), distV.end(), 0);

    return sqrt(accumulatedDist);
}
