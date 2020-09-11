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
                   [](const auto& ingredient, const auto& pair) {
                       auto [amount, unit] = pair;
                       std::string formattedUnit{};
                       if (unit == 'g') {
                           formattedUnit = "gram";
                       }
                       if (unit == 's') {
                           formattedUnit = "szklanka(i)";
                       }
                       if (unit == 'm') {
                           formattedUnit = "ml";
                       }
                       if (formattedUnit == "ml") {
                           return std::to_string(amount) + formattedUnit + ' ' + ingredient;
                       }
                       return std::to_string(amount) + ' ' + formattedUnit + ' ' + ingredient;
                   });
    return formattedIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream stream;
    stream << "Skladniki:\n";
    auto formattedIngredients = FormatIngredients(ingredients, amount);
    for (auto line : formattedIngredients) {
        stream << line << ",\n";
    }
    stream << '\n';
    stream << "Kroki:\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        stream << i + 1 << ") " << steps[i] << ".\n";
    }
    return stream;
}
