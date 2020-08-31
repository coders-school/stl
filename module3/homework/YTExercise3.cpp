#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
std::vector<char> Gather(std::vector<char> vec){
  auto middleValueIterator = std::next(vec.begin(), (vec.size() / 2)); 

  auto printVector = [](const std::vector<char> &vec) {
    std::for_each(vec.begin(), vec.end(),[](const auto &el) { std::cout << el << ' '; });
    std::cout << std::endl;
  };

  auto pred = [](auto& el){
        if (el == '*'){
          return false;
        } else
          return true;
  };
   auto predReversed = [](auto& el){
        if (el == '*'){
          return true;
        } else
          return false;
  }; 
  printVector(vec);
  std::stable_partition( vec.begin(), middleValueIterator, pred);
  printVector(vec);
  std::stable_partition(middleValueIterator, vec.end(), predReversed); 
  printVector(vec);

  return vec;
}
int main() {

  std::vector<char> vec {'*', '@', '*', '#', '@', '^', '*', '(', ')', '*'};
  Gather(vec);

  return 0;
}