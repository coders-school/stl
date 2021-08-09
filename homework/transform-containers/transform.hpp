//     Napisz funkcję transformContainers, która przyjmie std::list<std::string> oraz std::deque<int>
//     Usunie duplikaty z obu kontenerów
//     Na koniec skonwertuje to na std::map<int, std::string> i ją zwróci. Użyj std::transform.

// Zajrzyj do pliku z test.cpp i na jego podstawie wywnioskuj jak się ma nazywać funkcja, którą musisz zaimplementować.

// Plik nagłówkowy oraz źródłowy z implementacją funkcji nazwij tak, jak Ci się wydaje, że będzie pasować :)

// Dodaj odpowiednie #include do test.cpp

// Dodaj swój plik źródłowy cpp do pliku CMakeLists.txt, aby również był on kompilowany. Znajdziesz tam odpowiednie sekcje pod koniec:

#pragma once
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <string>

std::map <int, std::string> removeDuplicateAndTranformToMap(std::list <std::string>&, std::deque <int>&);