#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

int main() {
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                 "Dorzucic 1 szklanke maki",
                                 "Dokladnie wymieszac",
                                 "Nalac 40ml rumu do kieliszka",
                                 "Wypic kieliszek",
                                 "Wysypac zawartosc miski"};
  std::list<std::string> ingredients{"cukru", "maki", "rumu"};
  std::deque<std::pair<size_t, char>> amount{{20, 'g'}, {1, 's'}, {40, 'm'}};

  AppendNewRecipe(steps, ingredients, amount);

  return 0;
}
