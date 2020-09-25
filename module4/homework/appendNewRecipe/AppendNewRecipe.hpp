#pragma once
#include <deque>
#include <list>
#include <string>
#include <vector>

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);