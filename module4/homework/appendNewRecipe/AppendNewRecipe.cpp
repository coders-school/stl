#include "AppendNewRecipe.hpp"

#include <algorithm>
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
    
    auto op = [&result](const auto& ingredient, const auto& amount) {
        std::stringstream ss{};
        ss << amount.first << ' ' << units[amount.second] << ' ' << ingredient;
        return ss.str();
    };

    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(), std::back_inserter(result), op);
    
    return result;
}
