// Napisz funkcję transformContainers, która przyjmie std::list<std::string> oraz std::deque<int>
// Usunie duplikaty z obu kontenerów
// Na koniec skonwertuje to na std::map<int, std::string> i ją zwróci. Użyj std::transform.
// Zajrzyj do pliku z test.cpp i na jego podstawie wywnioskuj jak się ma nazywać funkcja, którą musisz zaimplementować.

// Plik nagłówkowy oraz źródłowy z implementacją funkcji nazwij tak, jak Ci się wydaje, że będzie pasować :)

// Dodaj odpowiednie #include do test.cpp

// Dodaj swój plik źródłowy cpp do pliku CMakeLists.txt, aby również był on kompilowany. Znajdziesz tam odpowiednie sekcje pod koniec:

// add_executable(${PROJECT_NAME}-ut test.cpp) # add your cpp file here after test.cpp
// # it this is problematic take a look into CMakeLists.txt files in other exercises
#include "transform.hpp"
#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> lis, std::deque<int> deq) {
    lis.sort();
    lis.erase(std::unique(lis.begin(), lis.end()), lis.end());
    std::sort(deq.begin(), deq.end());
    deq.erase(std::unique(deq.begin(), deq.end()), deq.end());
    std::map<int, std::string> map;
    return map;
}