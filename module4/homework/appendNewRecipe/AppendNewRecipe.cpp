#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>

std::map<char, std::string> amountCode{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngredients;
    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(), std::back_inserter(formattedIngredients),
                   [](const auto& ingredient, const auto& amount) {
                       std::stringstream ss;
                       ss << amount.first << " ";
                       ss << amountCode.at(amount.second) << " ";
                       ss << ingredient;
                       return ss.str();
                   });

    return formattedIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    std::vector<std::string> formattedIngredients = FormatIngredients(ingredients, amount);

    ss << "Skladniki:\n";
    for (auto el : formattedIngredients) {
        ss << el << ',' << '\n';
    }
    ss << "\nKroki:\n";
    for (size_t i = 0; i < steps.size(); ++i) {
        ss << std::to_string(i + 1) << ") " << steps[i] << ".\n";
    }

    ss << "___________________________________\n";
    return ss;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream ofs("recipes.txt", ofs.out | ofs.app);
    if (ofs.is_open()) {
        std::stringstream ss = FormatRecipit(steps, ingredients, amount);
        ofs << ss.str();
        ofs.close();
        return true;
    }
    return false;
}
