#pragma once

#include <deque>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using VecStr = std::vector<std::string>;
using ListStr = std::list<std::string>;
using DeqSizetChar = std::deque<std::pair<size_t, char>>;

bool AppendNewRecipe(VecStr steps, const ListStr& ingredients, const DeqSizetChar& amount);
VecStr FormatIngredients(const ListStr& ingredients, const DeqSizetChar& amount);
std::stringstream FormatRecipit(VecStr steps, const ListStr& ingredients, const DeqSizetChar& amount);
