<!-- .slide: data-background="#111111" -->

# Zadanie domowe

___

## Post-work

* recipes (25 XP)
* adapters (10, 20 lub 30 XP)

+3 XP za dostarczenie każdego zadania przed 20.09.2020 23:59

___

## Zadanie 1

Napisz funkcję, która umożliwi zapisywanie nowych przepisów w pliku `recipes.txt`. Zwróć false, jeżeli nie uda się zapisać przepisu.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Funkcja za 1 argument przyjmuje dane w <code>std::vector&lt;std::string&gt;</code>, który zawiera kolejne kroki przepisu.
* <!-- .element: class="fragment fade-in" --> Funkcja za 2 argument przyjmuje <code>std::list&lt;std::string&gt;</code> zawierającą nazwę składników.
* <!-- .element: class="fragment fade-in" --> Funkcja za 3 argument przyjmuje dane w <code>std::deque&lt;std::pair&lt;size_t, char&gt;&gt;</code> zawierające informacje o ilości składnika i jego reprezentacji <code>g</code> -> gramy <code>m</code> -> mililitry, <code>s</code> -> szklanki.

```cpp
bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie1 #2

Input:
<!-- .element: class="fragment fade-in" -->

```cpp
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

___

## Zadanie1 #3

Oczekiwany format:
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

## Zadanie1 #4

Pomocnicze funkcje:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

każdy rekord wektora powinien zawierać gotową sekcję jednego składnika np: `20 gram cukru` lub `1 szklanka(i) mąki`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
```
<!-- .element: class="fragment fade-in" -->

Oczekujemy gotowego formatu, który można od razu zapisać.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 2

Poczytaj i stwórz krótką notatkę oraz przykład wykorzystania następujących adapterów:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> stack
* <!-- .element: class="fragment fade-in" --> queue
* <!-- .element: class="fragment fade-in" --> priority_queue

Najciekawsze opracowanie nagrodzę 30xp. Drugie miejsce otrzyma 20xp a trzecie 10xp.
<!-- .element: class="fragment fade-in" -->
