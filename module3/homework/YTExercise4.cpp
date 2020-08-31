#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

std::vector<int> GetVec(size_t count){
    std::vector<int> vector(count);
    std::iota(vector.begin(), vector.end(), 10);
    return vector;
}

int Multiply(std::vector<int> vec){
    int result = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    return result; 
}


int main(){

    auto printVector = [](const std::vector<int> &vec) {
    std::for_each(vec.begin(), vec.end(), [](const auto &el) { std::cout << el << ' '; });
    std::cout << std::endl;
    };

    std::vector<int> vec = GetVec(7);
    int MultiplicationResult = Multiply(vec);
    printVector(vec);
    std::cout << "Multiplication Result: " << MultiplicationResult << std::endl;
    return 0;
}
