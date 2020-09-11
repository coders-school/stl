#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <map>
const std::map<char, std::string> ingredientsUnits{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> ingredientsResult;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(ingredientsResult),
                   [&](const auto& ingredient, const auto& amount) {
                       std::stringstream ingredientsStream;
                       ingredientsStream << amount.first << ' ' << ingredientsUnits.at(amount.second) << ' '
                                         << ingredient;
                       return ingredientsStream.str();
                   });
    return ingredientsResult;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream recipeStream;

    recipeStream << "Skladniki:\n";
    std::vector<std::string> FormattedIngredients = FormatIngredients(ingredients, amount);
    for_each(FormattedIngredients.begin(), FormattedIngredients.end(),
             [&recipeStream](const auto& ingredient) { recipeStream << ingredient << ",\n"; });
    recipeStream << "\nKroki:\n";
    int step = 1;
    for_each(steps.begin(), steps.end(), [&step, &recipeStream](auto element) {
        recipeStream << step << ") " << element << ".\n";
        step++;
    });
    recipeStream << std::string(35, '_') << "\n";
    return recipeStream;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipe("recipes.txt", recipe.out | recipe.app);
    if (recipe.is_open()) {
        std::stringstream recipesStream = FormatRecipit(steps, ingredients, amount);
        recipe << recipesStream.str();
        recipe.close();
        return true;
    }

    return false;
}