#include <iostream>
#include <array>

int main (){
    std::cout << "Array 1: \n";
    std::array<int, 10>arr;
    arr.fill(5);
    arr[3] = 3;
    std::array<int, 10>arr2;
    std::swap(arr, arr2);
    for (const auto& it : arr){
        std::cout << " " << it;
    }
        for (const auto& it : arr2){
        std::cout << " " << it;
    }
    
    return 0;

}