#pragma once
#include <vector>

class ArithmeticAverage {
public:
    float operator()(std::vector<int>& lhs, std::vector<int>& rhs) const;
};
