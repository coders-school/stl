# `ArithmeticAverage() && Distance()`

Implement a `ArithmeticAverage()` function, which takes `const std::vector<int>& first, const std::vector<int>& second` and calculate arithemetic average.

Input: `{1, 2, 3, 4}` `{1, 2, 3, 4}`
Output: `2.5`

Implement a `Distance()` function, which takes `const std::vector<int>& first, const std::vector<int>& second` and calculate distance between 2 points.

Input: `{7, 4, 3}` `{17, 6, 2}`
Output: `10.247`

## Add proper files

Please add proper files. In CMakeLists.txt you can see which files will be compiled.

```cmake
add_executable(${PROJECT_NAME} main.cpp arithmeticAverage.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp arithmeticAverage.cpp)
```

You need to remember about both cpp and hpp file. Don't forget the header guard in hpp!
