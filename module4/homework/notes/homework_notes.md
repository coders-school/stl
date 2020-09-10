---
title: STL Homework - Notes
---

## std::stack
std::stack is a container adapter which have LIFO (last in first out) data structure. We can access only it's top element.

std::stack is available after adding `#include <stack>` to your code.

Possible operations:
 * push() - inserts new element at the top
 * pop() - removes the element at the top
 * emplace() - constructs element at the top
 * swap() - swaps the content
 * empty() - checks if container is empty
 * size() - returns number of elements on stack
 * top() - gives access to top element

Usage example:
```cpp
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
```

It is also possible to create new stack container based on your previously created one. It can be done for std::vector, std::list and std::deque.


## std::queue
std::queue is a container adapter which have FIFO (first in first out) data structure. We can access only two it's elements - first and last element.

std::queue is available after adding `#include <queue>` to your code.

Possible operations:
 * push() - inserts new element at the top
 * pop() - removes the element at the top
 * empty() - checks if container is empty
 * size() - returns number of elements on stack
 * front() - gives access to the first element
 * back() - gives access to the last element
 * swap() - swaps the content of two queues

Usage example:
```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> queueContainer;

    queueContainer.push(5);
    queueContainer.push(10);
    std::cout << queueContainer.front() << '\n';  // 5
    std::cout << queueContainer.back() << '\n';   // 10

    queueContainer.front() *= 10;
    std::cout << queueContainer.front() << '\n';  // 50

    queueContainer.back() = 15;
    std::cout << queueContainer.back() << '\n';  // 15

    queueContainer.pop();
    std::cout << queueContainer.front() << '\n';  // 15

    queueContainer.push(8);
    std::cout << queueContainer.size() << '\n';  // 2

    queueContainer.pop();
    queueContainer.pop();
    std::cout << queueContainer.size() << '\n';  // 0
    if (queueContainer.empty()) {
        std::cout << "Queue is empty" << '\n';  // "Stack is empty"
    }

    return 0;
}
```

## std::priority_queue
std::priority_queue is also a container adapter which have FIFO (first in first out) data structure. We can access only two it's elements - first and last element.

std::priority_queue is available after adding `#include <queue>` to your code.

In addition to normal queue, in priority queue we are able to modify container using compare functor. The default one which is used keeps biggest number at the beginning.

Possible operations:
 * push() - inserts new element at the top
 * pop() - removes the element at the top
 * empty() - checks if container is empty
 * size() - returns number of elements on stack
 * top() - returns value of the top element
 * swap() - swaps the content of two queues

Usage example:
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> queueContainer;

    queueContainer.push(10);
    queueContainer.push(5);
    std::cout << queueContainer.top() << '\n';  // 10

    queueContainer.pop();
    std::cout << queueContainer.top() << '\n';  // 5

    queueContainer.push(8);
    std::cout << queueContainer.size() << '\n';  // 2

    queueContainer.pop();
    queueContainer.pop();
    std::cout << queueContainer.size() << '\n';  // 0
    if (queueContainer.empty()) {
        std::cout << "Priority queue is empty" << '\n';  // "Stack is empty"
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> queueContainer2;

    for (int n : {-5, -9, 1, 8, 2, 12415, -124314})
        queueContainer2.push(n);

    while (!queueContainer2.empty()) {
        std::cout << queueContainer2.top() << ", ";
        queueContainer2.pop();
    }  // -124314, -9, -5, 1, 2, 8, 12415,

    return 0;
}

```
