#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <utility>

using vecOfStrings = std::vector<std::string>;
using listOfStrings = std::list<std::string>;
using dequeOfPairs = std::deque<std::pair<size_t, char>>;

bool AppendNewRecipe(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount);

//std::vector<std::string> FormatIngredients(const listOfStrings& ingredients, const dequeOfPairs& amount);

//std::stringstream FormatRecipit(vecOfStrings steps, const listOfStrings& ingredients, const dequeOfPairs& amount);
