#include <iostream>

#include "recipeAppend.hpp"

bool appendNewRecipe(const std::string& filename,
                     const std::vector<std::string>& formattedIngredients,
                     const std::stringstream& formattedRecipe) {
    std::fstream recipe(filename, recipe.out | recipe.app);
    if (recipe.is_open()) {
        for(const auto& el : formattedIngredients) {
            recipe << el << '\n';
        }
        recipe << formattedRecipe.rdbuf() << '\n';
        recipe.close();
    } else {
        std::cerr << "File open error!" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> formatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> formattedIngredients;
    
    formattedIngredients.emplace_back("Skladniki:");
    
    auto it = ingredients.begin();
    for (size_t i = 0; i < ingredients.size(); i++) {
        std::string ingrid = std::to_string(amount.at(i).first);
        char unit = amount.at(i).second;
        if (unit == 'g') {
            ingrid += " gram ";
        } else if (unit == 's') {
            ingrid += " szklanka(i) ";
        } else if (unit == 'm') {
            ingrid += " mililitrow ";
        }
        ingrid += *(it++);
        formattedIngredients.emplace_back(ingrid);
    }

    return formattedIngredients;
}

std::stringstream formatRecipe(const std::vector<std::string>& steps) {
    std::stringstream formattedRecipe;

    formattedRecipe << "\nKroki:\n";
    for (size_t i = 0; i < steps.size(); i++) {
        formattedRecipe << i + 1 << ") " << steps.at(i) << ".\n";
    }

    return formattedRecipe;
}
