<!-- .slide: data-background="#111111" -->

# Input/output with files

___

## Input/output library

<img src="img/iostream.gif">

___

## istream, ostream, iostream

We will talk about incoming and outgoing data as data streams. The stream can flow from the program to the outside world through `operator>>` and from the outside world to the program through `operator<<`.

* <!-- .element: class="fragment fade-in" --> istream (<code>std::cin</code>) -> from input stream, i.e. incoming data (e.g. typed from the keyboard).
* <!-- .element: class="fragment fade-in" --> ostream (<code>std::cout</code>, <code>std::cerr</code>, <code>std::clog</code>) -> from output stream, i.e. outgoing data (e.g. displayed on the monitor).
* <!-- .element: class="fragment fade-in" --> iostream -> from input output stream, i.e. data can be both incoming and outgoing.

___

## Data stream

The data stream can come from many sources, we can load it from the user, it can come from some file saved on the disk, etc. This is ensured by an extensive hierarchy of classes, where starting from the base class `ios_base` we reach 3 derivative classes `istream`, `iostream` and `ostream`. Depending on where we want to load the data from, we will use:

* <!-- .element: class="fragment fade-in" --> <code>fstream</code> to handle files,
* <!-- .element: class="fragment fade-in" --> <code>iostream</code> to handle commands read from the keyboard,
* <!-- .element: class="fragment fade-in" --> <code>sstream</code> for convenient operation on <code>std::string</code> as if they were data streams.

Each of these 3 classes inherits from either <code>istream</code> when we want to read data, <code>ostream</code> when we want to save them or <code>iostream</code> when we want to do both.
<!-- .element: class="fragment fade-in" -->

___

## The fourth stream, `streambuf`
<!-- Nie mogłem znaleźć angielskiego odpowiednika od czwartego jeźdzca, jak taki jest to proszę poprawić :) -->

By definition, streambuffer represents output and input devices (like monitor, keyboard, disk, etc.) and allows us to access the low-level interface. It will be rarely used by us 🙂

Among other things, we will use this class to create our own streams. For example, let's look at how to create your own output stream `ostream`.
<!-- .element: class="fragment fade-in" -->

```C++
std::cout << 42 << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost << 24 << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
42
24
```
<!-- .element: class="fragment fade-in" -->

🤔 But why do we need our own stream?
<!-- .element: class="fragment fade-in" -->

___

## Custom data display style

In order not to interfere with the usual stream `std::cout` which is used globally.

```C++
std::cout << M_PI << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost.precision(15);
ost << M_PI << '\n';
std::cout << M_PI << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
3.14159
3.14159265358979
3.14159
```
<!-- .element: class="fragment fade-in" -->

**As a task for those willing, I encourage you to check what `iomanip` library does.**
<!-- .element: class="fragment fade-in" -->

___

<!-- .slide: style="font-size: 0.9em" -->

## Library `fstream`

It is a library that allows us to write and read data from a file. It is a very extensive library, but usually we will only use a few methods. Can you guess what they can do?

* <!-- .element: class="fragment fade-in" --> <code>is_open()</code><span class="fragment fade-in"> -> checks if the file is open (returns <code>bool</code>)</span>
* <!-- .element: class="fragment fade-in" --> <code>put()</code><span class="fragment fade-in"> -> write one character to the file</span>
* <!-- .element: class="fragment fade-in" --> <code>get()</code><span class="fragment fade-in"> -> gets one character from file</span>
* <!-- .element: class="fragment fade-in" --> <code>peek()</code><span class="fragment fade-in"> -> reads a character but does not move the read/write pointer</span>
* <!-- .element: class="fragment fade-in" --> <code>write()</code><span class="fragment fade-in"> -> write data block to file</span>
* <!-- .element: class="fragment fade-in" --> <code>read()</code><span class="fragment fade-in"> -> reads a block of data from a file</span>
* <!-- .element: class="fragment fade-in" --> <code>seekp()</code><span class="fragment fade-in"> -> sets the position of the read/write pointer at a given position in the file</span>
* <!-- .element: class="fragment fade-in" --> <code>tellp()</code><span class="fragment fade-in"> -> informs us about the position of the read/write pointer</span>
* <!-- .element: class="fragment fade-in" --> <code>getline()</code><span class="fragment fade-in"> -> takes characters from the file until it finds the given character (newline by default)</span>

You can treat a pointer in the file as a flashing cursor `|` in text files 🙂 So when we write a text, we always look where this sign is flashing and we know where we are currently modifying the file.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## A bit of Linux

What permissions can we give to a given file?

* <!-- .element: class="fragment fade-in" --> Read
* <!-- .element: class="fragment fade-in" --> Write
* <!-- .element: class="fragment fade-in" --> Execute

We can open files in read only mode, in write only mode or in read-write mode. Additionally, we have the option of setting the cursor when opening the file, erasing all its content if it exists, or creating a file if it does not exist. Let's guess what the different modes mean:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>trunc</code> <span class="fragment fade-in"> -> erase entire content of file,</span>
* <!-- .element: class="fragment fade-in" --> <code>in</code> <span class="fragment fade-in"> -> read mode,</span>
* <!-- .element: class="fragment fade-in" --> <code>out</code> <span class="fragment fade-in"> -> write mode,</span>
* <!-- .element: class="fragment fade-in" --> <code>ate</code> <span class="fragment fade-in"> -> sets <code>seek</code> at the end of the file</span>
* <!-- .element: class="fragment fade-in" --> <code>app</code> <span class="fragment fade-in"> -> sets <code>seek</code> at the end of the file before writing to it. In short, we "stick" new values ​​to the end of the file.</span>
* <!-- .element: class="fragment fade-in" --> <code>binary</code> <span class="fragment fade-in"> -> read/write in binary mode.</span>

___

## Example of a ship's crew logbook entry

```C++
std::fstream diary("Day1.txt", diary.out | diary.app);
// or longer -> std::ifstream::out | std::ifstream::app
if (diary.is_open()) {
    std::cout << "OPENED!\n";
    diary << "Today is my first day on ship, with my crew\n";
    diary << "I'm a little scared!\n";
    diary << "Hope it will be a marvelous adventure.\n";
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

File for writing, adding new data at the end.
Since we treat everything as streams, we can also write to a file using `operatora<<`.
<!-- .element: class="fragment fade-in" -->

___

## Example of reading the ship's crew logbook

```C++
diary.open("Day1.txt", diary.in);
if (diary.is_open()) {
    std::string str;
    while (diary >> str) {
        std::cout << str << ' ';
    }
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

Output: `Today is my first day on ship, with my crew I'm a little scared! Hope it will be a marvelous adventure.`
<!-- .element: class="fragment fade-in" -->

___

## `getline()`

If we want to read data line by line, we can use the function `getline()`.

```C++
diary.open("Day1.txt", diary.in);
if (diary.is_open()) {
    std::string str;
    while (!getline(diary, str, '\n').eof()) {
        std::cout << str << '\n';
    }
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
