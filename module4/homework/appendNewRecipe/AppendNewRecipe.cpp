#include <algorithm>
#include <fstream>
#include <iterator>

#include <iostream>

#include "AppendNewRecipe.hpp"

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipes("recipes.txt", recipes.out | recipes.app);
    if (recipes.is_open()) {
        std::cout << FormatRecipit(steps, ingredients, amount).str();
        recipes << FormatRecipit(steps, ingredients, amount).str();
        recipes.close();
        return true;
    }

    return false;
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
    return result;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    ss << "Skladniki:\n";
    std::vector<std::string> ingred = FormatIngredients(ingredients, amount);
    for (const auto& it: ingred) {
        ss << it << ",\n";
    }
    ss << "\nKroki:\n";
    short counter = 1;
    for (const auto& it: steps) {
        ss << counter << ") " << it << ".\n";
        counter++;
    }
    ss << "___________________________________\n";
    return ss;
}

std::string convertEnumToString(char c) {
    switch (c)
    {
    case 'g':
        return " gram";
        break;
    case 'm':
        return " mililitrow";
        break;
    case 's':
        return " szklanka(i)";
        break;
    default:
        break;
    }
    return "error";
}