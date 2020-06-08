<!-- .slide: data-background="#111111" -->

# STL #2

## Funktory, lambdy, algorytmy

### Podsumowanie

<a href="https://coders.school">
    <img width="500px" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co było łatwe do zrozumienia?

## Co chcesz powtórzyć na sesji Q&A?
<!-- .element: class="fragment fade-in" -->

### Zapisz i wrzuć na kanał #powtórka na Discordzie :)
<!-- .element: class="fragment fade-in" -->

___

## Praca domowa

### Post-work

* Zadanie 1 - kontynuacja poprzedniego zadania 3 - `grayscaleImages` (6 punktów)
* Zadanie 2 - `insensitivePalindrom` (6 punktów)
* Zadanie 3 - `transformContainers` (6 punktów)

PR zgłaszajcie również na gałąź `master` w repo `coders-school/stl`, ale dodajcie obowiązkowo w tytule `STL#2`. U was gałąź może być dowolna.

#### Bonusy

* 2 punkty za każde zadanie dostarczone przed 21.06.2020 (niedziela) do 23:59
* 3 punkty za pracę w grupie dla każdej osoby z grupy. Zalecamy grupy 3 osobowe (takie jak ostatnio)

#### [Zadania w repo](https://github.com/coders-school/stl/tree/master/module2/homework)


___

### Pre-work

* Przygotuj listę pytań na sesję Q&A :)
* Upewnij się, że działa Ci mikrofon i możesz rozmawiać na Discordzie
* Jeśli masz wątpliwości lub niedziałające implementacje i chcesz je skonsultować - podeślij link do repo na kanale #powtórka na Discordzie.
  * Pytania możesz oznaczyć komentarzami w kodzie
  * Pytania możesz też napisać w komentarzu do PR
  * Dodatkowe pytania możesz też później zadać na żywo podczas omawiania kodu

___

### Zadanie 1 - `grayscaleImages` cd.

Ulepsz program `grayscaleImages` z poprzednich zajęć STL#1 (kompresja, dekompresja) obrazków, tak, aby zamiast pętli wykorzystać algorytmy. Działaj na swojej/waszej wersji implementacji tego zadania.

___

### Zadanie 2 - `insensitivePalindrom`

Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. Program powinien ignorować znaki specjalne jak `,.?()[]`, wielkość liter oraz białe znaki jak spacja czy znak nowej linii.

Tutaj wywnioskuj po testach jak nazwać funkcję. Stwórz własne pliki źródłowe i nagłówkowe i dodaj je do CMakeLists.txt, aby się budowały. Szczegóły w README.md do tego zadania.

___

### Zadanie 3 - `transformContainers`

1. Napisz funkcję `transformContainers`, która przyjmie `std::list<std::string>` oraz `std::deque<int>`
2. Usunie duplikaty z obu kontenerów
3. Na koniec skonwertuje to na `std::map<int, std::string>` i ją zwróci. Użyj `std::transform`.

Tutaj wywnioskuj po testach jak nazwać funkcję. Stwórz własne pliki źródłowe i nagłówkowe i dodaj je do CMakeLists.txt, aby się budowały. Szczegóły w README.md do tego zadania.
