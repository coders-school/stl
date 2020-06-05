#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<int, 10> arr;
    arr.fill(5);
    arr[3] = 3;
    std::array<int, arr.size()> arr_sec;
    arr_sec.swap(arr);
    

    for (auto element : arr) {
        std::cout << element <<' ';
    }
    std::cout<<"\n";
    for (auto element : arr_sec) {
        std::cout << element <<' ';
    }

}
