<!-- .slide: data-background="#111111" -->

# STL #1

## Sequence containers

### Summary

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What do you remember about sequence containers?

1. <!-- .element: class="fragment fade-in" --> 5 containers
2. <!-- .element: class="fragment fade-in" --> Which of them are cache-friendly?
3. <!-- .element: class="fragment fade-in" --> Operations complexity
4. <!-- .element: class="fragment fade-in" --> Memory consumption
5. <!-- .element: class="fragment fade-in" --> Iterators invalidation

___

<img width="500" src="../img/sequence_containers.png" alt="Kontenery sekwencyjne" class="plain">

___
<!-- .slide: style="font-size: 0.9em" -->

## Homework

### Post-work

This homework may already be a bit of a challenge. Work a lot with the cppreference documentation.

* Read about PGM graphics format - [Wiki ENG](https://en.wikipedia.org/wiki/Netpbm#File_formats). This knowledge may be useful in tasks 3 and 4.
* Task 1 - `removeVowels()` (5 points)
* Task 2 - `lengthSort()` (6 points)
* Task 3a - `compressGrayscale()` (7 points)
* Task 3b - `decompressGrayscale()` (7 points)

#### Bonuses

* 2 points for each task delivered before 06/14/2020 (Sunday) by 23:59
* 3 points for group work for each person in the group. We recommend groups of 3.

#### [Repo tasks](https://github.com/coders-school/stl/tree/master/module1/homework)

___

### Pre-work

* Find on [cppreference.com](https://en.cppreference.com/w/) descriptions of algorithms and read them. See also usage examples.
* Read about computational complexity, e.g. on [Developer Tutorial](https://www.samouczekprogramisty.pl/podstawy-zlozonosci-obliczeniowa/)
* Watch and remember what is [the complexity of operations on each STL containers](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md)

___

## Task 1 - `removeVowels()`

Write a function `removeVowels()` which will accept `std::vector<std::string>` and it will remove all vowels from these phrases.

* Input: `{"abcde", "aabbbccabc", "qwerty"}`
* Output: `{"bcd", "bbccbc", "qwrt"}`

___

## Task 2 - `lengthSort()`

Write a function `lengthSort()`.

It is supposed to accept `std::forward_list<std::string>` and return `std::deque<std::string>`
with the words sorted from the shortest to the longest. If two or more words have the same number of characters
sort them lexicographically.

* Input: `std::forward_list<std::string>{"Three", "One", "Four", "Two"}`
* Output: `std::deque<std::string>{"One", "Two", "Four", "Three"}`

___
<!-- .slide: style="font-size: 0.9em" -->

## Task 3a - `compressGrayscale()`

The task will be to compress a grayscale image with dimensions of 240x160 pixels. Each pixel can have a value from 0 (black) to 255 (white). The larger the value, the lighter the hue the pixel represents. Example of a small 6x4 pixel image:

<img width="300px" src="../img/example.png" alt="Przykład pikseli" class="plain">

```cpp []
255 255 0   255 0   255   // 0xFF 0xFF 0x00 0xFF 0x00 0xFF
128 0   128 0   128 0     // 0x80 0x00 0x80 0x00 0x80 0x00
64  64  64  64  64  64    // 0x40 0x40 0x40 0x40 0x40 0x40
255 192 128 64  0   0     // 0xFF 0xB0 0x80 0x40 0x00 0x00
```

To get a PGM file from it, you only need to add the appropriate header.

___
<!-- .slide: style="font-size: 0.9em" -->

## Task 3a - `compressGrayscale()` - description

Write a function `compressGrayscale()`.
It should take one argument with `std::array<std::array<uint8_t, 240>, 160>` type which specifies the distribution of shades of gray in a 2D image (which we will refer to as a bitmap) and returns `std::vector<std::pair<uint8_t, uint8_t>>` containing a compressed bitmap.

Compression should proceed as follows:

* We draw the bitmap from the upper left corner going right, then a level below.
* If the same color occurs more than 1 time next to each other, the function should drop into `std::vector<>` the value of this color (a number between 0 and 255) as the first element of the pair and the number of its repetitions as the second element of the pair.
* If there are different shades next to each other, the function should fill `std::vector<> ` with hue value and the number of occurrences equal to 1 (in this case, we worsen the optimization, because we store 2x as much data, but most often the same colors are placed next to each other).

___
<!-- .slide: style="font-size: 0.9em" -->

## Task 3a - `compressGrayscale()` - example

```cpp []
input: {{0 0 0 1 1 2 3 0 0 0},
        {0 0 4 4 4 1 1 1 1 1},
        {2 2 2 2 2 1 2 2 2 2}}
output: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2}, {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}
```

In the case of the above conversion, instead of 30 bytes (dimensions 10x3) we will use 22 (11x2). So we compressed the data by 26.7%.

We don't care yet how `uint_8` will be converted to color. It is important in this task to practice using containers and performing various operations on them.

Volunteers can also refactor (i.e. write more readily, improve) tests so that the complicated loops that fill the arrays are a universal function that can be called in current and future tests (similar to the function `getBitmap()`).
After extracting and refactoring the generator function, try to add cases for 1/16, 1/32 and 1/64 of the map.

___
<!-- .slide: data-background="img/jjfile1_002.png" -->

___

## Task 3b - `decompressGrayscale()`

Write a function `decompressGrayscale()` which will decompress the compressed image in task 3 using the function `compressGrayscale()`.

As an argument of the function `decompressGrayscale()` will accept `std::vector<std::pair<uint8_t, uint8_t>>` and it will return `std::array<std::array<uint8_t, 240>, 160>` and perform operations to reconstruct the original bitmap format.

___

## ASCII art

For those willing (without points), we also recommend writing a function `printMap()` which will display the map.
By default `std::cout` will treat `uint8_t` as `unsigned char` therefore you can write a map from ASCII codes.

<img width="450px" src="../img/ascii_art_mug.jpg" alt="ASCII art z kubkiem" class="plain">

___

Willing people can also refactor the tests, so that the map checking function is generic (adequately to the function `expectBitmap()`.
After refactoring the check function, try to add cases for 1/16, 1/32 and 1/64 of the map as well.
