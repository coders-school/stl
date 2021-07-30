<!-- .slide: data-background="#111111" -->

# Algorytmy STL

## Praca domowa 💻

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## Praca domowa

### Post-work

Działaj dużo z dokumentacją cppreference i najlepiej z kimś w parze lub nawet grupie 3-osobowej 🙂

* Obejrzyj [105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=bFSnXNIsK4A)
* Zadanie 1 -  kontynuacja zadania `grayscale-image` (6 punktów)
* Zadanie 2 - `insensitive-palindrom` (6 punktów)
* Zadanie 3 - `transform-containers` (6 punktów)

#### Bonusy

* **18.07.2021 (środa)** to ostatni dzień na zebranie bonusowych punktów za punktualność
* **3 XP** wpadną Ci za każde zadanie dostarczone w terminie (razem aż 9 punktów)
* **1 XP** za pracę w grupie dla każdej osoby z grupy za każde zadanie (razem 3 punkty dla każdej osoby). Zalecamy grupy 3 osobowe.

#### [Zadania w repo](https://github.com/coders-school/stl/blob/master/04-algorithms/16-homework.md)

___

### Pre-work

* Poczytaj coś więcej o złożoności obliczeniowej np. na [Samouczku programisty](https://www.samouczekprogramisty.pl/podstawy-zlozonosci-obliczeniowej/)
* Obejrzyj i zapamiętaj jaka jest [złożoność operacji na wszystkich kontenerach STL](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md). Poczytaj tam też o drzewach binarnych i różnych algorytmach sortowania.

___

## Zadanie 1 - `grayscale-image-algo`

Ulepsz program `grayscale-images` z poprzedniej pracy domowe (kompresja, dekompresja) obrazków, tak, aby zamiast pętli wykorzystać algorytmy. Działaj na swojej/waszej wersji implementacji tego zadania.

Gotowe zadanie zgłoś na branch `coders/grayscale-image-algo`. Jeśli nie chcesz nadpisać PR z tamtą pracą domową to po prostu utwórz nowego brancha od tego stanu. Jeśli to skomplikowane - po prostu skopiuj swój program `grayscale-images` ;)

___

## Zadanie 2 - `insensitive-palindrom`

Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. Program powinien ignorować znaki specjalne np. `,.?()[]` (i nie tylko). Powinien również ignorować wielkość liter oraz białe znaki jak spacja czy znak nowej linii.

Wywnioskuj po testach jak nazwać funkcję. Stwórz własne pliki źródłowe i nagłówkowe i dodaj je do CMakeLists.txt, aby się budowały. Szczegóły w README.md do tego zadania.

___

## Zadanie 3 - `transform-containers`

Napisz funkcję `transformContainers`, która:

1. Przyjmie `std::list<std::string>` oraz `std::deque<int>`
2. Usunie duplikaty z obu kontenerów
3. Na koniec skonwertuje to na `std::map<int, std::string>` i ją zwróci. Użyj `std::transform`.

Wywnioskuj po testach jak nazwać funkcję. Stwórz własne pliki źródłowe i nagłówkowe i dodaj je do CMakeLists.txt, aby się budowały. Szczegóły w README.md do tego zadania.
