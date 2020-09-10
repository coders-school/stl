#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>

const std::map<char, std::string> amountCode{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};
const std::string ingredientsMessage{"Skladniki"};
const std::string stepMessage{"Kroki"};

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
    std::vector<std::string> formattedIngredients = FormatIngredients(ingredients, amount);
    std::stringstream ss;
    ss << ingredientsMessage << ":\n";
    std::copy(formattedIngredients.begin(), formattedIngredients.end(), std::ostream_iterator<std::string>(ss, ",\n"));
    ss << "\n"<< stepMessage << ":\n";

    std::for_each(steps.begin(), steps.end(),
                  [count = 1, &ss](const auto& step) mutable {
                      ss << std::to_string(count) << ") " << step << ".\n";
                      count++;
                  });

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
