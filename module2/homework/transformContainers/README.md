# `transformContainers`

1. Napisz funkcję `transformContainers`, która przyjmie `std::list<std::string>` oraz `std::deque<int>`
2. Usunie duplikaty z obu kontenerów
3. Na koniec skonwertuje to na `std::map<int, std::string>` i ją zwróci. Użyj `std::transform`.

Zajrzyj do pliku z test.cpp i na jego podstawie wywnioskuj jak się ma nazywać funkcja, którą musisz zaimplementować.

Plik nagłówkowy oraz źródłowy z implementacją funkcji nazwij tak, jak Ci się wydaje, że będzie pasować :)

Dodaj odpowiednie `#include` do `test.cpp`

Dodaj swój plik źródłowy cpp do pliku `CMakeLists.txt`, aby również był on kompilowany. Znajdziesz tam odpowiednie sekcje pod koniec:

```cmake
add_executable(${PROJECT_NAME}-ut test.cpp) # add your cpp file here after test.cpp
# it this is problematic take a look into CMakeLists.txt files in other exercises
```
