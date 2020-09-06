#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>

std::vector<std::string> FormatIngredients(
    const std::list<std::string>& ingredients,
    const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngredents{};

    std::transform(
        ingredients.cbegin(), ingredients.cend(), amount.cbegin(),
        std::back_inserter(formattedIngredents),
        [](const std::string ing, const std::pair<size_t, char> amount) -> std::string {
            switch (amount.second) {
            case 'g':
                return std::to_string(amount.first) + GRAM + ing;
            case 'm':
                return std::to_string(amount.first) + MILILITRES + ing;
            case 's':
                return std::to_string(amount.first) + GLASSES + ing;
            default:
                return "NaN";
            }
        });
    return formattedIngredents;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    auto ss = FormatRecipit(steps, ingredients, amount);
    std::fstream recipes("recipes.txt", recipes.out | recipes.app);
    if (recipes.is_open()) {
        recipes << ss.str();
        recipes.close();
        return true;
    }
    return false;
};

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::string dash(35, '_');
    std::stringstream ss;
    auto formattedIngredients = FormatIngredients(ingredients, amount);

    ss << "Skladniki:\n";
    for (auto& el : formattedIngredients) {
        ss << el << ",\n";
    }
    ss << "\nKroki:\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        ss << std::to_string(i + 1) << ") " << steps[i] << ".\n";
    }
    ss << dash << "\n";
    return ss;
};
