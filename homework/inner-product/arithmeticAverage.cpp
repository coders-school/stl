#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> Union;

    std::merge(first.begin(), first.end(), 
               second.begin(), second.end(), 
               std::back_inserter(Union));
    // std::cout.precision(4);
    // for(auto el : Union) {
    //     std::cout << el << ' ';
    // }
    double sum = std::accumulate(Union.begin(), Union.end(), 0);
    return sum / Union.size();
}
double Distance(const std::vector<int>& first, const std::vector<int>& second) {
    std::vector<int> vec;

    std::copy(first.begin(), first.end(),
              std::back_inserter(vec));
    std::transform(begin(vec), end(vec),
                   begin(second), begin(vec),
                   [](auto first, auto second) {
                       return  pow((first - second),2);
                   });
    double sum = std::accumulate(vec.begin(), vec.end(), 0);
    return sqrt(sum);
}
