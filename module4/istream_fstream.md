<!-- .slide: data-background="#111111" -->

# Operacje na plikach

___


## Krótka pasta o strumieniach

<img src="img/iostream.gif">

___

## istream, ostream, iostream

O danych przychodzących i wychodzących będziemy mówić jak o strumieniach danych. Strumień może płynąć od programu do świata zewnętrzego poprzez `operator>>`, natomiast ze świata zewnętrzego do programu poprzez `operator<<`.

* <!-- .element: class="fragment fade-in" --> istream (<code>std::cin</code>) -> od input stream, czyli dane przychodzące (np. wpisywane z klawiatury).
* <!-- .element: class="fragment fade-in" --> ostream (<code>std::cout</code>, <code>std::cerr</code>, <code>std::clog</code>) -> od output stream, czyli dane wychodzące (np. wyświetlane na monitorze).
* <!-- .element: class="fragment fade-in" --> iostream -> od input output stream, czyli dane mogą zarówno być przychodzące jak i wychodzące.

___

## Strumień danych

Strumień danych może pochodzić z wielu źródeł, możemy je wczytywać od użytkownika, może on pochodzić z jakiegoś pliku zapisanego na dysku itp. Zapewnia nam to rozbudowana hierarchia klas, gdzie zaczynając od klasy bazowej `ios_base` docieramy do 3 klas pochodnych `istream`, `iostream` oraz `ostream`. W zależności od tego skąd będziemy chcieć wczytywać dane użyjemy:

* <!-- .element: class="fragment fade-in" --> <code>fstream</code> do obsługi plików,
* <!-- .element: class="fragment fade-in" --> <code>iostream</code> do obsługi poleceń wczytywanych z klawiatury,
* <!-- .element: class="fragment fade-in" --> <code>sstream</code> służącą do wygodnego operowania na <code>std::string</code>, tak jakby to by były strumienie danych.

Każda z tych 3 klas dziedziczy albo po <code>istream</code>, gdy chcemy odczytywać dane, <code>ostream</code> gdy chcemy je zapisywać lub <code>iostream</code>, gdy chcemy robić obie czynności.
<!-- .element: class="fragment fade-in" -->

___

## Czwarty jeździec, czyli `streambuf`

Z definicji streambuffer reprezentuje urządzenia wyjściowe i wejściowe (jak monitor, klawiatura, dysk itp.) oraz umożliwia nam dostęp do interfejsu niskiego poziomu. Raczej będzie rzadko przez nas stosowany 🙂

Klasę tę użyjemy między innymi do tworzenia własnych strumieni. Popatrzmy na przykład jak utworzyć własny strumień wyjściowy `ostream`.
<!-- .element: class="fragment fade-in" -->

```C++
std::cout << 42 << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost << 24 << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
42
24
```
<!-- .element: class="fragment fade-in" -->

🤔 Ale po co nam własny strumień?
<!-- .element: class="fragment fade-in" -->

___

## Własny styl wyświetlania danych

Aby nie ingerować w zwykły strumień `std::cout`, który jest używany globalnie.

