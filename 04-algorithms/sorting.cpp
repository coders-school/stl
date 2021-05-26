#include <deque>
#include <iostream>
#include <algorithm>

struct Point {
    int x;
    int y;
};

void printPoints(std::deque<Point> const & d) {
    for (auto [x, y] : d) {
        std::cout << "{" << x << ", " << y << "}, \t";
    }
    std::cout << '\n';
}

int main() {
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
    printPoints(d);
    auto pointXCompare = [](Point const & lhs, Point const & rhs) {
        return lhs.x < rhs.x;
    };
    auto pointYCompare = [](Point const & lhs, Point const & rhs) {
        return lhs.y < rhs.y;
    };
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointXCompare) << '\n';
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointYCompare) << '\n';

    std::stable_sort(d.begin(), d.end(), pointXCompare);
    printPoints(d);

    std::sort(d.begin(), d.end(), pointYCompare);
    printPoints(d);
    return 0;
}
