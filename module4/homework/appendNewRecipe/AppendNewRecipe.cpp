#include "AppendNewRecipe.hpp"

#include <algorithm>

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    if (ingredients.size() != amount.size()) {
        return {};
    }
    std::vector<std::string> formattedIngredients(ingredients.size());
    std::transform(begin(ingredients),
                   end(ingredients),
                   begin(amount),
                   begin(formattedIngredients),
                   [](const auto& ingredient, const auto& pair) 
                   {
                       auto [amount, unit] = pair;
                       return std::to_string(amount) + unit + ' ' + ingredient;
                   });
    return formattedIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    return {};
}
