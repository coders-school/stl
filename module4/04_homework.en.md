<!-- .slide: data-background="#111111" -->

# Homework

___

## Task 1

Write a function that will allow you to save new recipes in a file `recipes.txt`. Return false if you failed to save the recipe.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> The function for 1 argument takes data in <code>std::vector&lt;std::string&gt;</code>which contains the steps of the recipe.
* <!-- .element: class="fragment fade-in" --> The function takes 2 arguments <code>std::list&lt;std::string&gt;</code> containing the name of the ingredients.
* <!-- .element: class="fragment fade-in" --> The function for the 3rd argument takes data in <code>std::deque&lt;std::pair&lt;size_t, char&gt;&gt;</code> containing information about the amount of the ingredient and its representation <code>g</code> -> we play <code>m</code> -> milliliters, <code>s</code> -> glasses.

```C++
bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

___

## Task1 # 2

Input:
<!-- .element: class="fragment fade-in" -->

```C++
std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                "Dorzucić 1 szklankę mąki",
                                "Dokładnie wymieszać",
                                "Nalać 40ml rumu do kieliszka",
                                "Wypić kieliszek",
                                "Wysypać zawartość miski"};
std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
std::deque<std::pair<size_t, char>> amount{
    {20, 'g'},
    {1, 's'},
    {40, 'm'}};
```
<!-- .element: class="fragment fade-in" -->

<!-- nie mieściło się, dzielę na dwa -->
___

## Task1 # 3

Expected format:
<!-- .element: class="fragment fade-in" -->

```note
Składniki:
20 gram cukru,
1 szklanka(i) mąki,
40ml rumu,

Kroki:
1) Wsypać do miski 20 gram cukru.
2) Dorzucić 1 szklankę mąki.
3) Dokładnie wymieszać.
4) Nalać 40ml rumu do kieliszka.
5) Wypić kieliszek.
6) Wysypać zawartość miski.
```
<!-- .element: class="fragment fade-in" -->
___
<!-- .slide: style="font-size: 0.9em" -->

## Task1 # 4

Auxiliary functions:
<!-- .element: class="fragment fade-in" -->

```C++
std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

each vector record should contain a ready-made section of one component, e.g .: `20 gram cukru` or `1 szklanka(i) mąki`.
<!-- .element: class="fragment fade-in" -->

```C++
std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

We expect a ready-made format that can be saved immediately.
<!-- .element: class="fragment fade-in" -->

___

## Exercise 2

Read and write a short note and an example of using the following adapters:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> stack
* <!-- .element: class="fragment fade-in" --> queue
* <!-- .element: class="fragment fade-in" --> priority_queue

I will reward the most interesting study with 30xp. Second place will get 20xp and third place 10x.
<!-- .element: class="fragment fade-in" -->
