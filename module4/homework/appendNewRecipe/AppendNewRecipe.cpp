#include "AppendNewRecipe.hpp"

#include <algorithm>
#include <iostream>
#include <map>

std::map<char, std::string> units{
    {'g', "gram"},
    {'s', "szklanka(i)"},
    {'m', "mililitrow"}};

bool AppendNewRecipe(VecStr steps, const ListStr& ingredients, const DequeSizetChar& amount) {
    return false;
}

std::stringstream FormatRecipit(VecStr steps, const ListStr& ingredients, const DequeSizetChar& amount) {
    return {};
}

VecStr FormatIngredients(const ListStr& ingredients, const DequeSizetChar& amount) {
    VecStr result{};
    size_t  i = 0;
    for (const auto& ingredient : ingredients) {
        std::ostringstream oss{};
        oss << amount[i].first << ' ' << units[amount[i].second] << ' ' << ingredient;
        result.push_back(oss.str());
        i++;
    }
    
    return result;
}
