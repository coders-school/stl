#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

constexpr char filename[] = "recipes.txt";

bool AppendNewRecipe(std::vector<std::string>& steps, const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    std::fstream file(filename, file.out | file.app);
    const auto formattedRecipe = FormatRecipit(steps, ingridients, amount);

    if (!file.is_open()) {
        return false;
    }

    file << formattedRecipe.str();
    return true;
}

std::vector<std::string> FormatIngridients(const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngridients{};
    const std::map<char, std::string> units = {{'g', "gram"},
                                         {'s', "szklanka(i)"},
                                         {'m', "mililitrow"}};

    std::transform(ingridients.cbegin(), ingridients.cend(), amount.cbegin(), std::back_inserter(formattedIngridients),
                   [&units](const auto& ingridient, const auto& amount) {
                       std::stringstream stream{};
                       stream << amount.first << " " << units.at(amount.second) << " " << ingridient;
                       return stream.str();
                   });

    return formattedIngridients;
}

std::stringstream FormatRecipit(std::vector<std::string>& steps, const std::list<std::string>& ingridients, const std::deque<std::pair<size_t, char>>& amount) {
    const std::string stepsStart = "\nKroki:";
    const std::string ingidientsStart = "Skladniki:\n";
    const std::string breakLine = "\n___________________________________\n";
    std::stringstream output{};

    output << ingidientsStart;
    const auto formattedIngredients = FormatIngridients(ingridients, amount);
    std::copy(formattedIngredients.cbegin(), formattedIngredients.cend(), std::ostream_iterator<std::string>(output, ",\n"));

    output << stepsStart;
    std::for_each(steps.cbegin(), steps.cend(),
                  [counter = 1, &output](const auto& step) mutable {
                      output << "\n"
                             << counter++ << ") " << step << ".";
                  });

    output << breakLine;

    return output;
}