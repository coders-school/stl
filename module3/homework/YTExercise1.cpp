#include <algorithm>
#include <iostream>
#include <vector>

bool moveValue(std::vector<int> &vector, int value, int newPosition);
void printVector(std::vector<int> &vec);
int main() {
  std::vector<int> vector = {3, 7, 4, 9, 5, 8, 4, 2, 1};
  printVector(vector);
  moveValue(vector, 2, 2);

  return 0;
}

bool moveValue(std::vector<int> &vector, int value, int newPosition) {

  auto it = find(vector.begin(), vector.end(), value);

  // std::rotate(vector.begin(), vector.begin()+1, vector.end()-2);
  // printVector(vector);

  if (it == vector.cend()) {
    std::cout << "Value not found" << std::endl;
    return false;
  } else {
    int actualPosition =
        std::distance(vector.begin(), it); // counting from zero

    if (newPosition > actualPosition) {
      std::rotate(vector.begin() + actualPosition,
                  vector.begin() + actualPosition + 1,
                  vector.begin() + newPosition + 1);
      std::cout << "Actual Position: " << actualPosition << std::endl;
      std::cout << "Vector rotated new > actual" << std::endl;
      printVector(vector);
      return true;
    } else if (newPosition < actualPosition) {
      std::rotate(vector.begin() + newPosition,
                  vector.begin() + actualPosition,
                  vector.begin() + actualPosition + 1);
      std::cout << "Actual Position: " << actualPosition << std::endl;
      std::cout << "Vector rotated new < actual" << std::endl;
      printVector(vector);
      return true;
    } else if (newPosition == actualPosition) {
      std::cout << "New == actual" << std::endl;
      return false;
    }
  }
  return false;
}

void printVector(std::vector<int> &vec) {
  for (int i : vec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}