---
title: STL Homework 2 Notes
output: pdf_document
---

## std::stack
std::stack is a container adapter which have LIFO (last in first out) data structure.
std::stack is available after adding `#include <stack>` to your code.

Possible operations:
 * push - inserts new element at the top
 * pop - removes the element at the top
 * emplace - constructs element at the top
 * swap - swaps the content
 * empty - checks if container is empty
 * size - returns number of elements on stack
 * top - gives access to top element

Usage example:
```cpp
#include <iostream>
#include <stack>

std::stack<int> stack;

stack.push(5);
stack.push(10);
std::cout << stack.top() << '\n'; //10

stack.top() *= 10;
std::cout << stack.top() << '\n'; //100

stack.top() = 15;
std::cout << stack.top() << '\n'; //15

stack.pop();
std::cout << stack.top() << '\n'; //5


```


## std::queue


## std::priority_queue
