# `insensitivePalindrom`

Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. Program powinien ignorować znaki specjalne jak `,.?()[]`, wielkość liter oraz białe znaki jak spacja czy znak nowej linii.

Zajrzyj do pliku z test.cpp i na jego podstawie wywnioskuj jak się ma nazywać funkcja, którą musisz zaimplementować.

Plik nagłówkowy oraz źródłowy z implementacją funkcji nazwij tak, jak Ci się wydaje, że będzie pasować :)

Dodaj odpowiednie `#include` do `test.cpp`

Dodaj swój plik źródłowy cpp do pliku `CMakeLists.txt`, aby również był on kompilowany. Znajdziesz tam odpowiednie sekcje pod koniec:

```cmake
add_executable(${PROJECT_NAME}-ut test.cpp) # add your cpp file here after test.cpp
# it this is problematic take a look into CMakeLists.txt files in other exercises
```
