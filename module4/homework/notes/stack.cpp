#include <iostream>
#include <stack>

int main() {
    std::stack<int> stackContainer;

    stackContainer.push(5);
    stackContainer.push(10);
    std::cout << stackContainer.top() << '\n';  // 10

    stackContainer.top() *= 10;
    std::cout << stackContainer.top() << '\n';  // 100

    stackContainer.top() = 15;
    std::cout << stackContainer.top() << '\n';  // 15

    stackContainer.pop();
    std::cout << stackContainer.top() << '\n';  // 5

    stackContainer.push(8);
    std::cout << stackContainer.size() << '\n';  // 2

    stackContainer.pop();
    stackContainer.pop();
    std::cout << stackContainer.size() << '\n';  // 0
    if (stackContainer.empty()) {
        std::cout << "Stack is empty" << '\n';  // "Stack is empty"
    }

    return 0;
}
