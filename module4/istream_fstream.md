# Operacje na plikach

___

## Krótka pasta o iteratorach

<img src="http://www.cplusplus.com/img/iostream.gif">

___

## istream, ostream, iostream

O danych przychodzących i wychodzących będziemy mówić jak o strumieniach danych. Strumień może płynąć od programu do świata zewnętrzego poprzez `operator>>` natomiast ze świata zewnętrzego do programu poprzez `operator<<`.

* istream (`std::cin`) -> od input stream, czyli dane przychodzące (np. wpisywane z klawiatury).
* ostream (`std::cout`, `std::cerr`, `std::clog`) -> od output stream, czyli dane wychodzące (np. wyświetlane na monitorze).
* iostream -> od input output stream, czyli dane moga zarówno być przychodzące jak i wychodzące.

___

## Strumień danych

Strumień danych może pochodzić z wielu źródeł, możemy je wczytywać od użytknownika, może on pochodzić z jakiegoś pliku zapisanego na dysku itp. Zapewnia nam to rozbudowana Hierarchia klas. Gdzie zaczynając od klasy bazowej `ios_base` docieramy do 3 kals pochodnych `istream`, `iostream` oraz `ostream`. W zależności od tego skąd będziemy chcieć wczytywac dane użyjemy:

* `fstream` do obsługi plików,
* `iostream` do obsługi poleceń wczytywanych z klawiatury,
* `sstream` służącą do wygodnego operowania na std::string tak jakby to by były strumienie danych.
  
Każda z tych 3 klas dziedziczy albo po `istream` gdy chcemy odczytywac dane, `ostream` gdy chcemy je zapisywać lub `iostream` gdy chcemy robić obie czynnośći.

___

## Czwarty jeździeć, czyli streambuf

Z definicji streambuffer reprezentuje urządzenia wyjściowe i wejściowe (jak monitor, klawiatura, dysk itp) oraz umożliwia nam dostęp do interfejsu niskiego poziomu). Raczej będzie żadko przez nas stosowany :)

Klasa tą użyjemy między innymi do tworzenia własnych strumieni. Popatrzmy na przykład jak utworzyć własny strumień wyjściowy ostream.

```C++
std::cout << 42 << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost << 24 << '\n';
```

Output:

```C++
42
24
```

Hmm Ale po co nam własny strumień?

___

## Własny styl wyświetlania danych

Aby nie ingerować w zwykły stumien std::cout, kóry jest używany globalnie.

```C++
std::cout << M_PI << '\n';
std::streambuf* buffer = std::cout.rdbuf();
std::ostream ost(buffer);
ost.precision(15);
ost << M_PI << '\n';
std::cout << M_PI << '\n';
```

Output:

```C++
3.14159
3.14159265358979
3.14159
```

<b>Jako zadanie dla chętnych zachęcam do sprawdzenia co biblioteka `iomanip` nam umozliwa</b>.

___

## Biblioteka fstream

Jest to biblioteka umozliwiająca nam zapis i odczyt danych z pliku. Jest to bardzo rozbudowana biblioteka, jednak zwykle będziemy używac tylko kilka metod. Zgadnijcie proszę co mogą one robić?

* `is_open()` -> sprawdza czy plik jest otwarty (zwraca bool),
* `put()` -> zapisuje do pliku jeden znak,
* `get()` -> pobiera jeden znak z pliku, ale nie przesuwa iteratora do przodu.
* `peek()` -> odczytuje znak, ale nie przesuwa ku
* `write()` -> zapisuje blok danych do pliku,
* `read()` -> odczytuje blok danych z pliku,
* `seekp()` -> ustawia nam pozycje wskaźnika odczytu/zapisu na danej pozycji w pliku,
* `tellp()` -> informuje nas o pozycji wskaźnika odczytu zapisu,
* `getline()` -> pobiera znaki z pliku tak długo aż nie natrafi na podany znak (domyślnie spację).

