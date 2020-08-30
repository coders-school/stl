<!-- .slide: data-background="#111111" -->

# Iteratory

___

## Krótka powtórka #1

Iterator jest to obiekt, który wskazuje na dany element w kontenerze. W zależności od typu możemy na nim wykonywać różne operacje, np: inkrementować go `operator++`, dekrementować `operator--` lub wykonywać operacje typu `it += 6`. W celu odwołania się do wskazywanego elementu przez iterator używamy `operator*` czyli dereferencji (jak na zwykłych wskaźnikach).

___

## Krótka powtórka #2

Każdy kontener ma 2 końce. Na jeden z nich wskazuje `begin()`, a na drugi `end()`.

<image src="img/iterator.png">

___

## Krótka powtórka #3

Dla niektórych kontenerów możemy także pobrać odwrotny iterator (ang. reverse iterator) umożliwiający nam przejście wstecz przez zakres.

<image src="img/rev_iterator.gif">

___

## Krótka powtórka #4

Jeżeli nie chcemy modyfikować danych wskazywanych przez iterator zastosujemy opcję z przedrostkiem `c` pochodzącym od słowa `constant`.

* <!-- .element: class="fragment fade-in" --> <code>cbegin()</code>
* <!-- .element: class="fragment fade-in" --> <code>cend()</code>
* <!-- .element: class="fragment fade-in" --> <code>crbegin()</code>
* <!-- .element: class="fragment fade-in" --> <code>crend()</code>

___

## Hierarchia iteratorów

<image src="img/iterator_categories.gif" height="350px">

Pytanie, co powinno się znaleźć w miejscu `forward_iterator`?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::forward_list<T></code>
* <!-- .element: class="fragment fade-in" --> <code>std::unordered_set<T></code>
* <!-- .element: class="fragment fade-in" --> <code>std::unordered_map<T></code>

___

### "Najbiedniejsze" iteratory, czyli input i output

Input iterator: pochodzi np. ze strumienia `std::istream`, czyli znanego nam `std::cin`. Raz wczytane dane znikają, nie możemy ich ponownie odczytać. Mamy możliwość tylko jednorazowego przejścia przez dane. Innym słowem jak tylko odczytamy jakąś daną nasz operator od razu jest inkrementowany.

```C++
int a;
int b;
std::cin >> a >> b;
```
<!-- .element: class="fragment fade-in" -->

Output iterator: pochodzi np. ze strumienia `std::ostream`, czyli znanego nam `std::cout`. Raz wypisane dane znikają, nie możemy ich ponownie wyświetlić, musimy ponownie podać dane.
<!-- .element: class="fragment fade-in" -->

```C++
int a;
int b;
std::cin >> a >> b;
std::cout << a << ' ' << b;
```
<!-- .element: class="fragment fade-in" -->
___

### Pytanie

Jakie mamy dostępne operatory dla input iterator, a jakie dla output iterator?

Input iterator:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>

Output iterator:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator()++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>

___

### Forward iterator

Jest to iterator, który umożliwia nam wielokrotne przejście danego zakresu w jedną stronę (w przód).

```C++
std::forward_list<int> list {1, 2, 3, 4, 5};
for (auto it = list.begin() ; it != list.end() ; ++it) {
    std::cout << *it << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5`
<!-- .element: class="fragment fade-in" -->

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>

___
<!-- .slide: style="font-size: 0.85em" -->

### Bidirectional iterator

Jest to iterator, który umożliwia nam wielokrotne przejście danego zakresu w obie strony (w przód i tył).

```C++
std::list<int> list{1, 2, 3, 4, 5};
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << ' ';
}
auto last = std::prev(list.end());
for (auto it = last; it != std::prev(list.begin()); --it) {
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5 5 4 3 2 1`
<!-- .element: class="fragment fade-in" -->

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator--</code>

___

### Random Access iterator

Jest to iterator, który umożliwia nam wielokrotne przejście danego zakresu w obie strony (w przód i tył), a także dostęp do dowolnego obiektu.

```C++
std::vec<int> vec{1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << ' ';
}
auto last = std::prev(vec.end());
for (auto it = last; it != std::prev(vec.begin()); --it) {
    std::cout << *it << ' ';
}
std::cout <<  vec[3];
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5 5 4 3 2 1 3`
<!-- .element: class="fragment fade-in" -->

___

### Random Access iterator

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator--</code>
* <!-- .element: class="fragment fade-in" --> <code>operator<</code>
* <!-- .element: class="fragment fade-in" --> <code>operator<=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator></code>
* <!-- .element: class="fragment fade-in" --> <code>operator>=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator+</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-</code>
* <!-- .element: class="fragment fade-in" --> <code>operator[]</code>

___

### Ciekawostka

W C++ 17 wprowadzono jeszcze typ: `ContiguousIterator`. Zawiera on wszystkie cechy Random Access iterator oraz zapewnia, że wszystkie dane są ułożone w jednym miejscu w pamięci.

___

## Q&A
