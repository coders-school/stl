#include <algorithm>
#include <iterator>

#include "AppendNewRecipe.hpp"

bool AppendNewRecipeconst(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    return true;
}

const std::map<char, std::string> quantities{{'g', "gram"}, {'s', "szklanka(i)"}, {'m', "mililitrów"}};

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> result;
    std::transform(ingredients.begin(), ingredients.end(), amount.begin(), std::back_inserter(result),
    [&](auto& ingredient, auto am){
        std::stringstream ss;
        ss << am.first << " " << convertEnumToString(am.second) << " " << ingredient;
        return ss.str();
    });
    return result;
}

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    return ss;
}

std::string convertEnumToString(char c) {
    switch (c)
    {
    case 'g':
        return "gram";
        break;
    case 'm':
        return "mililitry";
        break;
    case 's':
        return "szklanka";
        break;
    default:
        break;
    }
    return "error";
}