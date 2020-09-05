#pragma once
#include <vector>

class Distance {
public:
    int operator()(std::vector<int>& a, std::vector<int>& b) const;
};
