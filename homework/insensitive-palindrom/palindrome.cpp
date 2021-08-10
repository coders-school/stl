// Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest 
// palindromem. Program powinien ignorować znaki specjalne np. ,.?()[] (i nie tylko). 
// Powinien również ignorować wielkość liter oraz białe znaki jak spacja czy znak nowej linii.

// Wywnioskuj po testach jak nazwać funkcję. Stwórz własne pliki źródłowe i nagłówkowe i dodaj je do CMakeLists.txt, aby się budowały. Szczegóły w README.md do tego zadania.

// Gotowe zadanie zgłoś na gałąź coders-school:insensitive-palindrom.

#include "palindrome.hpp"
#include <algorithm>
#include <cctype>

bool is_palindrome (std::string& str) {
    auto it = std::remove_if (str.begin(), str.end(), [](char letter){return !isalpha (letter);});
    str.erase(it, str.end());
    std::transform (str.begin(), str.end(), str.begin(), [](char letter){return std::toupper(letter);});

    return std::equal(str.begin(), str.begin() + str.size()/2, str.rbegin());
}