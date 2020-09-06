#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>

const std::map<char, std::string> quantities{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    constexpr auto filename = "recipes.txt";
    std::fstream recipes(filename, recipes.out | recipes.app);

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
                       sstr << amount.first << ' ' << quantities.at(amount.second) << ' ' << ingredient;
                       return sstr.str();
                   });

    return vecIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream recipit;
    std::vector<std::string> vecIngedients = FormatIngredients(ingredients, amount);

    constexpr auto ingredientsMessage = "Skladniki:\n";
    recipit << ingredientsMessage;
    std::copy(vecIngedients.cbegin(), vecIngedients.cend(), std::ostream_iterator<std::string>(recipit, ",\n"));

    constexpr auto stepsMessage = "\nKroki:\n";
    recipit << stepsMessage;
    std::transform(steps.cbegin(), steps.cend(),
                   std::ostream_iterator<std::string>(recipit, "\n"),
                   [counter{1}](const auto& step) mutable {
                       std::stringstream sstr;
                       sstr << counter++ << ") " << step << '.';
                       return sstr.str();
                   });
    recipit << "___________________________________\n";

    return recipit;
}