```C++
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

```C++
3.14159
3.14159265358979
3.14159
```
<!-- .element: class="fragment fade-in" -->

**Jako zadanie dla chętnych zachęcam do sprawdzenia co biblioteka `iomanip` nam umożliwia.**
<!-- .element: class="fragment fade-in" -->

___

<!-- .slide: style="font-size: 0.9em" -->

## Biblioteka `fstream`

Jest to biblioteka umożliwiająca nam zapis i odczyt danych z pliku. Jest to bardzo rozbudowana biblioteka, jednak zwykle będziemy używać tylko kilka metod. Zgadnijcie proszę co mogą one robić?

* <!-- .element: class="fragment fade-in" --> <code>is_open()</code><span class="fragment fade-in"> -> sprawdza czy plik jest otwarty (zwraca <code>bool</code>)</span>
* <!-- .element: class="fragment fade-in" --> <code>put()</code><span class="fragment fade-in"> -> zapisuje do pliku jeden znak</span>
* <!-- .element: class="fragment fade-in" --> <code>get()</code><span class="fragment fade-in"> -> pobiera jeden znak z pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>peek()</code><span class="fragment fade-in"> -> odczytuje znak, ale nie przesuwa wskaźnika odczytu/zapisu</span>
* <!-- .element: class="fragment fade-in" --> <code>write()</code><span class="fragment fade-in"> -> zapisuje blok danych do pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>read()</code><span class="fragment fade-in"> -> odczytuje blok danych z pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>seekp()</code><span class="fragment fade-in"> -> ustawia nam pozycje wskaźnika odczytu/zapisu na danej pozycji w pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>tellp()</code><span class="fragment fade-in"> -> informuje nas o pozycji wskaźnika odczytu zapisu</span>
* <!-- .element: class="fragment fade-in" --> <code>getline()</code><span class="fragment fade-in"> -> pobiera znaki z pliku tak długo, aż nie natrafi na podany znak (domyślnie znak nowej linii)</span>

Wskaźnik w pliku możemy traktować tak jak migający kursor `|` w plikach tekstowych 🙂 Czyli jak piszemy sobie jakiś tekst, zawsze patrzymy, gdzie miga nam ten znaczek i wiemy gdzie modyfikujemy aktualnie plik.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Trochę z linuxa

Jakie możemy nadać uprawnienia danemu plikowi?

* <!-- .element: class="fragment fade-in" --> Read
* <!-- .element: class="fragment fade-in" --> Write
* <!-- .element: class="fragment fade-in" --> Execute

Pliki możemy otworzyć w trybie do odczytu (read only), w trybie do modyfikacji (write only) lub w trybie (read-write). Dodatkowo mamy możliwość ustawienia kursora podczas otwierania pliku, wymazanie całej jego zawartości jeżeli istnieje, lub utworzenie pliku jeżeli nie istnieje. Zgadnijmy co oznaczają poszczególne tryby:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>trunc</code> <span class="fragment fade-in"> -> wymazuje wszystko w pliku co było do tej pory,</span>
* <!-- .element: class="fragment fade-in" --> <code>in</code> <span class="fragment fade-in"> -> tryb do odczytu,</span>
* <!-- .element: class="fragment fade-in" --> <code>out</code> <span class="fragment fade-in"> -> tryb do zapisu,</span>
* <!-- .element: class="fragment fade-in" --> <code>ate</code> <span class="fragment fade-in"> -> ustawia <code>seek</code> na końcu pliku,</span>
* <!-- .element: class="fragment fade-in" --> <code>app</code> <span class="fragment fade-in"> -> ustawia <code>seek</code> na końcu pliku przed zapisaniem do niego danych. Jednym słowem "doklejamy" nowe wartości na końcu pliku.</span>
* <!-- .element: class="fragment fade-in" --> <code>binary</code> <span class="fragment fade-in"> -> zapis/odczyt w trybie binarnym.</span>

___

## Przykład zapisu dziennika pokładowego załogi statku

```C++
std::fstream diary("Day1.txt", diary.out | diary.app);
// or longer -> std::ifstream::out | std::ifstream::app
if (diary.is_open()) {
    std::cout << "OPENED!\n";
    diary << "Today is my first day on ship, with my crew\n";
    diary << "I'm a little scared!\n";
    diary << "Hope it will be a marvelous adventure.\n";
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

Plik do zapisu, dopisujący na końcu nowe dane.
Ponieważ wszystko traktujemy jak strumienie, możemy również pisać do pliku używając `operatora<<`.
<!-- .element: class="fragment fade-in" -->

___

## Przykład odczytu dziennika pokładowego załogi statku

```C++
diary.open("Day1.txt", diary.in);
if (diary.is_open()) {
    std::string str;
    while (diary >> str) {
        std::cout << str << ' ';
    }
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

Output: `Today is my first day on ship, with my crew I'm a little scared! Hope it will be a marvelous adventure.`
<!-- .element: class="fragment fade-in" -->

___

## `getline()`

Jeżeli chcemy odczytywać dane linijka po linijce, możemy użyć funkcji `getline()`.

```C++
diary.open("Day1.txt", diary.in);
if (diary.is_open()) {
    std::string str;
    while (!getline(diary, str, '\n').eof()) {
        std::cout << str << '\n';
    }
    diary.close();
}
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
