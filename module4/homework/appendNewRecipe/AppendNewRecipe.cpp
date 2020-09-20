#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

constexpr char filename[] = "recipes.txt";
constexpr char ingredientsHeader[] = "Skladniki:";
constexpr char stepsHeader[] = "Kroki:";
constexpr char gram[] = "gram";
constexpr char glass[] = "szklanka(i)";
constexpr char ml[] = "mililitrow";
constexpr char recipeEndMarker[] = "___________________________________";

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount)
{
    std::fstream file(filename, file.out | file.app);
    try {
        if (file.is_open()) {
            file << FormatRecipit(steps, ingredients, amount).str();
            file.close();
            return true;
        }
    } catch (const std::fstream::failure& e) {
        std::cerr << "Cannot open file: " << e.what() << std::endl;
    }
    return false;
}

std::string FormatUnits(char unit)
{
    switch (unit) {
        case 'g':
            return gram;
        case 's':
            return glass;
        case 'm':
            return ml;
        default:
            return {};
    }
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount)
{
    std::vector<std::string> ingredientsVec(ingredients.size());
    auto itIngredients = ingredients.begin();
    auto itAmount = amount.begin();

    std::generate(ingredientsVec.begin(), ingredientsVec.end(), [itIngredients, itAmount]() mutable {
        std::stringstream ingredient;

        ingredient << std::to_string((itAmount)->first);
        ingredient << " ";
        ingredient << FormatUnits(itAmount->second);
        ingredient << " ";
        ingredient << *itIngredients;
        itAmount++;
        itIngredients++;

        return ingredient.str();
    });

    return ingredientsVec;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
{
    std::stringstream recipe;
    auto ingredientsVec = FormatIngredients(ingredients, amount);

    recipe << ingredientsHeader << "\n";
    std::copy(ingredientsVec.begin(), ingredientsVec.end(), std::ostream_iterator<std::string>(recipe, ",\n"));
    recipe << std::endl;
    recipe << stepsHeader << "\n";

    for (auto index = 1; const auto& step : steps) {
        recipe << index << ") " << step << ".\n";
        index++;
    }
    recipe << recipeEndMarker << "\n";

    return recipe;
}
