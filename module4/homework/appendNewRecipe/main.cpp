#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount) {
    const std::map<char, std::string> converter{
        {'g', "gram"},
        {'m', "mililitrów"},
        {'s', "szklanka(i)"}};

    std::vector<std::string> vec(ingredients.size());
    std::transform(cbegin(ingredients), cend(ingredients), cbegin(amount), begin(vec),
                   [&](const auto& ingredient, const auto& amount) {
                       return std::to_string(amount.first) + " " + converter.at(amount.second) + " " + ingredient;
                   });

    return vec;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    auto formated_ingredients = FormatIngredients(ingredients, amount);
    std::stringstream ss;

    ss << "Składniki:\n";
    std::copy(begin(formated_ingredients), end(formated_ingredients),
              std::ostream_iterator<std::string>(ss, ",\n"));

    std::transform(begin(steps), end(steps), begin(steps),
                   [counter{1}](const auto& step) mutable {
                       return std::to_string(counter++) + ") " + step;
                   });

    ss << "\nKroki:\n";
    std::copy(begin(steps), end(steps), std::ostream_iterator<std::string>(ss, ".\n"));
    ss << std::string(35, '_') << '\n';

    return ss;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::ofstream file("recipes.txt", file.app);
    if (!file.is_open())
        return false;

    file << FormatRecipit(steps, ingredients, amount).str();
    file.close();
    return true;
}

int main() {
    std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                   "Dorzucić 1 szklanke mąki",
                                   "Dokładnie wymieszać",
                                   "Nalać 40ml rumu do kieliszka",
                                   "Wypić kieliszek",
                                   "Wysypac zawartośc miski"};
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    AppendNewRecipeconst(steps, ingredients, amount);


    std::ifstream file("recipes.txt");
    std::stringstream ss;
    while (file >> ss) {
    }
}