<!-- .slide: data-background="#111111" -->

# Strumienie plików

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

<!-- .slide: style="font-size: 0.9em" -->

## Biblioteka `fstream`

Jest to biblioteka umożliwiająca zapis i odczyt danych z pliku. Jest bardzo rozbudowana, jednak zwykle będziemy używać tylko kilka metod. Zgadnij co mogą one robić?

* <!-- .element: class="fragment fade-in" --> <code>is_open()</code><span class="fragment fade-in"> -> sprawdza czy plik jest otwarty (zwraca <code>bool</code>)</span>
* <!-- .element: class="fragment fade-in" --> <code>put()</code><span class="fragment fade-in"> -> zapisuje do pliku jeden znak</span>
* <!-- .element: class="fragment fade-in" --> <code>get()</code><span class="fragment fade-in"> -> pobiera jeden znak z pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>peek()</code><span class="fragment fade-in"> -> odczytuje znak, ale nie przesuwa wskaźnika odczytu/zapisu</span>
* <!-- .element: class="fragment fade-in" --> <code>write()</code><span class="fragment fade-in"> -> zapisuje blok danych do pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>read()</code><span class="fragment fade-in"> -> odczytuje blok danych z pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>seekp()</code><span class="fragment fade-in"> -> ustawia nam pozycje wskaźnika odczytu/zapisu na danej pozycji w pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>tellp()</code><span class="fragment fade-in"> -> informuje nas o pozycji wskaźnika odczytu zapisu</span>
* <!-- .element: class="fragment fade-in" --> <code>getline()</code><span class="fragment fade-in"> -> pobiera znaki z pliku tak długo, aż nie natrafi na podany znak (domyślnie znak nowej linii)</span>

Wskaźnik odczytu/zapisu w pliku możemy traktować tak jak migający kursor `|` w plikach tekstowych 🙂 Czyli jak piszemy sobie jakiś tekst, zawsze patrzymy, gdzie miga nam ten znaczek i wiemy gdzie modyfikujemy aktualnie plik.
<!-- .element: class="fragment fade-in" -->

___

## Trochę z linuxa

Jakie możemy nadać uprawnienia danemu plikowi?

* <!-- .element: class="fragment fade-in" --> Read
* <!-- .element: class="fragment fade-in" --> Write
* <!-- .element: class="fragment fade-in" --> Execute

Pliki możemy otworzyć w trybie do odczytu (read only), w trybie do modyfikacji (write only) lub w trybie (read-write).
<!-- .element: class="fragment fade-in" -->

Dodatkowo mamy możliwość ustawienia kursora podczas otwierania pliku, wymazanie całej jego zawartości jeżeli istnieje, lub utworzenie pliku jeżeli nie istnieje.
<!-- .element: class="fragment fade-in" -->

___

## Tryby otwarcia pliku

Zgadnij co oznaczają poszczególne tryby:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>trunc</code> <span class="fragment fade-in"> - wymazuje wszystko w pliku co było do tej pory</span>
* <!-- .element: class="fragment fade-in" --> <code>in</code> <span class="fragment fade-in"> - tryb do odczytu</span>
* <!-- .element: class="fragment fade-in" --> <code>out</code> <span class="fragment fade-in"> - tryb do zapisu</span>
* <!-- .element: class="fragment fade-in" --> <code>ate</code> <span class="fragment fade-in"> - ustawia <code>seek</code> na końcu pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>app</code> <span class="fragment fade-in"> - ustawia <code>seek</code> na końcu pliku przed zapisaniem do niego danych, dzięki czemu "doklejamy" nowe wartości na końcu pliku</span>
* <!-- .element: class="fragment fade-in" --> <code>binary</code> <span class="fragment fade-in"> - zapis/odczyt w trybie binarnym</span>

___

## Przykład zapisu dziennika pokładowego załogi statku

```cpp
std::fstream diary("Day1.txt", diary.out | diary.app);
// or longer -> std::ifstream::out | std::ifstream::app
if (diary.is_open()) {
    std::cout << "OPENED!\n";
    diary << "Today is my first day on ship, with my crew\n";
    diary << "I'm a little scared!\n";
    diary << "Hope it will be a marvelous adventure.\n";
    // don't need to call diary.close() - RAII
}
```
<!-- .element: class="fragment fade-in" -->

Plik do zapisu, dopisujący na końcu nowe dane.
Ponieważ plik "Day1.txt" traktujemy jak strumień, możemy pisać do niego używając `operator<<`.
<!-- .element: class="fragment fade-in" -->

___

## Przykład odczytu dziennika pokładowego załogi statku

```cpp
diary.open("Day1.txt", diary.in);
if (diary.is_open()) {
    std::string str;
    while (diary >> str) {
        std::cout << str << ' ';
    }
}
```
<!-- .element: class="fragment fade-in" -->

Output: `Today is my first day on ship, with my crew I'm a little scared! Hope it will be a marvelous adventure.`
<!-- .element: class="fragment fade-in" -->

___

## `getline()`

Jeżeli chcemy odczytywać dane linijka po linijce, możemy użyć funkcji `getline()`.

```cpp
diary.open("Day1.txt");
if (diary.is_open()) {
    std::string str;
    while (!getline(diary, str, '\n').eof()) {
        std::cout << str << '\n';
    }
}
```
<!-- .element: class="fragment fade-in" -->
