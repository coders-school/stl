<!-- .slide: data-background="#111111" -->

# Algorytmy

## Nie modyfikujące sekwencji

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorytmy nie modyfikujące sekwencji

Nie modyfikują kontenerów na których działają. Nie mogą:
<!-- .element: class="fragment fade-in" -->

* zmieniać kolejności elementów <!-- .element: class="fragment fade-in" -->
* usuwać elementów <!-- .element: class="fragment fade-in" -->
* dodawać elementów <!-- .element: class="fragment fade-in" -->

___
<!-- .element: style="font-size: 0.9em" -->
### Typy takich algorytmów

1. <!-- .element: class="fragment fade-in" --> Sprawdzanie warunków - <code>std::all_of</code>, <code>std::any_of</code>, <code>std::none_of</code>
2. <!-- .element: class="fragment fade-in" --> Zliczanie elementów - <code>std::count</code>, <code>std::count_if</code>
3. <!-- .element: class="fragment fade-in" --> Szukanie elementów - <code>std::find_if</code> vs <code>std::find_first_of</code> vs <code>std::search</code> vs <code>std::adjacent_find</code>
4. <!-- .element: class="fragment fade-in" --> Porównywanie - <code>std::mismatch</code>

___

### `std::find_if` vs `std::find_first_of` vs `std::search` vs `std::adjacent_find`

* <!-- .element: class="fragment fade-in" --> <code>std::find_if</code> zwraca pierwszy element, który spełnia zadany warunek, zwany predykatem (dla którego predykat zwróci <code>true</code>)
* <!-- .element: class="fragment fade-in" --> <code>std::find_first_of</code> przeszukuje pierwszy zakres w celu znalezienia któregokolwiek z elementów w drugim zakresie
* <!-- .element: class="fragment fade-in" --> <code>std::search</code> przeszukuje pierwszy zakres w celu znalezienie pierwszego wystąpienia sekwencji elementów z drugiego zakresu
* <!-- .element: class="fragment fade-in" --> <code>std::adjacent_find</code> znajduje pierwsze dwie sąsiadujące ze sobą elementy, które są równe (lub spełniają podany warunek)
* <!-- .element: class="fragment fade-in" --> Wszystkie z nich zwracają:
  * <!-- .element: class="fragment fade-in" --> iterator do pierwszego pasującego elementu, lub...
  * <!-- .element: class="fragment fade-in" --> <code>last</code> (drugi argument podany do algorytmu, zazwyczaj iterator <code>end()</code>) jeśli nic nie pasuje

___

## Pozostałe algorytmy przeszukiwania

Ale to nie wszystko, bo mamy jeszcze takie algorytmy:

* <!-- .element: class="fragment fade-in" --> <code>std::find</code>
* <!-- .element: class="fragment fade-in" --> <code>std::find_if_not</code>
* <!-- .element: class="fragment fade-in" --> <code>std::find_end</code>
* <!-- .element: class="fragment fade-in" --> <code>std::search_n</code>

___

### Ściąga na hackingcpp.com

* [Finding / Locating Elements](https://hackingcpp.com/cpp/std/algorithms.html)

___

### Zadanie 💻

1. Utwórz `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Znajdź wszystkie elementy większe od `6` i wypisz je
3. Znajdź wszystkie elementy równe `2`, `4`, `6` lub `8` i wypisz je
4. Przeszukaj wektor `v` w poszukiwaniu zakresów `{6, 6}` i `{7, 7}`
5. Użyj `std::adjacent_find` na wektorze `v`
