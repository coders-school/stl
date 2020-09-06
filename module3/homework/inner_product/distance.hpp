#pragma once
#include <vector>

class Distance {
public:
    float operator()(std::vector<int>& lhs, std::vector<int>& rhs) const;
};
