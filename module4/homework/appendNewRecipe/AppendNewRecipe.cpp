#include "AppendNewRecipe.hpp"

#include <fstream>
#include <iostream>

constexpr char filename[] = "recipes.txt";
constexpr char ingredientsHeader[] = "Skladniki:";
constexpr char stepsHeader[] = "Kroki:";
constexpr char gram[] = "gram";
constexpr char glass[] = "szklanka(i)";
constexpr char ml[] = "mililitrow";

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

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount)
{
    // ToDo
    return {};
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
{
    // ToDo
    return {};
}
