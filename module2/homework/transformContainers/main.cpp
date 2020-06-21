#include "transformContainers.hpp"

int main() {
    std::list<std::string> lst{
        "Ala", "Kot", "Ma", "Rysia", "Ala",
        "Sierotka", "Kot", "Ma", "Ala"};
    std::deque<int> deq{
        1, 2, 3, 4, 5, 3, 1, 2, 3, 4,
        5, 2, 3, 1, 1, 2, 3, 2, 1, 4};

    auto result = removeDuplicateAndTranformToMap(lst, deq);

    return 0;
}
