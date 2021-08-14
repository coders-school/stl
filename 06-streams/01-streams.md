<!-- .slide: data-background="#111111" -->

# Strumienie

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Podział strumieni

<img src="../img/iostream.gif">

___

## `operator>>`, `operator<<`

O danych przychodzących i wychodzących będziemy mówić jak o strumieniach danych. Strumień może płynąć do programu ze świata zewnętrznego poprzez `operator>>`, natomiast od programu do świata zewnętrznego poprzez `operator<<`.

___
<!-- .slide: style="font-size: 0.95em" -->

## `istream`, `ostream`, `iostream`

<a href="https://drive.google.com/file/d/0B3DUpmL8tTt8N2JIRklJeTIxYW8/view?resourcekey=0-0zniuYTfigINYmPoI0I4pg"><img src="../img/cpp_lands.png"></a>

* <!-- .element: class="fragment fade-in" --> <code>istream</code> (<code>std::cin</code>) - od input stream, czyli dane przychodzące, np. wpisywane z klawiatury
* <!-- .element: class="fragment fade-in" --> <code>ostream</code> (<code>std::cout</code>, <code>std::cerr</code>, <code>std::clog</code>) - od output stream, czyli dane wychodzące, np. wyświetlane na monitorze
* <!-- .element: class="fragment fade-in" --> <code>iostream</code> - od input output stream, czyli dane mogą zarówno być przychodzące jak i wychodzące

___

## Strumień danych

Strumień danych może pochodzić z wielu źródeł. Dane możemy wczytywać od użytkownika, może on pochodzić z jakiegoś pliku zapisanego na dysku. Zapewnia nam to rozbudowana hierarchia klas, gdzie zaczynając od klasy bazowej `ios_base` docieramy do 3 klas pochodnych `istream`, `iostream` oraz `ostream`.

W zależności od tego skąd będziemy chcieli wczytywać dane użyjemy:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>fstream</code> (file stream) do obsługi plików
* <!-- .element: class="fragment fade-in" --> <code>iostream</code> (input output stream) do obsługi poleceń wczytywanych z klawiatury,
* <!-- .element: class="fragment fade-in" --> <code>sstream</code> (stringstream) do wygodnego operowania na <code>std::string</code>, tak jakby to by były strumienie danych.

Każda z tych 3 klas dziedziczy albo po <code>istream</code>, gdy chcemy odczytywać dane, <code>ostream</code> gdy chcemy je zapisywać lub <code>iostream</code>, gdy chcemy robić obie czynności.
<!-- .element: class="fragment fade-in" -->

___

## Czwarty jeździec, czyli `streambuf`

Z definicji `streambuf` reprezentuje bufor urządzenia wyjściowego lub wejściowego (jak monitor, klawiatura, dysk, karta sieciowa itp.) oraz umożliwia nam dostęp do interfejsu niskiego poziomu. Raczej będzie rzadko przez nas stosowany 🙂

Klasę tę użyjemy między innymi do tworzenia własnych strumieni. Popatrzmy na przykład jak utworzyć własny strumień wyjściowy `ostream`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::cout << 42 << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost << 24 << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
42
24
```
<!-- .element: class="fragment fade-in" -->

### Ale po co nam własny strumień? 🤔
<!-- .element: class="fragment fade-in" -->

___

## Własny styl wyświetlania danych

Aby nie ingerować w zwykły strumień `std::cout`, który jest używany globalnie.

```cpp
std::cout << M_PI << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost.precision(15);
ost << M_PI << '\n';
std::cout << M_PI << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
3.14159
3.14159265358979
3.14159
```
<!-- .element: class="fragment fade-in" -->

**Jako zadanie dla chętnych zachęcam do sprawdzenia co umożliwia biblioteka [`iomanip`](https://en.cppreference.com/w/cpp/header/iomanip)**
<!-- .element: class="fragment fade-in" -->
