#include <algorithm>
#include <iostream>
#include <vector>

bool ChangePosition(std::vector<int>& vec, int value, int new_pos) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it == vec.end()) {
        return false;
    }

    auto position = std::distance(vec.begin(), it);

    if (position > new_pos) {
        std::rotate(vec.begin() + new_pos, vec.begin() + position, vec.begin() + position + 1);
    } else {
        std::rotate(vec.begin() + position, vec.begin() + position + 1, vec.begin() + new_pos + 1);
    }

    for (auto elem : vec) {
        std::cout << elem << std::endl;
    }
    return true;
}

int main(void) {
    std::vector<int> vec = {1, 2, 3, 4};
    std::vector<int> vec2 = {};
    ChangePosition(vec, 4, 1);
    // vec2 = ChangePos
}
