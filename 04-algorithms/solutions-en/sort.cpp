// struct Point { int x, y; }
// Create std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
// Create a function for printing the content of d
// Write 2 comparators:
// pointXCompare that compares only x values of Point
// pointYCompare that compares only y values of Point
// Check if d is sorted according to pointXCompare and pointYCompare
// Use stable_sort to sort d by x
// Use sort to sort d by y

#include <algorithm>
#include <deque>
#include <iostream>

struct Point { int x, y; };

void print(std::deque<Point> const & d) {
    for (auto [x, y] : d) {
        std::cout << "{" << x << ", " << y << "}\t";
    }
    std::cout << '\n';
}

int main() {
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};
    print(d);
    auto pointXCompare = [](Point const & lhs, Point const & rhs){
        return lhs.x < rhs.x;
    };
    auto pointYCompare = [](Point const & lhs, Point const & rhs){
        return lhs.y < rhs.y;
    };
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointXCompare) << '\n';
    std::cout << std::boolalpha << std::is_sorted(d.begin(), d.end(), pointYCompare) << '\n';

    std::sort(begin(d), end(d), pointYCompare);
    print(d);
    std::sort(begin(d), end(d), pointXCompare);
    print(d);
    return 0;
}
