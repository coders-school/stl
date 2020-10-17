#include "AppendNewRecipe.hpp"
#include <map>
#include <fstream>

const std::map<char, std::string> UNITS_NAMES{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"}
};

RecipitList FormatIngredients(IngredientsList& ingredients, UnitsDeque& units){
    if(ingredients.size() != units.size())
        return {};
    
    RecipitList result;
    size_t counter{0};

    for (auto & ingredient: ingredients)
    {
        auto unit = units[counter++];
        auto text = std::to_string(unit.first) + ' ' + UNITS_NAMES.at(unit.second) + ' ' + ingredient;
        
        result.push_back(text);  
    }
    
    return result;
}

std::stringstream FormatRecipit(StepList& steps, IngredientsList& ingredients, UnitsDeque& units){
    std::stringstream output;

    output << "Skladniki:" << '\n';

    for(auto & ingredient: FormatIngredients(ingredients, units)){
        output << ingredient << ',' << '\n';
    }

    output << '\n' << "Kroki:" << '\n';

    size_t counter{1};
    for(auto & step: steps){
        output << counter++ << ") ";
        output << step << '.' << '\n';
    }
    
    output << std::string(35, '_') << '\n';

    return output;
}

void AppendNewRecipe(StepList& steps, IngredientsList& ingredients, UnitsDeque& units){
    std::fstream file("recipes.txt", file.out | file.app);

    if(file.is_open()){
        file << FormatRecipit(steps, ingredients, units).rdbuf();
        file.close();
    }
}
