#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>

#include "AppendNewRecipe.hpp"

std::map<char, std::string> ingredientsUnits{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"},
};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipe{"recipes.txt", recipe.out | recipe.app};
    if (recipe.is_open()) {
        recipe << FormatRecipit(steps, ingredients, amount).str();
        recipe.close();
        return true;
    }

    std::cout << "Cannot open file";
    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> vecIngredients;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(vecIngredients),
                   [](const auto& ingredient, const auto& amount) {
                       std::stringstream ingredientsStream;
                       ingredientsStream << amount.first << ' ' << ingredientsUnits.at(amount.second) << ' ' << ingredient;
                       return ingredientsStream.str();
                   });
    return vecIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream recipitStream;
    auto vectorIngredients = FormatIngredients(ingredients, amount);
    recipitStream << "Skladniki:\n";
    std::move(vectorIngredients.begin(), vectorIngredients.end(), std::ostream_iterator<std::string>(recipitStream, ",\n"));
    recipitStream << "\nKroki:\n";
    auto index = 1;
    for (const auto& st : steps) {
        recipitStream << index << ") " << st << ".\n";
        index++;
    }
    recipitStream << std::string(35, '_') << "\n";
    return recipitStream;
}
