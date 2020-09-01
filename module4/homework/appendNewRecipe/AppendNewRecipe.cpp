#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>

std::map<char, std::string> quantities{{'g', " gram"}, {'s', " szklanka(i)"}, {'m', "ml"}};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipes("recipes.txt", recipes.out | recipes.app);

    if (!recipes.is_open()) {
        return false;
    }

    recipes << FormatRecipit(steps, ingredients, amount).str();

    recipes.close();
    return true;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> vecIngredients;

    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(),
                   std::back_inserter(vecIngredients),
                   [&](const auto& ingredient, const auto& amount) {
                       std::stringstream sstr;
                       sstr << amount.first << quantities[amount.second] << ' ' << ingredient;
                       return sstr.str();
                   });

    return vecIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
}
