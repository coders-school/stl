<!-- .slide: data-background="#111111" -->

# STL #1

## Kontenery sekwencyjne

### Podsumowanie

<a href="https://coders.school">
    <img width="500px" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co pamiętasz z dzisiaj?

### Napisz na czacie jak najwięcej haseł
<!-- .element: class="fragment fade-in" -->

1. <!-- .element: class="fragment fade-in" --> Jak czytać dokumentację
1. <!-- .element: class="fragment fade-in" --> Przypomnienie STLa
1. <!-- .element: class="fragment fade-in" --> <code>std::vector&lt;T&gt;</code>
1. <!-- .element: class="fragment fade-in" --> <code>std::list&lt;T&gt;</code>
1. <!-- .element: class="fragment fade-in" --> <code>std::forward_list&lt;T&gt;</code>
1. <!-- .element: class="fragment fade-in" --> <code>std::array&lt;T, N&gt;</code>
1. <!-- .element: class="fragment fade-in" --> <code>std::deque&lt;T&gt;</code>

___

<img width="500" data-src="img/sequence_containers.png" src="img/sequence_containers.png" alt="Kontenery sekwencyjne" class="plain">
___

## Praca domowa

### Post-work

* Poczytaj o formacie grafiki PGM - [Wiki ENG](https://en.wikipedia.org/wiki/Netpbm#File_formats). Ta wiedza może się przydać w zadaniu 3 i 4.
* Zadanie 1 - `removeVowel()`
* Zadanie 2 - `lengthSort()`
* Zadanie 3 - `compressGrayscale()`
* Zadanie 4 - `decompressGrayscale()`

#### Bonusy

* 2 punkty za każde zadanie dostarczone przed 14.06.2020 (niedziela) do 23:59
* 3 punkty za pracę w grupie dla każdej osoby z grupy. Zalecamy grupy 3 osobowe.

#### [Zadania w repo](https://github.com/coders-school/stl/tree/master/module1/homework)

___

### Pre-work

* Znajdź na [cppreference.com](https://en.cppreference.com/w/) opisy algorytmów i zapoznaj się z nimi. Popatrz też na przykłady użycia.
* Poczytaj o złożoności obliczeniowej np. na [Samouczku programisty](https://www.samouczekprogramisty.pl/podstawy-zlozonosci-obliczeniowej/)
* Obejrzyj i zapamiętaj jaka jest [złożoność operacji na poszczególnych kontenerach STL](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md)

___

## Zadanie 1 - `removeVowel()`

Napisz funkcję `removeVowel()`, która przyjmie `std::vector<std::string>>` oraz usunie wszystkie samogłoski z tych wyrażeń.

* Input: `{"abcde", "aabbbccabc", "qwerty"}`
* Output: `{"bcd", "bbccbc", "qwrt"}`

___

## Zadanie 2 - `lengthSort()`

Napisz funkcję `lengthSort()`.

Ma ona przyjąć `std::forward_list<std::string>` i zwrócić `std::deque<std::string>`
z posortowanymi słowami od najkrótszego do najdłuższego. Jeżeli dwa lub więcej słów ma tyle samo znaków
posortuj je leksykograficznie.

* Input: `std::forward_list<std::string>{"Three", "One", "Four", "Two"}`
* Output: `std::deque<std::string>{"One", "Two", "Four", "Three"}`

___
<!-- .slide: style="font-size: 0.9em" -->

## Zadanie 3 - `compressGrayscale()`

Zadaniem będzie kompresja obrazka w odcieniach szarości o wymiarach 240x160 pikseli. Każdy piksel może mieć wartość od 0 (kolor czarny) do 255 (kolor biały). Im większa wartość tym jaśniejszy odcień piksel reprezentuje. Przykład małego obrazka o rozmiarach 6x4 piksele:

<img width="300px" data-src="img/example.png" src="img/example.png" alt="Przykład pikseli" class="plain">

```cpp
255 255 0   255 0   255   // 0xFF 0xFF 0x00 0xFF 0x00 0xFF
128 0   128 0   128 0     // 0x80 0x00 0x80 0x00 0x80 0x00
64  64  64  64  64  64    // 0x40 0x40 0x40 0x40 0x40 0x40
255 192 128 64  0   0     // 0xFF 0xB0 0x80 0x40 0x00 0x00
```

Aby otrzymać z tego plik w formacie PGM wystarczy tylko dodać mu odpowiedni nagłówek.

___
<!-- .slide: style="font-size: 0.9em" -->

## Zadanie 3 - `compressGrayscale()` - opis

Napisz funkcję `compressGrayscale()`.
Powinna ona przyjąć jeden argument typu `std::array<std::array<uint8_t, 240>, 160>` określający rozkład odcieni szarości na obrazku 2D (który w dalszej części nazywać będziemy bitmapą) i zwróci `std::vector<std::pair<uint8_t, uint8_t>>` zawierający skompresowaną bitmapę.

Kompresja powinna przebiegać w następujący sposób:

* Bitmapę rysujemy od górnego lewego rogu przechodząc w prawo, następnie poziom niżej.
* Jeżeli obok siebie występuje ten sam kolor więcej niż 1 raz, funkcja powinna wrzucić do  `std::vector<>` wartość tego koloru (liczba z przedziału 0 – 255) jako pierwszy element pary oraz ilość jego powtórzeń jako drugi element pary.
* Jeżeli obok siebie występują różne odcienie to funkcja powinna wypełnić `std::vector<> ` wartością odcienia oraz liczbą wystąpień równą 1 (w tym przypadku pogarszamy optymalizację, gdyż przechowujemy 2x tyle danych, jednak najczęściej te same kolory są położone obok siebie).

___
<!-- .slide: style="font-size: 0.9em" -->

## Zadanie 3 - `compressGrayscale()` - przykład

```cpp
input: {{0 0 0 1 1 2 3 0 0 0},
        {0 0 4 4 4 1 1 1 1 1},
        {2 2 2 2 2 1 2 2 2 2}}
output: {{0, 3}, {1, 2}, {2, 1}, {3, 1}, {0, 3}, {0, 2}, {4, 3}, {1, 5}, {2, 5}, {1, 1}, {2, 4}}
```

W przypadku powyższej konwersji zamiast 30 bajtów (wymiary 10x3) zużyjemy 22 (11x2). Więc skompresowaliśmy dane o 26,7%.

Nie przejmujemy się na razie tym jak `uint_8` będzie zamieniany na kolor. Ważne w tym zadaniu jest, aby poćwiczyć korzystanie z kontenerów oraz wykonywania na nich różnych operacji.

Chętni mogą także zrefaktoryzować (czyli napisać czytelniej, ulepszyć) testy tak, aby te skomplikowane pętle, które wypełniają tablice były uniwersalną funkcją, możliwą do wywołania w obecnie istniejących i przyszłych testach (podobnie jak funkcja `getBitmap()`).
Po wydzieleniu i refaktoringu funkcji generującej, postarajcie się dopisać także przypadki dla 1/16, 1/32 i 1/64 mapy.

___
<!-- .slide: data-background="img/jjfile1_002.png" -->

___

## Zadanie 4 - `decompressGrayscale()`

Napisz funkcję `decompressGrayscale()`, która zdekompresuje obrazek skompresowany w zadaniu 3 za pomocą funkcji `compressGrayscale()`.

Jako argument funkcja `decompressGrayscale()` przyjmie `std::vector<std::pair<uint8_t, uint8_t>>` natomiast zwróci `std::array<std::array<uint8_t, 240>, 160>` i przeprowadzi operacje mające na celu rekonstrukcję pierwotnego formatu bitmapy.

___

## ASCII art

Dla chętnych (bez punktów) polecamy także napisać sobie funkcję `printMap()`, która wyświetli mapę.
Domyślnie `std::cout` potraktuje `uint8_t` jako `unsigned char`, dlatego też możecie sobie wypisać mapę z kodów ASCII.

<img width="450px" data-src="img/ascii_art_mug.jpg" src="img/ascii_art_mug.jpg" alt="ASCII art z kubkiem" class="plain">

___

Chętni mogą także zrefaktoryzować testy, tak by funkcja sprawdzająca mapę była generyczna (adekwatnie do funkcji `expectBitmap()`.
Po refaktoringu funkcji sprawdzającej, postarajcie sie dopisać także przypadki dla 1/16, 1/32 i 1/64 mapy.
