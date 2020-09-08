#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <map>

bool AppendNewRecipe(const std::vector<std::string>& steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::ofstream file("recipes.txt");
    if (file.is_open()) {
        std::stringstream ss = FormatRecipit(steps, ingredients, amount);
        file << ss.str();

        file.close();
        return true;
    }
    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::map<char, std::string> dimensions{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

    std::vector<std::string> vec;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(vec),
                   [&dimensions](const auto& ingr, const auto& amo) {
                       std::string str = std::to_string(amo.first);
                       str += " ";
                       str += dimensions[amo.second];
                       str += " ";
                       str += ingr;
                       return str;
                   });

    return vec;
}

std::stringstream FormatRecipit(const std::vector<std::string>& steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> all_ingredients = FormatIngredients(ingredients, amount);

    std::stringstream ss;
    ss << "Skladniki:\n";

    for (const auto& word : all_ingredients) {
        ss << word << ",\n";
    }
    ss << "\nKroki:\n";

    for (int i = 0; i < steps.size(); ++i) {
        ss << i + 1 << ") " << steps[i] << ".\n";
    }

    return ss;
}
