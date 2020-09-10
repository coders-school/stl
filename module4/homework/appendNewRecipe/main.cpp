#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "AppendNewRecipe.hpp"

int main() {
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    auto s = FormatRecipit(steps, ingredients, amount);

    std::cout << s.str();
}