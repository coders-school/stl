#include "AppendNewRecipe.hpp"

#include <iostream>
#include <fstream>

bool AppendNewRecipe(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount){
    std::fstream recipes{"recipes.txt", recipes.out};

    try {
        if (recipes.is_open()) {
            std::cout << "Opened!\n";
            recipes << FormatRecipit(steps, ingredients, amount).str();
            recipes.close();
            return true;
        }
    } catch (std::invalid_argument){
        std::cerr << "Cannot open file";
    }

    return false;
}

vecOfStrings FormatIngredients(const listOfStrings& ingredients, const dequeOfPairs& amount){
    if(ingredients.size() == amount.size()){

        vecOfStrings formattedIngredients;
        formattedIngredients.resize(ingredients.size());
        auto amountIt = amount.begin();
        auto ingredientsIt = ingredients.begin();

        for(auto& ingredient : formattedIngredients){
            switch(amountIt->second){
                case 'g':
                    ingredient.append(std::to_string(amountIt->first) + " gram ");
                    break;
                case 's':
                    ingredient.append(std::to_string(amountIt->first) + " szklanka(i) ");
                    break;
                case 'm':
                    ingredient.append(std::to_string(amountIt->first) + " mililitrów ");
                    break;
                default:
                    ingredient.append("Bad data ");
            }
            ingredient.append(*ingredientsIt);
            ingredientsIt++;
            amountIt++;
        }
        return formattedIngredients;
    } else {
        throw std::invalid_argument("Ingredient's list size does not equal to amount's deque size");
    }
}

std::stringstream FormatRecipit(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount){
    vecOfStrings formattedIngredients = FormatIngredients(ingredients, amount);
    std::stringstream formattedRecipit;

    if(formattedIngredients.size() == amount.size()){
        formattedRecipit << "Składniki:\n";
        for(const auto& ingredients : formattedIngredients){
            formattedRecipit << ingredients << ',' << '\n';
        }
        formattedRecipit << "\nKroki:\n";
        int index = 1;
        for(const auto& step : steps){
            formattedRecipit << index++ << ") " << step << ".\n";
        }
        formattedRecipit << std::string underscores(36, '_') << '\n';
        return formattedRecipit;
    } else{
        throw std::invalid_argument("Ingredient's list size does not equal to amount's deque size");
    }
}
