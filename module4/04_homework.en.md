<!-- .slide: data-background="#111111" -->

# Homework

___

## Post-work

* recipes (25 XP)
* adapters (10, 20 lub 30 XP)

+3 XP for delivering each task before 20 September 2020 23:59

___

## Task 1

Write a function that will allow you to save new recipes in a `recipes.txt` file. Return false if you failed to save the recipe.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> The function for 1 argument takes data in <code>std::vector&lt;std::string&gt;</code> which contains the steps of the recipe.
* <!-- .element: class="fragment fade-in" --> The function takes 2 arguments <code>std::list&lt;std::string&gt;</code> containing the name of the ingredients.
* <!-- .element: class="fragment fade-in" --> The function for the 3rd argument takes data in <code>std::deque&lt;std::pair&lt;size_t, char&gt;&gt;</code> containing information about the amount of the ingredient and its representation <code>g</code> -> grams <code>m</code> -> milliliters, <code>s</code> -> glasses.

```cpp
bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

___

## Task1 #2

Input:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<std::string> steps{"Pour 20 grams of sugar into a bowl",
                                "Throw in 1 glass of flour",
                                "Mix thoroughly",
                                "Pour 40ml of rum into the glass",
                                "Drink the rum",
                                "Pour the contents of the bowl"};
std::list<std::string> ingredients{"of sugar", "of flour", "of rum"};
std::deque<std::pair<size_t, char>> amount{
    {20, 'g'},
    {1, 's'},
    {40, 'm'}};
```
<!-- .element: class="fragment fade-in" -->

___

## Task1 # 3

Expected format:
<!-- .element: class="fragment fade-in" -->

```note
Ingredients:
20 grams of sugar,
1 glass(es) of flour,
40ml of rum,

Steps:
1) Pour 20 grams of sugar into a bowl.
2) Throw in 1 glass of flour.
3) Mix thoroughly.
4) Pour 40ml of rum into the glass.
5) Drink the rum.
6) Pour the contents of the bowl.
```
<!-- .element: class="fragment fade-in" -->
___
<!-- .slide: style="font-size: 0.9em" -->

## Task1 #4

Auxiliary functions:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

each vector record should contain a ready-made section of one component, e.g .: `20 grams of sugar` or `1 glass(es) of flour`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

We expect a ready-made format that can be saved immediately.
<!-- .element: class="fragment fade-in" -->

___

## Task 2

Read and write a short note and an example of using the following adapters:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> stack
* <!-- .element: class="fragment fade-in" --> queue
* <!-- .element: class="fragment fade-in" --> priority_queue

I will reward the most interesting essay with 30xp. Second place will get 20xp and third place 10xp.
<!-- .element: class="fragment fade-in" -->
