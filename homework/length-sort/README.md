# `lengthSort()`

Implement `lengthSort()` function. It should take `std::forward_list<std::string>` and return `std::deque<std::string>` with words sorted from the shortest to the longest. If two or more words has the same amount of characters they should be sorted lexicographically.

* Input: `std::forward_list<std::string>{"Three", "One", "Four", "Two"}`
* Output: `std::deque<std::string>{"One", "Two", "Four", "Three"}`

## Add proper files

Please add proper files. In CMakeLists.txt you can see which files will be compiled.

```cmake
add_executable(${PROJECT_NAME} main.cpp sort.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp sort.cpp)
```

You need to remember about both cpp and hpp file. Don't forget the header guard in hpp!
