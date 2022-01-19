#include "arithmeticAverage.hpp"

int main()
{
    std::vector<int> vector1{1, 2, 3, 4};
    std::vector<int> vector2{1, 2, 3, 4};
    auto resultAA = ArithmeticAverage(vector1, vector2);
    std::vector<int> vector3{7,4,3};
    std::vector<int> vector4{17,6,2};
    auto resultD = Distance(vector3, vector4);
}
