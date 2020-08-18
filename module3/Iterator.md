# Iteratory

___

## Krótka powtórka #1

Iterator jest to obiekt, który wskazuje na dany element w kontenerze, w zależnośći od typu możemy na nim wykonywać różne operację, np: inkrementować go `operator++` dekrementować `operator--` lub wykonywac operacje typu `it += 6`. W celu odwołania się do wskazywanego elementu przez iterator używamy `operator*` czyli dereferencji (jak na zwykłych wskaźnikach).

___

## Krótka powtórka #2

Każy kontener ma 2 końce. Na jeden z nich wskazuje `begin()` na drugi `end()`

<image src="http://i.stack.imgur.com/oa3EQ.png">

___

## Krótka powtórka #3

Dla każdego kontenera możemy także pobrać odwrotny iterator (ang. reverse iterator) umożliwiający nam przejście wstecz przez zakres.

<image src="https://twimgs.com/ddj/cuj/images/cuj0106smeyers/diagram2.gif">

___

## Krótka powtórka #4

Jeżeli nie chcemy modyfikować danych wskazywanych przez iterator zastosujemy opcję z przedrostkiem `c` pochodzącym od słowa `constant`.

* cbegin()
* cend()
* crbegin()
* crend

___

## Hierarhia iteratorów

<image src="https://tr1.cbsistatic.com/hub/i/2015/06/03/fb4d1b31-098c-11e5-940f-14feb5cc3d2a/u00220020606KXS01_02.gif">

Pytanie, co powinno się znaleźć w miejscu `forward_iterator` ?

`std::forward_list<T>` `std::unordered_set<T>` `std::unordered_map<T>`

___

### "Najbiedniejszy" iterator czyli input i output

Input iterator: pochodzi np. ze strumienia std::istream, czyli znanego nam `std::cin` raz wczytane dane znikają, nie możemy ich ponownie odczytać. Mamy możliwość tylko jednorazowego przejścia przez dane. Innym słowem jak tylko odczytamy jakąś daną nasz operator odrazu jest inkrementowany.

```C++
int a;
int b;
std::cin >> a >> b;
```

Otput iterator: pochodzi np. ze strumienia std::ostream, czyli znanego nam `std::cout` raz wypisane dane znikają, nie możemy ich ponownie wyświetlić, musimy ponownie podać dane.

```C++
int a;
int b;
std::cin >> a >> b;
std::cout << a << ' ' << b;
```

Pytanie: Jakie mamy dostępne operatory dla input iterator a jakie dla output iterator?
Input iterator: `operator()++`  `operator*` `operator->` `operator==` `operator!=`
Output iterator: `operator()++`  `operator*`
___

### Forward iterator

Jest to iterator, który umożliwia nam wielokronte przejście danego zakresu w jedną stronę (w przód).

```C++
std::forward_list<int> list {1, 2, 3, 4, 5};
for (auto it = list.begin() ; it != list.end() ; ++it) {
    std::cout << *it << '\n';
}
```

Output: `1 2 3 4 5`

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
`operator()++`  `operator*` `operator->` `operator==` `operator!=`

___

### Bidirectional iterator

Jest to iterator, który umożliwia nam wielokronte przejście danego zakresu w obie strony (w przód i tył).

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

Output: `1 2 3 4 5 5 4 3 2 1`

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
`operator()++`  `operator*` `operator->` `operator==` `operator!=` `operator--`

___

### Random Access iterator

Jest to iterator, który umożliwia nam wielokronte przejście danego zakresu w obie strony (w przód i tył) a także dostęp do dowolnego obiektu.

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

Output: `1 2 3 4 5 5 4 3 2 1 3`

Pytanie: Jakie mamy dostępne operatory dla tego iteratora?
`operator()++`  `operator*` `operator->` `operator==` `operator!=` `operator--` `operator<` `operator<=` `operator>` `operator>=` `operator+` `operator-` `operator[]`

___

### Ciekawostka

W C++ 17 wprowadzone jescze typ: ContiguousIterator. Zawiera On wszystkie cechy Random Access iterator oraz zapewnia, że wszystkie dane są ułożone w jednym miejscu w pamięci.

___

## Q&A

___
