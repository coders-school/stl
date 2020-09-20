#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <numeric>

static const std::map<char, std::string> measurementUnits{{'g', "gram"},
                                                          {'s', "szklanka(i)"},
                                                          {'m', "mililitrow"}};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<std::size_t, char>>& amount) {
    std::string fileName = "recipes.txt";
    std::fstream recipesStream(fileName, recipesStream.out | recipesStream.app);
    if (!recipesStream.is_open()) {
        return false;
    }
    recipesStream << FormatRecipit(steps, ingredients, amount).str();
    recipesStream.close();
    return true;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<std::size_t, char>>& amount) {
    std::vector<std::string> IngredientsVector;

    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(),
                   std::back_inserter(IngredientsVector),
                   [](const auto& ingredient, const auto& amount) {
                       std::stringstream ss;
                       ss << amount.first << " ";
                       ss << measurementUnits.at(amount.second) << " ";
                       ss << ingredient;
                       return ss.str();
                   });
    return IngredientsVector;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<std::size_t, char>>& amount) {
    std::vector<std::string> Ingredients(FormatIngredients(ingredients, amount));

    std::stringstream recipeStream;
    std::string componentsMessage = "Skladniki:\n";
    recipeStream << componentsMessage;
    std::copy(Ingredients.cbegin(), Ingredients.cend(),
              std::ostream_iterator<std::string>(recipeStream, ",\n"));
    std::string stepMessage = "\nKroki:\n";
    recipeStream << stepMessage;
    std::transform(steps.cbegin(), steps.cend(),
                   std::ostream_iterator<std::string>(recipeStream, "\n"),
                   [counter{1}](const auto& step) mutable {
                       std::stringstream stepStream;
                       stepStream << counter++ << ") " << step << '.';
                       return stepStream.str();
                   });

    recipeStream << "___________________________________\n";
    return recipeStream;
}
