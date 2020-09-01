#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> arithmeticAverageFirstVec{1, 2, 3, 4, 7};
    std::vector<int> arithmeticAverageSecondVec{1, 2, 3, 4};

    ArithmeticAverage(arithmeticAverageFirstVec, arithmeticAverageSecondVec);

    std::vector<int> distanceFirstVec{7, 4, 3};
    std::vector<int> distanceSecondVec{17, 6, 2};

    Distance(distanceFirstVec, distanceSecondVec);

    return 0;
}