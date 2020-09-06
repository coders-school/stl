#pragma once
#include <vector>

class Distance {
public:
    float operator()(std::vector<int>& a, std::vector<int>& b) const;
};
