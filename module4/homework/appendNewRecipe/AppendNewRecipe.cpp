#include "AppendNewRecipe.hpp"

#include <iostream>
/*
INPUT
std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                "Dorzucić 1 szklankę mąki",
                                "Dokładnie wymieszać",
                                "Nalać 40ml rumu do kieliszka",
                                "Wypić kieliszek",
                                "Wysypać zawartość miski"};
std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
std::deque<std::pair<size_t, char>> amount{
    {20, 'g'},
    {1, 's'},
    {40, 'm'}};

*/

/*
Output:(textfile)
Składniki:
20 gram cukru,
1 szklanka(i) mąki,
40ml rumu,

Kroki:
1) Wsypać do miski 20 gram cukru.
2) Dorzucić 1 szklankę mąki.
3) Dokładnie wymieszać.
4) Nalać 40ml rumu do kieliszka.
5) Wypić kieliszek.
6) Wysypać zawartość miski.


*/

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> result;
    auto it = ingredients.begin();
    for (size_t i = 0; i < ingredients.size(); ++i) {
        std::string xx{};
        xx += std::to_string(amount[i].first);

        if (amount[i].second == 'g') {
            xx += " gram ";
        } else if (amount[i].second == 's') {
            xx += " szklanka(i) ";
        } else if (amount[i].second == 'm') {
            xx += " mililitrow ";
        }
        xx += *it;

        result.push_back(xx);
        std::cout<<xx<<'\n';
        it++;
    }

    return result;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss{"abc"};
    ss << "abc";
    return ss;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::ofstream ofs{"receipe.txt"};
    if (!ofs) {
        return false;
    }
    return true;
}
