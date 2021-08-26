#include <iostream>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> first;
    std::vector<int> second;
    int number_of_elements = 0;
    int elements;
    std::cout << "enter the number of elements of the first set: ";
    std::cin >> number_of_elements;

    while (number_of_elements--) {
        std::cin >> elements;
        first.push_back(elements);
    }
    std::cout << "enter the number of elements of the second set: ";
    std::cin >> number_of_elements;
    while (number_of_elements--) {
        std::cin >> elements;
        second.push_back(elements);
    }
    std::cout <<"arithemetic average of all values = "<< ArithmeticAverage(first, second);
    std::cout << '\n';
    std::cout <<"distance between 2 points in n-dimentional space = "<< Distance(first, second);
    std::cout << '\n';
    
    return 0;
}