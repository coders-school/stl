#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>

constexpr char fileName[] = "recipes.txt";

const std::map<char, std::string> units{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"}};

bool AppendNewRecipe(VecStr steps, const ListStr& ingredients, const DeqSizetChar& amount) {
    auto newRecipe = (FormatRecipit(steps, ingredients, amount)).str();

    std::fstream file(fileName, file.app);
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
    std::copy(formatedIngredients.cbegin(), formatedIngredients.cend(), std::ostream_iterator<std::string>(result, ",\n"));
    
    result << "\nKroki:";
    size_t i = 1;
    for(const auto& step : steps) {
        result << '\n' << i++ << ") " << step << '.';
    }
    result << "\n___________________________________\n";
    
    return result;
}

VecStr FormatIngredients(const ListStr& ingredients, const DeqSizetChar& amount) {
    VecStr result{};

    auto op = [&result](const auto& ingredient, const auto& amount) {
        std::stringstream ss{};
        ss << amount.first << ' ' << units.at(amount.second) << ' ' << ingredient;
        return ss.str();
    };

    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(), std::back_inserter(result), op);
    
    return result;
}
