#include "AppendNewRecipe.hpp"

bool AppendNewRecipeconst(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    return true;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount) {
    std::vector<std::string> result {};
    for (auto it = 0; it < ingredients.size(); it++) {
        result[it] += amount[it].first;
        result[it] += " ";
        result[it] += convertEnumToString(amount[it].second);
        result[it] += " ";
        auto itIngredients = ingredients.begin();
        std::advance(itIngredients, it);
        result[it] += *itIngredients;
        result[it] += ",";
    }
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
        return "szklanki";
        break;
    default:
        break;
    }
    return "error";
}