
#include "AppendNewRecipe.hpp"

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
{
    std::stringstream ss;
    ss << "DDDDD";
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount)
{
    return {"AA", "BB"};
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount)
{
    return true;
}


