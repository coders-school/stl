#pragma once

#include <deque>
#include <list>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using Steps = std::vector<std::string>;
using FormattedIngredients = std::vector<std::string>;
using Ingredients = std::list<std::string>;
using Amount = std::deque<std::pair<size_t, char>>;

bool AppendNewRecipe(const Steps& steps,
                     const Ingredients& ingredients,
                     const Amount& amount);

FormattedIngredients FormatIngredients(const Ingredients& ingredients,
                                       const Amount& amount);

std::stringstream FormatRecipit(const Steps& steps,
                                const Ingredients& ingredients,
                                const Amount& amount);
