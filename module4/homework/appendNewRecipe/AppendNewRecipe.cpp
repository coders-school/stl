#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <deque>
#include <list>
#include <sstream>
#include <string>
#include <vector>

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    return true;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> res;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(res),
                   [](const auto ingredient, const auto amount) -> std::string {
                       return std::to_string(amount.first) + ConstStrings::ingredientMap[amount.second] + ingredient;
                   });

    return res;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    ss << ConstStrings::ingredientHeader;

    for (const auto& row : FormatIngredients(ingredients, amount)) {
        ss << row << ConstStrings::ingredientSeparator;
    }

    ss << ConstStrings::stepsHeader;

    for (size_t i = 0; i < steps.size(); i++) {
        ss << std::to_string(i + 1) << ") " << steps[i] << ConstStrings::stepsSeparator;
    }
    ss << ConstStrings::recipeSeparator;

    return ss;
}