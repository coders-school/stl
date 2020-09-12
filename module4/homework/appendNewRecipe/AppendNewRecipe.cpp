#include "AppendNewRecipe.hpp"

#include <fstream>

bool AppendNewRecipe(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount){
    std::fstream recipes{"../recipes.txt", recipes.out};

    if(recipes.is_open()){
        std::cout << "Opened!\n";

        recipes << "Składniki: \n";
        auto it = ingredients.begin();
        for(size_t i = 0; i < ingredients.size(); i++){
            recipes << std::to_string(amount[i].first);

            if(amount[i].second == 'g')
                recipes << " gram ";
            else if(amount[i].second == 's')
                recipes << " szklanka(i) ";
            else if(amount[i].second == 'm')
                recipes << "ml ";

            recipes << *it++ << "\n";
        }
        recipes << "Kroki: \n";
        for(size_t i = 0; i < steps.size(); i++){
            recipes << i + 1 << ") " << steps[i] << "\n";
        }
        recipes.close();
        return true;
    }

    return false;
}

//std::vector<std::string> FormatIngredients(const listOfStrings& ingredients, const dequeOfPairs& amount){
//}

//std::stringstream FormatRecipit(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount){
//
//}
