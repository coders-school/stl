#include <fstream>
#include <iostream>
#include "AppendNewRecipe.hpp"

int main() {
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};
    std::vector<std::string> result = FormatIngredients(ingredients, amount);
    // for (auto x : result) {
    //     std::cout << x << "\n";
    // }
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    //AppendNewRecipe(steps, ingredients, amount);
    FormatRecipit(steps, ingredients, amount);
}
