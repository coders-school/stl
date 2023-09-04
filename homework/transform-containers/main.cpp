#include "mapMaking.hpp"

std::list<std::string> list{
    "Ala", "Kot", "Ma", "Rysia", "Ala",
    "Sierotka", "Kot", "Ma", "Ala"};
std::deque<int> deque{
    1, 2, 3, 4, 5, 3, 1, 2, 3, 4,
    5, 2, 3, 1, 1, 2, 3, 2, 1, 4};
int main() {
    removeDuplicateAndTranformToMap(list, deque);
}