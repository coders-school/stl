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
        std::string recentIngredient{};
        recentIngredient += std::to_string(amount[i].first);

        if (amount[i].second == 'g') {
            recentIngredient += " gram ";
        } else if (amount[i].second == 's') {
            recentIngredient += " szklanka(i) ";
        } else if (amount[i].second == 'm') {
            recentIngredient += " mililitrow ";
        }
        recentIngredient += *it;

        result.push_back(recentIngredient);
        it++;
    }

    return result;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    std::vector<std::string> formattedIngredients = FormatIngredients(ingredients, amount);

    ss << "Skladniki:\n";
    for (auto el : formattedIngredients) {
        ss << el << ',' << '\n';
    }
    ss << "\nKroki:\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        ss << std::to_string(i + 1) << ") " << steps[i] << ".\n";
    }

    ss << "___________________________________\n";
    return ss;
}

/*
std::fstream diary("Day1.txt", diary.out | diary.app);
// or longer -> std::ifstream::out | std::ifstream::app
if (diary.is_open()) {
    std::cout << "OPENED!\n";
    diary << "Today is my first day on ship, with my crew\n";
    diary << "I'm a little scared!\n";
    diary << "Hope it will be a marvelous adventure.\n";
    diary.close();
}
*/

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    //std::ofstream ofs("receipe.txt", std::ios_base::app);
    std::fstream ofs("receipe.txt", ofs.out | ofs.app);
    //ofs.open("receipe.txt", std::ios_base::app);
    std::stringstream ss = FormatRecipit(steps, ingredients, amount);
    if (!ofs) {
        return false;
    }

    if (ofs.is_open()) {
        ofs << ss.str();
        ofs.close();
    }

    return true;
}
