#include <iostream>

#include "arithmeticAverage.hpp"

int main()
{
    std::vector v1 { 1, 2, 3, 4 };
    std::cout << "Aritmethic avarage of two vectors: `{1, 2, 3, 4}` `{1, 2, 3, 4}` = "
              << ArithmeticAverage(v1, v1) << std::endl;

    std::vector<int> first { -5, 4, 2, -5, 2, 4, 6, 7 };
    std::vector<int> second { 3, 5, -2, 6, 7, -3, 6, 9 };
    std::cout << "Aritmethic avarage of two vectors: "
              << "{ -5, 4, 2, -5, 2, 4, 6, 7 } and "
              << "{3, 5, -2, 6, 7, -3, 6, 9} = "
              << ArithmeticAverage(first, second) << std::endl;

    std::cout << "--------------------\n";
    std::vector point1 { 7, 4, 3 };
    std::vector point2 { 17, 6, 2 };
    std::cout << "Distance between two points: {7, 4, 3}, {17, 6, 2}`\n"
              << "(In 3D-dimentional space) = "
              << Distance(point1, point2) << '\n';

    std::vector point3 { 7, 4, 3, 13 };
    std::vector point4 = { 17, 6, 2, -2 };

    std::cout << "Distance between two points: { 7, 4, 3, 13 }, { 17, 6, 2, -2 }`\n"
              << "(In 4D-dimentional space) = "
              << Distance(point3, point4) << '\n';

    return 0;
}
