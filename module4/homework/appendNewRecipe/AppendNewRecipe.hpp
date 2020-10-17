#pragma once

#include <vector>
#include <string>
#include <list>
#include <deque>
#include <sstream>

using IngredientsList = std::list<std::string>;
using UnitsDeque = std::deque<std::pair<size_t, char>>;
using StepList = std::vector<std::string>;
using RecipitList = std::vector<std::string>;

RecipitList FormatIngredients(const IngredientsList&, const UnitsDeque&);
std::stringstream FormatRecipit(const StepList&, const IngredientsList&, const UnitsDeque&);
void AppendNewRecipe(const StepList&, const IngredientsList&, const UnitsDeque&);

