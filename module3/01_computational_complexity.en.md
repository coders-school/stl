<!-- .slide: data-background="#111111" -->

# Computational complexity

___

## Computational complexity

<img src="img/complexity.jpg">

___

## Definition

Computational complexity is about estimating time of algorithm execution. We measure the number of operations, then we look for a function that describes the number of operations depending on the input data. Notation `O` (big O) is an upfront estimate. Since we only want to approximate the value, we omit any kind of constants that are irrelevant to the large input sets labeled as `n`. Therefore `Ο(2n + 5)`, `Ο(2n)` and `Ο(n)` are considered as `O(n)` complexity.

___

## `O(1)` complexity

This is called Constant complexity that is independent of the number of inputs. When calculating the sum of an arithmetic sequence (code below), we do not iterate over all the elements of the array, so the execution time is constant and independent of the size of the array.

```C++
int sum(std::vector<int> vec) {
    if (vec.empty()) {
        return 0;
    }

    return (vec.front() + vec.back()) * vec.size() / 2;
}

int main() {
    std::cout << sum({1, 2, 3, 4, 5, 6}) << std::endl;

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

Output: `21`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## `O(logn)` complexity

Let's imagine that we are looking for the phone number of our friend Albert. We take the phone book and open it in the middle and see that we have a person named Karen. We know that Albert is in the first half of the address book, because the letter K is much further down the alphabet than the letter A. So we open again in the middle of the first half and see that the name Dylan is there. So we repeat our search, finding Bella in the next part, and finally we come across Albert. Such a search, in which we drop half the range every time, is written as `O(logn)` notation.

```C++
std::vector<int> vec{1, 2, 3, 4, 5, 6};
std::cout << std::boolalpha
          << std::binary_search(begin(vec), end(vec), 2) << std::endl
          << std::binary_search(begin(vec), end(vec), 0) << std::endl;
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
true
false
```
<!-- .element: class="fragment fade-in" -->

___

## `O(n)` complexity

Now imagine the situation that we are looking for Zowie's number in the address book. However, we are not going to do a binary search now, we will just see how long it will take when we search person by person. So we start with the letter A and 4 days later we finally find Zowie's number 🙂. Such complexity, where we check each element in turn, is `O(n)` complexity.

<!-- brak miejsca - dzielę na dwa -->
___
<!-- .slide: style="font-size: 0.85em" -->

## `O(n)` complexity  - example

```C++
constexpr size_t samples = 1'000'000'000;
constexpr size_t search_num = 987'654'321;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);

auto start = std::chrono::high_resolution_clock::now();
std::binary_search(begin(vec), end(vec), search_num);
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(logn): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

start = std::chrono::high_resolution_clock::now();
for (const auto el : vec) {
    if (el == search_num) {
        break;
    }
}
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
```

Example Output:
<!-- .element: class="fragment fade-in" -->

```C++
O(logn): 0 ns
O(n): 6'949'430'300 ns
```
<!-- .element: class="fragment fade-in" -->

___

## `O(nlog(n))` Complexity

This is called log-linear complexity, the execution time of which is directly proportional to the product of the input data and their logarithm.
Now imagine this: we are trying to find Albert's number in the phone book, but our colleague played a trick on us and swapped the pages. Now we have to sort it, we are concerned about time, so we want to do it efficiently. Therefore, we tear pages from the phone book one by one and insert them into the new one in correct order. Not only do we have to do such an operation for `n` pages, we still have to put them alphabetically, which will take us `logn` time. Therefore, the whole process is `nlogn`.

___

## `O(nlog(n))` complexity  - example

```C++
constexpr size_t samples = 1'000'000'000;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);
std::random_device rd;
std::mt19937 gen(rd());

//Here our colleague mixed up phone book.
std::shuffle(begin(vec), end(vec), gen);
auto start = std::chrono::high_resolution_clock::now();
std::sort(begin(vec), end(vec));
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(nlogn): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
```
<!-- .element: class="fragment fade-in" -->

Possible output: `O(nlogn): 499'694'684'900 ns`
<!-- .element: class="fragment fade-in" -->

Previous slides output: `O(n): 6'949'430'300 ns`
<!-- .element: class="fragment fade-in" -->

___

## `O(n^x)` complexity

