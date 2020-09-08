#pragma once

#include <deque>
#include <list>
#include <string>
#include <vector>

bool AppendNewRecipe(std::vector<std::string>,
                     const std::list<std::string>&,
                     const std::deque<std::pair<size_t, char>>&);

std::vector<std::string> FormatIngredients(const std::list<std::string>&,
                                           const std::deque<std::pair<size_t, char>>&);

std::stringstream FormatRecipit(std::vector<std::string>,
                                const std::list<std::string>&,
                                const std::deque<std::pair<size_t, char>>&);