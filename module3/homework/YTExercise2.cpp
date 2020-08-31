#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {

  std::vector<int> operationalVector(20);
  std::vector<int> choosenValues = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  std::iota(operationalVector.begin(), operationalVector.end(), 0);
  int middleValuePosition = 10;
  auto middleValueIterator = operationalVector.begin() + middleValuePosition; 

  auto printVector = [](const std::vector<int> &vec) {
    std::for_each(vec.begin(), vec.end(),[](const auto &el) { std::cout << el << ' '; });
    std::cout << std::endl;
  };
  printVector(operationalVector);

  std::stable_partition( operationalVector.begin(), middleValueIterator, [choosenValues](auto &el) {
        if (std::find(choosenValues.begin(), choosenValues.end(), el) != choosenValues.end()) {
          return false;
        } else
          return true;
     });
printVector(operationalVector);
  std::stable_partition(middleValueIterator, operationalVector.end(), [choosenValues](auto &el) {
        if (std::find(choosenValues.begin(), choosenValues.end(), el) != choosenValues.end()) {
          return true;
        } else
          return false;
     });

  printVector(operationalVector);

  return 0;
}