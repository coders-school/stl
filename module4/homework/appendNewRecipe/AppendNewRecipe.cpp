#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <map>

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount)
{
    std::fstream file("recipes.txt", std::ios::app | std::ios::in);
    if (file.is_open()) {
        std::string newRecipe = FormatRecipit(steps, ingredients, amount).str();
        file << newRecipe;
        file.close();
        return true;
    }
    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount)
{
    std::vector<std::string> separatedIngredients(ingredients.size());
    const std::map<char, std::string> LEGEND{
        {'g', "gram"},
        {'s', "szklanka(i)"},
        {'m', "mililitrow"}};

    std::transform(ingredients.begin(), ingredients.end(),
                   amount.begin(),
                   separatedIngredients.begin(), [LEGEND](const auto& singleIngredient, const auto& countOfIngredients) {
                       auto legendIterator = LEGEND.find(countOfIngredients.second);
                       std::string separatedIngredient = std::to_string(countOfIngredients.first) + ' ' + legendIterator->second + ' ' + singleIngredient;
                       return separatedIngredient;
                   });

    return separatedIngredients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
{
    std::stringstream ss;
    std::vector<std::string> separatedIngredients = FormatIngredients(ingredients, amount);

    ss << "Skladniki:\n";
    std::for_each(separatedIngredients.begin(), separatedIngredients.end(),
                  [&ss](std::string singleIngredient) {
                      ss << singleIngredient << ",\n";
                  });
    ss << '\n';

    ss << "Kroki:\n";
    unsigned int whichStep = 1;
    std::for_each(steps.begin(), steps.end(),
                  [&ss, whichStep](std::string singleStep) mutable {
                      ss << whichStep << ") " << singleStep << ".\n";
                      whichStep++;
                  });
    ss << "___________________________________\n";
    whichStep = 1;

    return ss;
}