<!-- .slide: data-background="#111111" -->

# Operacje na plikach

___

## Krótka pasta o iteratorach

<img src="http://www.cplusplus.com/img/iostream.gif">

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

Aby nie ingerować w zwykły strumień `std::cout`, kóry jest używany globalnie.

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

* <!-- .element: class="fragment fade-in" --> <code>is_open()</code><span class="fragment fade-in"> -> sprawdza czy plik jest otwarty (zwraca <code>bool</co    de>)</span>
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

## POD - Plain old data

Czyli klasa/struktura bez konstruktora, destruktora i metod wirtualnych.

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

private:
    size_t index_;
    const char name_[15];
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

<!-- Podzieliłem slajd na dwa, bo trzeba było bardzo mocno zmniejszyć czcionkę żeby się zmieściło -->
___

## POD - Plain old data #2

Ale to już nie jest POD.

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

private:
    size_t index_;
    std::string name_; // std::string has constructor!
    double average_;
};
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Zapisywanie POD

```C++
class Pod {
public:
    void DoSth() {}
    bool ReturnTrue() { return true; }
    bool ReturnFalse() { return false; }

    void SetName(std::string name) { strncpy(name_, name.data(), 15); }
    void SetIndex(size_t index) { index_ = index; }
    void SetAverage(double average) { average_ = average; }

    std::string GetName() const { return name_; }
    size_t GetIndex() const { return index_; }
    double GetAverage() const { return average_; }

private:
    char name_[15];
    size_t index_;
    double average_;
};

int main() {
    Pod mateusz;
    mateusz.SetName("Mateusz");
    mateusz.SetIndex(123456);
    mateusz.SetAverage(5.0);

    // or
    // Pod mateusz{"Mateusz", 123456, 5.0};

    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&mateusz), sizeof(Pod));
        student.close();
    }
}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Odczyt POD

```C++
    student.open("Student.txt", student.binary | student.in);
    Pod mateusz_read;
    if (student.is_open()) {
        student.read(reinterpret_cast<char*>(&mateusz_read), sizeof(Pod));
        std::cout << "Name: " << mateusz_read.GetName() << '\n';
        std::cout << "Index: " << mateusz_read.GetIndex() << '\n';
        std::cout << "Average: " << mateusz_read.GetAverage() << '\n';
        student.close();
    }
```
<!-- .element: class="fragment fade-in" -->

Hexdump:
<!-- .element: class="fragment fade-in" -->

```C++
0000000 614d 6574 7375 007a 0000 0000 0000 0000
0000010 e240 0001 0000 0000 0000 0000 0000 4014
0000020
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
Name: Mateusz
Index: 123456
Average: 5
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## stringstream - jak wygodnie używać `std::string` jako strumień

Podzielenie `std::string` na pojedyncze słowa. Niestety nie możemy tego w tak prosty sposób zrobić dla innch znaków niż spacja.

```C++
std::string str {"Ala ma kota, a kot ma ale, ale to nie to samo, co Sierotka ma rysia."};
std::istringstream iss(str);
std::vector<std::string> vec {std::istream_iterator<std::string>(iss), {}};
std::copy(begin(vec), end(vec), std::ostream_iterator<std::string>(std::cout, "\t"));
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
Ala     ma      kota,   a       kot     ma      ale,    ale     to      nie     to      samo,   co      Sierotka        ma      rysia.
```
<!-- .element: class="fragment fade-in" -->

`std::ostream_iterator` pozwala nam wpisywać dane do `std::cout`, w wygodny sposób.
<!-- .element: class="fragment fade-in" -->

___

## stringstream -> jak skonwertować na string

```C++
std::stringstream ss;
ss << "End of passion play, crumbling away\n";
ss << "I'm your source of self-destruction\n";
ss << "Veins that pump with fear, sucking darkest clear\n";
ss << "Leading on your deaths' construction\n";
std::string str = ss.str();
std::cout << "str: " << str;
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
str: End of passion play, crumbling away
I'm your source of self-destruction
Veins that pump with fear, sucking darkest clear
Leading on your deaths' construction
```
<!-- .element: class="fragment fade-in" -->

___

## Q&A
