#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>

const std::map<char, std::string> units{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> ingredientsVector;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(ingredientsVector),
                   [&](const auto& ingredient, const auto& amount) {
                       std::stringstream ingredientsStream;
                       ingredientsStream << amount.first << ' ' << units.at(amount.second) << ' ' << ingredient;
                       return ingredientsStream.str();
                   });
    return ingredientsVector;
}

std::stringstream FormatRecipe(std::vector<std::string> steps,
                               const std::list<std::string>& ingredients,
                               const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream recipeStream;
    recipeStream << "Skladniki:\n";
    std::vector<std::string> ingredientsVector = FormatIngredients(ingredients, amount);
    for (const auto& ingredient : ingredientsVector) {
        recipeStream << ingredient << ",\n";
    }
    recipeStream << "\nKroki:\n";
    int step = 1;
    for (const auto& it : steps) {
        recipeStream << step << ") " << it << ".\n";
        step++;
    }
    recipeStream << "___________________________________\n";
    return recipeStream;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipe("recipes.txt", recipe.out | recipe.app);
    if (recipe.is_open()) {
        std::stringstream recipesStream = FormatRecipe(steps, ingredients, amount);
        recipe << recipesStream.str();
        recipe.close();
        return true;
    }

    return false;
}
