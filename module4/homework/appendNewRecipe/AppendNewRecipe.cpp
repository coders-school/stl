#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>

bool AppendNewRecipe(const std::vector<std::string>& steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::string fileName{"recipes.txt"};
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open()) {
        const auto text = FormatRecipit(steps, ingredients, amount).str();
        file << text;
        file.close();
        return true;
    }
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
                       const auto [amount, unit] = pair;
                       std::string formattedUnit{};
                       switch (unit) {
                           case 'g':
                           formattedUnit = "gram";
                           break;
                           case 's':
                           formattedUnit = "szklanka(i)";
                           break;
                           case 'm':
                           formattedUnit = "mililitrow";
                           break;
                       }
                       std::stringstream temp_stream(std::to_string(amount) + ' ' + formattedUnit + ' ' + ingredient);
                       return temp_stream.str();
                   });
    return formattedIngredients;
}
std::stringstream FormatRecipit(const std::vector<std::string>& steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream stream;
    const std::string ingredientsMessage{"Skladniki:\n"};
    stream << ingredientsMessage;
    auto formattedIngredients = FormatIngredients(ingredients, amount);
    for (auto line : formattedIngredients) {
        stream << line << ",\n";
    }
    const std::string stepsMessage{"\nKroki:\n"};
    stream << stepsMessage;
    for (size_t i = 0; i < steps.size(); ++i) {
        stream << i + 1 << ") " << steps[i] << ".\n";
    }
    const std::string dash{"___________________________________\n"};
    stream << dash;
    return stream;
}
