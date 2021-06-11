# `removeVowels()`

Implement a `removeVowels()` function, which takes `std::vector<std::string>` and removes all vowels from all strings.

Input: `{"abcde", "aabbbccabc", "qwerty"}`
Output: `{"bcd", "bbccbc", "qwrt"}`

## Add proper files

Please add proper files. In CMakeLists.txt you can see which files will be compiled.

```cmake
add_executable(${PROJECT_NAME} main.cpp vowel.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp vowel.cpp)
```

You need to remember about both cpp and hpp file. Don't forget the header guard in hpp!
