#pragma once

#include <deque>
#include <list>
#include <sstream>
#include <string>
#include <vector>

bool AppendNewRecipe(const std::vector<std::string>& steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(const std::vector<std::string>& steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
