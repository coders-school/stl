<!-- .slide: data-background="#111111" -->

# Homework

___

## Task 1

Using `std::inner_product`, write a program that computes the arithmetic mean of two `std::vector<int>`.

Input: `{1, 2, 3, 4}` `{1, 2, 3, 4}`
<!-- .element: class="fragment fade-in" -->

Output: `2.5`
<!-- .element: class="fragment fade-in" -->

___

## Task 1 # 2

Then using `std::inner_product`, write a function that will calculate the distance between 2 points for n dimensions.

We define the Euclidean metric in space:
<!-- .element: class="fragment fade-in" -->

`$$ {\mathbb  R}^{n} $$`
<!-- .element: class="fragment fade-in" -->

`$$ d_e(\mathbf x, \mathbf y) = \sqrt{(y_1 - x_1)^2 + \dots + (y_n - x_n)^2} $$`
<!-- .element: class="fragment fade-in" -->

<!-- Oryginal:
```
{\displaystyle \mathbb {R} ^{n}}{\mathbb  R}^{n}
{\displaystyle d_{e}(\mathbf {x} ,\mathbf {y} )={\sqrt {(y_{1}-x_{1})^{2}+\dots +(y_{n}-x_{n})^{2}}},}d_e(\mathbf x, \mathbf y) = \sqrt{(y_1 - x_1)^2 + \dots + (y_n - x_n)^2},
```
-->

Input: `{7, 4, 3}` `{17, 6, 2}`
<!-- .element: class="fragment fade-in" -->

Output: `10.247`
<!-- .element: class="fragment fade-in" -->

___

## Exercise 2

Write a program `advanced_calculator`. This program should have a main loop that will accept input from the user. All calculator commands should be stored in a map that has a key `char` in the form of a character referring to a command (e.g. `+` -> add, `%` -> modulo) and its value should be a function `std::function<>` which is a wrapper for lambda expressions that perform a specific calculation. The program should also return the appropriate error code, if the user gives wrong data, e.g. division by 0 or tries to add `ala + 5`.

Input: `5 + 5` -> operation of adding two numbers 5 and 5 -> output: `10`.
<!-- .element: class="fragment fade-in" -->
Input: `5 ^ 2` -> exponentiation operations -> output: `25`.
<!-- .element: class="fragment fade-in" -->
Input `125 $ 3` -> square root operation (sqrt too long), cubic root of 125 -> output: `5`.
<!-- .element: class="fragment fade-in" -->
___

### Calculator functions

* <!-- .element: class="fragment fade-in" --> Addition, multiplication, division, subtraction, (<code>+</code>, <code>*</code>, <code>/</code>, <code>-</code>),
* <!-- .element: class="fragment fade-in" --> Modulo (<code>%</code>),
* <!-- .element: class="fragment fade-in" --> Calculating the factorial (<code>!</code>),
* <!-- .element: class="fragment fade-in" --> Raising a number to a power (<code>^</code>),
* <!-- .element: class="fragment fade-in" --> Calculate square root (<code>$</code>).
  
___

### Error code

* <!-- .element: class="fragment fade-in" --> <code>Ok</code>,
* <!-- .element: class="fragment fade-in" --> <code>BadCharacter</code> -> If the user specifies a character other than a number.
* <!-- .element: class="fragment fade-in" --> <code>BadFormat</code> -> If the user specifies the wrong command format, e.g. + 5 4, it should be 4 + 5.
* <!-- .element: class="fragment fade-in" --> <code>DivideBy0</code> -> divide by 0.
* <!-- .element: class="fragment fade-in" --> <code>SqrtOfNegativeNumber</code> -> square root of a negative number.
* <!-- .element: class="fragment fade-in" --> <code>ModuleOfNonIntegerValue</code> -> Attempt to calculate% on a non-integer number.

___

### The function to be tested

* `ErrorCode process(std::string input, double* out)`
* This function should continuously receive further data from the user and make appropriate calculations.
* If the data is correct, it will return `ErrorCode:Ok`and in the variable `out` will save the data.
* If any of the errors occur, the function will return it, and in `out` will not save anything.
