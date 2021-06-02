<!-- .slide: data-background="#111111" -->

# `std::forward_list<T>`
<!-- .element: style="font-size: 2.3em" -->

## Lista jednokierunkowa

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::forward_list<T>`

* <!-- .element: class="fragment fade-in" --> Nie jest cache-friendly
  * <!-- .element: class="fragment fade-in" --> Elementy są porozrzucane po pamięci
* <!-- .element: class="fragment fade-in" --> Każdy element (węzeł -> ang. node) posiada wskaźnik na następny element
* <!-- .element: class="fragment fade-in" --> Typ <code>T</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ.
* <!-- .element: class="fragment fade-in" --> Dodawanie nowego elementu jest proste. Program zaalokuje potrzebną pamięć dla węzła i przekaże poprzedniemu węzłowi (o ile istnieje) informacje o swoim położeniu.
* <!-- .element: class="fragment fade-in" --> Usuwanie elementu jest szybkie, program zwalnia pamięć zaalokowaną dla danego węzła oraz informuje o tym poprzedni węzeł, aby mógł zmienić swój wskaźnik.
* <!-- .element: class="fragment fade-in" --> Wyszukiwanie węzła (np. do usunięcia lub wstawienia za nim nowego elementu) jest już kosztowne, gdyż musimy się przeiterować kolejno przez wszystkie węzły, aż odnajdziemy poszukiwany (nawet, jeżeli dokładnie wiemy, że jest on np. 40-tym elementem listy)

___
<!-- .slide: style="font-size: 0.55em" -->

## Operacje na `std::forward_list<T>`

| Operacje                                                              | Metody                                                                                                                                                                                                                                                                                               |
| :-------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| dodawanie elementu                                                    | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">push_front()</code>, <code class="fragment highlight-green">emplace_front()</code>,<br/><code class="fragment highlight-blue">insert_after()</code>, <code class="fragment highlight-blue">emplace_after()</code> |
| modyfikowanie/dostęp do elementu                                      | <!-- .element: class="fragment fade-in" --> <span class="fragment highlight-red">tylko poprzez iteratory</span>                                                                                                                                                                                      |
| pierwszy/ostatni element                                              | <!-- .element: class="fragment fade-in" -->  <code>front()</code>, <span class="fragment highlight-red">brak <code>back()</code></span>                                                                                                                                                              |
| rozmiar                                                               | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">brak <code>size()</code></span>                                                                                                                                                                                    |
| iterator wskazujący element przed <code>begin()</code>                | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-blue">before_begin()</code>                                                                                                                                                                                             |
| odwrócony (ang. reverse) iterator                                     | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">brak <code>rbegin()</code> i <code>rend()</code></span>                                                                                                                                                            |
| stały iterator                                                        | <!-- .element: class="fragment fade-in" -->  <code>cbegin()</code>, <code>cend()</code></code>, <code class="fragment highlight-blue">cbefore_begin()</code>                                                                                                                                        |
| wyczyszczenie kontenera                                               | <!-- .element: class="fragment fade-in" -->  <code>clear()</code>                                                                                                                                                                                                                                    |
| posortowanie listy                                                    | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-green">sort()</code>                                                                                                                                                                                                    |
| odwrócenie listy                                                      | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-green">reverse()</code>                                                                                                                                                                                                 |
| usunięcie duplikatów                                                  | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-green">unique()</code>                                                                                                                                                                                                  |
| usunięcie elementów z listy                                           | <!-- .element: class="fragment fade-in" -->  <code>remove()</code>                                                                                                                                                                                                                                   |
| wymazanie elementów z pamięci                                         | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-blue">erase_after()</code>                                                                                                                                                                                              |
| wymazanie elementów z pamięci używając <code>&lt;algorithm&gt;</code> | <!-- .element: class="fragment fade-in" -->  <code>erase()</code>                                                                                                                                                                                                                                    |

___

## `std::forward_list<T>::insert_after()` && `std::forward_list<T>::before_begin()`
<!-- .element: style="font-size: 1.2em" -->

Lista jednokierunkowa umożliwia nam wstawianie elementu za konkretnym węzłem.
Jeżeli chcemy wstawić wartość na początku listy używając metody `insert_after()`, musimy podać jej specjalny iterator `before_begin`, który wskazuje element przed pierwszym węzłem listy.
W ten sposób, metoda `insert_after()` wstawi pożądaną przez nas wartość dokładnie jako pierwszy element listy.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5, 6};
list.insert_after(list.begin(), 10);
print(list);
list.insert_after(list.before_begin(), 0);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```text
1 10 2 3 4 5 6
0 1 10 2 3 4 5 6
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::remove()`

Ponieważ lista zawiera swoją metodę `remove()`, nie musimy już korzystać z `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::forward_list<T>::erase_after()`
<!-- .element: style="font-size: 1.3em" -->

`erase_after()` służy do usunięcia węzłów od miejsca za elementem wskazanym przez pierwszy iterator do momentu wskazanego przez drugi iterator (bez elementu wskazywanego przez niego).
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
auto it = list.begin();
std::advance(it, 4);
std::cout << "it: " << *it << std::endl;

auto it2 = list.begin();
std::advance(it2, 7);
std::cout << "it2: " << *it2 << std::endl;

list.erase_after(it, it2);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```text
it: 5
it2: 8
1 2 3 4 5 8 9 10
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

* Znajdź dokumentację `std::forward_list` na [cppreference.com](https://en.cppreference.com)
* Skorzystaj z kodu z zadania z `std::list`
* Stwórz listę jednokierunkową zawierającą elementy od 0 do 5
* Wyświetl listę
* Usuń 3 element z listy
* Dodaj na początek i koniec listy wartość 10
* Wyświetl listę
* Dodaj na czwartej pozycji liczbę 20
* Wyświetl listę

___

## Q&A
