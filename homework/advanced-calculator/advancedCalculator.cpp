#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <regex>
#include <unordered_map>
#include <variant>

ErrorCode process(std::string input, double* out) {
    std::unordered_map<char, std::variant<std::function<double(double, double)>,
                                          std::function<int(int, int)>,
                                          std::function<double(double)>>> operations;
    operations.emplace('+', std::function([](double l, double r) {
        return l + r;
    }));
    operations.emplace('-', std::function([](double l, double r) {
        return l - r;
    }));
    operations.emplace('*', std::function([](double l, double r) {
        return l * r;
    }));
    operations.emplace('/', std::function([](double l, double r) {
        return l / r;
    }));
    operations.emplace('%', std::function([](int l, int r) {
        return l % r;
    }));
    operations.emplace('!', std::function([](double n) {
        return std::tgamma(n + 1);
    }));
    operations.emplace('^', std::function([](double l, double r) {
        return std::pow(l, r);
    }));
    operations.emplace('$', std::function([](double l, double r) {
        return std::pow(l, 1 / r);
    }));
}
