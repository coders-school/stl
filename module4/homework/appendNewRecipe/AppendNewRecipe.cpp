#include <algorithm>
#include <iterator>

#include <iostream>

#include "AppendNewRecipe.hpp"

bool AppendNewRecipeconst(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    return true;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> result;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(result),
    [&](auto& ingredient, auto am){
        std::stringstream ss;
        ss << am.first << convertEnumToString(am.second) << " " << ingredient;
        return ss.str();
    });
    /*for (const auto& it: result)
        std::cout << "ooooooooooo" << it << '\n';*/
    return result;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    ss << "Składniki:\n";
    std::vector<std::string> ingred = FormatIngredients(ingredients, amount);
    for (const auto& it: ingred) {
        ss << it << '\n';
    }

    return ss;
}

std::string convertEnumToString(char c) {
    switch (c)
    {
    case 'g':
        return " gram";
        break;
    case 'm':
        return "ml";
        break;
    case 's':
        return " szklanka(i)";
        break;
    default:
        break;
    }
    return "error";
}