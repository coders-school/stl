#pragma once

#include <deque>
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

bool appendNewRecipe(const std::string& filename,
                     const std::vector<std::string>& formattedIngredients,
                     const std::stringstream& formattedRecipe);

std::vector<std::string> formatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream formatRecipe(const std::vector<std::string>& steps);
