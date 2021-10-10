#include "arithmeticAverage.hpp"
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <stdexcept>

double ArithmeticAverage(const std::vector<int> &x, const std::vector<int> &y)
{
    using namespace std;

    auto result = transform_reduce(begin(x), end(x), begin(y), 0.0, plus<>{}, plus<>{}) / (x.size() + y.size());
    return result;
};
double Distance(const std::vector<int> &x, const std::vector<int> &y)
{
    using namespace std;
    vector<double> v;
    v.reserve(x.size());
    if (x.size() != y.size())
    {
        throw std::length_error("vector x, y has different size");
    }
    
    for (int i = 0; i < x.size(); i++)
    {
        v.push_back(pow(x[i] - y[i], 2));
    }

    auto const sum = reduce(begin(v), end(v));

    return sqrt(sum);
};