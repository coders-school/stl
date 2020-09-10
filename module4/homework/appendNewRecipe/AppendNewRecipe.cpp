#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

const char filename[] = "recipes.txt";

bool AppendNewRecipe(std::vector<std::string> steps, const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream file(filename, file.out | file.app);
    auto formattedRecipe = FormatRecipit(steps, ingridients, amount);

    if (!file.is_open()) {
        return false;
    }

    file << formattedRecipe.str();
    return true;
}

std::vector<std::string> FormatIngridients(const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngridients{};
    std::map<char, std::string> units = {{'g', "gram"},
                                         {'s', "szklanka(i)"},
                                         {'m', "mililitrow"}};

    std::transform(ingridients.begin(), ingridients.end(), amount.begin(), std::back_inserter(formattedIngridients),
                   [&units](const auto& ingridient, const auto& amount) {
                       std::stringstream stream{};
                       stream << amount.first << " " << units[amount.second] << " " << ingridient;
                       return stream.str();
                   });

    return formattedIngridients;
}

std::stringstream FormatRecipit(std::vector<std::string> steps, const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    const std::string stepsStart = "\n\nKroki:";
    const std::string ingidientsStart = "Skladniki:";

    std::stringstream output{};
    output << ingidientsStart;
    auto formattedIngredients = FormatIngridients(ingridients, amount);
    std::for_each(formattedIngredients.begin(), formattedIngredients.end(),
                  [&output](const auto& ingridient) {
                      output << "\n"
                             << ingridient << ",";
                  });
    output << stepsStart;

    std::for_each(steps.begin(), steps.end(),
                  [counter = 1, &output](const auto& step) mutable {
                      output << "\n"
                             << counter << ") " << step << ".";
                      counter++;
                  });
    output << "\n___________________________________\n";

    return output;
}