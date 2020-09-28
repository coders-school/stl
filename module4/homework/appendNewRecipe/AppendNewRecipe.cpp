#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>

const std::string fileName{"recipes.txt"};
const std::string glassPl{"szklanka(i)"};
const std::string gramPl{"gram"};
const std::string ingredientsPl{"Skladniki:"};
const std::string mlPl{"mililitrow"};
const std::string separatorRecipe(35, '_');
const std::string separatorStep{".\n"};
const std::string stepsPl{"Kroki:"};

std::map<char, std::string> translateUnits {
    {'g', gramPl},
    {'s', glassPl},
    {'m', mlPl},
};

bool AppendNewRecipe(const std::vector<std::string>& steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    
    std::fstream file(fileName, file.out | file.app);
    try {
        if (file.is_open()) {
            file << FormatRecipit(steps, ingredients, amount).str();
            file.close();
            return true;
        }
    } catch (const std::fstream::failure& e) {
        std::cerr << "Can't open this file: " << e.what() << '\n';
    }
    return false;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {

    std::vector<std::string> vecOfIngredients(ingredients.size());
    std::generate(vecOfIngredients.begin(), 
                  vecOfIngredients.end(), 
                  [itIngredients = ingredients.begin(), itAmount = amount.begin()]() mutable {
                      std::stringstream ingredient;
                      ingredient << std::to_string((itAmount)->first) << " ";
                      ingredient << translateUnits[itAmount->second] << " ";
                      ingredient << *itIngredients;
                      itAmount++;
                      itIngredients++;
                      return ingredient.str();
    });
    return vecOfIngredients;
}

std::stringstream FormatRecipit(const std::vector<std::string>& steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {

    std::stringstream recipe;
    auto vecOfIngredients = FormatIngredients(ingredients, amount);
    recipe << ingredientsPl << '\n';
    std::move(vecOfIngredients.cbegin(), vecOfIngredients.cend(), std::ostream_iterator<std::string>(recipe, ",\n"));
    recipe << '\n' << stepsPl << '\n';
    auto stepNumber = 1;
    for (const auto& step : steps) {
        recipe << stepNumber << ") " << step << separatorStep;
        stepNumber++;
    }
    recipe << separatorRecipe << '\n';
    return recipe;
}