Wkaźnik w pliku możemy traktowac tak jak migający kursor `|` w plikach tekstowych :) Czyli jak piszemy sobie jakiś tekst, zawsze patrzymy, gdzie miga nam ten znaczek i wiemy gdzie modyfikujemy aktualnie plik.

___

## Trochę z linuxa

Jakie możemy nadać uprawnienia danemu plikowi?

* Read,
* Write,
* Execute,

Pliki możemy otworzyć w trybie do odczytu (read only) w trybie do modyfikacji (write only) lub w trybie (read-write). Dodatkowo mamy możliwość ustawienia kursora podczas otwierania pliku, wymazanie całej jego zawartości jeżeli istnieje, lub utowrzenie pliku jeżeli nie istnieje. Zgadnijmy co oznaczają poszczególne tryby:

* `trunc` -> wymazuje wszystko w pliku co było do tej pory,
* `in` -> tryb do odczytu,
* `out` -> tryb do zapisu,
* `ate` -> ustawia `seek` na końcu pliku,
* `app` -> ustawia `seek` na końcu pliku przed zapisaniem do niego danych. Jednym słowem "Doklejamy" nowe wartości na końcu pliku.
* `binary` -> Zapis/ odczyt w trybie binarnym.

___

## Przykład zapisu dziennika pokładowego załogi statku

```C++
// or longer -> std::ifstream::in std::ifstream::app
std::fstream diary("Day1.txt", diary.out | diary.app);
if (diary.is_open()) {
    std::cout << "OPENED!\n";
    diary << "Today is my first day on ship, with my crew\n";
    diary << "i'm a little scared!\n";
    diary << "Hope It will be marvelous adventure.\n";
    diary.close();
}
```

Plik do odczytu, dopisujący na końcu nowe dane.
ponieważ wszystko traktujemy jak strumienia, możemy również pisać do pliku używając `operatora<<`.

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

Output: `Today is my first day on ship, with my crew i'm a little scared! Hope It will be marvelous adventure.`

__

## Getline

Jeżeli chcemy odczytywać linijka po linijce, możemy użyć getline.

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

___

## POD - Plain old data

Czyli klasa/ struktura bez konstruktora, destruktora i metod wirtualnych.

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

Ale to już nie jest POD

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

___

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

public:
    char name_[15];
    size_t index_;
    double average_;
};

int main() {
    Pod mateusz;
    mateusz.SetName("Mateusz");
    mateusz.SetIndex(123456);
    mateusz.SetAverage(5.0);

    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&mateusz), sizeof(Pod));
        student.close();
    }
}
```

___

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

Hexdump:

```C++
0000000 614d 6574 7375 007a 0000 0000 0000 0000
0000010 e240 0001 0000 0000 0000 0000 0000 4014
0000020
```

Output:

```C++
Name: Mateusz
Index: 123456
Average: 5
```

___

## stringstream - jak wygodnie używać std::string jako strumień

Podzielenie `std::string` na pojedyncze słowa. Niestety nie możemy tego w tak prosty sposób zrobić dla innch znaków niż spacja.

```C++
    std::string str {"Ala ma kota, a kot ma ale, ale to nie to samo, co Sierotka ma rysia."};
    std::istringstream iss(str);
    std::vector<std::string> vec {std::istream_iterator<std::string>(iss), {}};
    std::copy(begin(vec), end(vec), std::ostream_iterator<std::string>(std::cout, "\t"));
```

Output:

```C++
Ala     ma      kota,   a       kot     ma      ale,    ale     to      nie     to      samo,   co      Sierotka        ma      rysia.
```

`std::ostream_iterator` pozwala nam wpisywać dane do `std::cout`, w wygodny sposób.

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

Output:

```note
str: End of passion play, crumbling away
I'm your source of self-destruction
Veins that pump with fear, sucking darkest clear
Leading on your deaths' construction
```

___

## Q&A

___
