#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <fstream>
#include <map>

static const std::map<char, std::string> units{{'g', "gram"},
                                               {'s', "szklanka(i)"},
                                               {'m', "mililitrow"}};

bool AppendNewRecipe(const Steps& steps,
                     const Ingredients& ingredients,
                     const Amount& amount) 
{
    const std::string filename{"recipes.txt"};
    std::fstream output(filename, output.out | output.app);
    if (!output.is_open()) {
        return false;
    }
    output << FormatRecipit(steps, ingredients, amount).str();
    output.close();
    return true;
}

FormattedIngredients FormatIngredients(const Ingredients& ingredients,
                                       const Amount& amount)
{
    Steps result;
    result.reserve(ingredients.size());
    auto amount_it = amount.begin();

    std::for_each(ingredients.begin(), ingredients.end(), 
                    [&result, &amount_it](const auto& ingr){
                        std::stringstream preparedIngredient{};
                        preparedIngredient << (*amount_it).first << " "
                                           << units.at((*amount_it).second) << " "
                                           << ingr;
                        result.push_back(preparedIngredient.str());
                        ++amount_it;
    });

    return result;
}

std::stringstream FormatRecipit(const Steps& steps,
                                const Ingredients& ingredients,
                                const Amount& amount)
{
    std::stringstream result;
    FormattedIngredients formIngrs = FormatIngredients(ingredients, amount);
    const std::string ingredientsHeader{"Skladniki:\n"};
    const std::string stepsHeader{"\nKroki:\n"};

    result << ingredientsHeader;
    for (const auto& ingr : formIngrs) {
        result << ingr << ",\n";
    }
    result << stepsHeader;
    for (size_t i = 0; i < steps.size(); i++) {
        result << i + 1 << ") " << steps[i] << ".\n";
    }
    result << std::string(35, '_') << "\n";

    return result;
}