This is called polynomial complexity. Its special and very common case is the square complexity - `O(n^2)` whose execution time is directly proportional to the square of the amount of input data. Now imagine a different situation. We managed to find Albert's number and we also decide to play a trick on our friend, but we want to repay with a vengeance. Therefore, we print a new phone book, but add the number '8' to the beginning of each number. Now our colleague not only needs to improve each page `n` but he also has to check and correct each number basing on the original book. Such computational complexity is `O(n^2)`. An example of `O(n^2)` complexity is the popular bubble sort.

___
<!-- .slide: style="font-size: 0.7em" -->

## `O(n^2)` complexity - example

```C++
constexpr size_t samples = 1'000'000;
std::vector<int> vec(samples);
std::iota(begin(vec), end(vec), 0);
auto start = std::chrono::high_resolution_clock::now();
BubleSort(vec);
auto stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

constexpr size_t samples2 = 10'000'000;  // size is 10 times higher.
std::vector<int> vec2(samples2);
std::iota(begin(vec2), end(vec2), 0);
start = std::chrono::high_resolution_clock::noaw();
BubleSort(vec2);
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";

constexpr size_t samples3 = 100'000'000;  // size is 100 times higher.
std::vector<int> vec3(samples3);
std::iota(begin(vec3), end(vec3), 0);
start = std::chrono::high_resolution_clock::now();
BubleSort(vec3);
stop = std::chrono::high_resolution_clock::now();
std::cout << "O(n^2): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
```
<!-- .element: class="fragment fade-in" -->

Possible output:
<!-- .element: class="fragment fade-in" -->

```C++
O(n^2): 9'974'800 ns
O(n^2): 83'777'600 ns
O(n^2): 810'269'600 ns
```
<!-- .element: class="fragment fade-in" -->

___

## `O(x^n)` complexity

This is called exponential complexity. The execution time increases exponentially with the amount of input data. Imagine a situation where not only the book contains errors that we previously deliberately introduced, but someone decided to print it in a huge circulation and now we have to correct all the books where the time to correct errors was already `n^2`. For such a combination, we say complexity is `n^n`. So it grows exponentially as the number of books (samples) increases. An example would be the DFS (deep-first search) graph, if the input is a matrix. Since we have to go through the whole row every time until we find the item we are interested in, so we will do `n^n` steps. Rarely seen, so it is more of a trivia 🙂

___

## `O(n!)` complexity

This is a factorial complexity, the execution time increases with the rate of factorial with respect to the amount of input data. An example of a problem is the traveling salesman problem from the group of graph algorithms. Find the shortest route starting from city A, passing through all other cities once and going back to city A. For many years, analysts have been puzzling over how to improve this algorithm. We still have room to show off 🙂. I will not paste the code here, but if you are interested, I refer you to search for a traveling salesman algorithm.

___

## `O(n * n!)` complexity

One of the worst scenarios we can do for the algorithm. Imagine a situation where our colleague decided to show us that he was not worth messing with and complains to your supervisor that you messed up the phone book. Now, as a punishment, you have to write a program for a robot arranging books on your friend's shelves in alphabetical order. However, you decide to do the next (worst) trick for him, and you write a robot that will arrange the books randomly, and then check whether they have been arranged correctly, and if not, he would take them again and arrange them again. This way, the robot will compose books for weeks or months, but eventually it will succeed 🙂

Thus, we wrote a perfectly suboptimal sorting algorithm with complexity `O(n * n!)`. An example of such sorting is bogosort.

___
<!-- .slide: style="font-size: 0.65em" -->

## `O(n * n!)` complexity - example

```C++
std::random_device rd;
std::mt19937 generator(rd());

void BogoSort(std::vector<int>& vec) {
    while (!std::is_sorted(vec.begin(), vec.end())) {
        std::shuffle(vec.begin(), vec.end(), generator);
    }
}

int main() {
    constexpr size_t samples = 10;  // Only 10 elements! Try it for 100 :)
    std::vector<int> vec(samples);
    std::iota(begin(vec), end(vec), 0);
    std::shuffle(vec.begin(), vec.end(), generator);
    for (int i = 0; i < 5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        BogoSort(vec);
        auto stop = std::chrono::high_resolution_clock::now();
        std::cout << "O(n * n!): " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << " ns\n";
    }

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

Possible output:
<!-- .element: class="fragment fade-in" -->

```C++
O(n * n!): 35'938'300 ns
O(n * n!): 85'772'000 ns
O(n * n!): 899'885'600 ns
O(n * n!): 2'603'326'600 ns
O(n * n!): 145'608'700 ns
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
