#include "arithmeticAverage.hpp"

int main(int argc, char const* argv[]) {
    std::vector<int> first{-5, 4, 2, -5, 2, 4, 6, 7};
    std::vector<int> second{3, 5, -2, 6, 7, -3, 6, 9};

    double arth_average = ArithmeticAverage(first, second);

    std::cout << arth_average << '\n';

    return 0;
}
