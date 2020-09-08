#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <sstream>

constexpr char FILE_PATH[] = "recipes.txt";
constexpr char INGREDIENTS_MESSAGE[] = "Skladniki:\n";
constexpr char STEPS_MESSAGE[] = "\nKroki:\n";

const std::map<char, std::string> mapOfMeasures{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"}};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream recipes(FILE_PATH, recipes.out | recipes.app);

    if (recipes.is_open()) {
        std::stringstream ss = FormatRecipit(steps, ingredients, amount);
        recipes << ss.str();
        recipes.close();

        return true;
    }

    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngredients{};

    std::transform(ingredients.cbegin(), ingredients.cend(), amount.cbegin(), std::back_inserter(formattedIngredients),
                   [](const std::string ingredient, const std::pair<size_t, char> amount) {
                       std::stringstream ss;
                       ss << amount.first << " " << mapOfMeasures.at(amount.second) << " " << ingredient;

                       return ss.str();
                   });

    return formattedIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngredients = FormatIngredients(ingredients, amount);
    std::stringstream formattedRecipit{};

    formattedRecipit << INGREDIENTS_MESSAGE;
    std::copy(formattedIngredients.cbegin(), formattedIngredients.cend(), std::ostream_iterator<std::string>(formattedRecipit, ",\n"));

    formattedRecipit << STEPS_MESSAGE;
    std::transform(steps.cbegin(), steps.cend(), std::ostream_iterator<std::string>(formattedRecipit, "\n"),
                   [counter{0}](std::string sentence) mutable {
                       std::stringstream ss;
                       ss << ++counter << ") " << sentence << ".";

                       return ss.str();
                   });

    const uint8_t dashesLineLength = 35;
    std::string dash(dashesLineLength, '_');
    formattedRecipit << dash << '\n';

    return formattedRecipit;
}
