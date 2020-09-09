#include "AppendNewRecipe.hpp"

#include <fstream>
#include <map>

std::map<char, std::string> units{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"}};

bool AppendNewRecipe(VecStr steps, const ListStr& ingredients, const DeqSizetChar& amount) {
    auto newRecipe = (FormatRecipit(steps, ingredients, amount)).str();

    std::fstream file("recipes.txt", file.app);
    if (file.is_open()) {
        file << newRecipe;
        file.close();
        return true;
    }
    
    return false;
}

std::stringstream FormatRecipit(VecStr steps, const ListStr& ingredients, const DeqSizetChar& amount) {
    auto formatedIngredients = FormatIngredients(ingredients, amount);
    std::stringstream result{};
    result << "Skladniki:\n";
    for(const auto& ingredient : formatedIngredients) {
        result << ingredient << ',' << '\n';
    }
    result << "\nKroki:";
    size_t i = 1;
    for(const auto& step : steps) {
        result << '\n' << i << ") " << step << '.';
        i++;
    }
    result << "\n___________________________________\n";
    
    return result;
}

VecStr FormatIngredients(const ListStr& ingredients, const DeqSizetChar& amount) {
    VecStr result{};
    size_t i = 0;
    for (const auto& ingredient : ingredients) {
        std::stringstream ss{};
        ss << amount[i].first << ' ' << units[amount[i].second] << ' ' << ingredient;
        result.push_back(ss.str());
        i++;
    }
    
    return result;
}
