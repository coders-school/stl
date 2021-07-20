<!-- .slide: data-background="#111111" -->

# Iteratory

## Zadanie

___

## Zadanie

Napisz funkcję `middle`, która może być wywoływana na różnych kontenerach.
<!-- .element: class="fragment fade-in" -->

Funkcja ta powinna zwracać środkowy element w kolekcji.
<!-- .element: class="fragment fade-in" -->

Napisz ją w konwencji algorytmów z biblioteki STL, czyli jako argumenty chcemy podać 2 iteratory:
<!-- .element: class="fragment fade-in" -->

```cpp
auto middle(Iter first, Iter last);
```
<!-- .element: class="fragment fade-in" -->

Za `Iter` musisz podstawić właściwe typy parametrów i napisać kilka przeciążeń tej funkcji.
<!-- .element: class="fragment fade-in" -->

Możesz też... użyć szablonów, jeśli wiesz jak :).
<!-- .element: class="fragment fade-in" -->

___

## Problem

Możesz napisać jedną uniwersalną implementację, która będzie działać dla wszystkich kontenerów, ale nie będzie zbyt wydajna we wszystkich przypadkach.
<!-- .element: class="fragment fade-in" -->

Jeśli masz do dyspozycji kontener posiadający tylko Forward Iterator to implementacja wygląda zapewne tak:
<!-- .element: class="fragment fade-in" -->

```cpp
auto middle(Iter begin, Iter end) {
    auto middle = begin;
    auto size = 0;
    while(begin != end) {
        ++size;
    }
    for (int i = 0; i < size / 2; ++i) {
        middle++;
    }
    return *middle;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Problem c.d.

Ale wiesz, że dla wektora, można to napisać tak:
<!-- .element: class="fragment fade-in" -->

```cpp
auto middle(Iter begin, Iter end) {
    size = end - begin;
    return *(begin + size / 2);
}
```
<!-- .element: class="fragment fade-in" -->

Czy można mieć zarówno uniwersalne jak i wydajne rozwiązanie?
<!-- .element: class="fragment fade-in" -->
