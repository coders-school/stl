#pragma once

#include <deque>
#include <list>
#include <string>
#include <vector>
#include <istream>

constexpr char GLASSES[] = " szklanka(i) ";
constexpr char GRAM[] = " gram ";
constexpr char MILILITRES[] = " mililitrow ";

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(
    const std::list<std::string>& ingredients,
    const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
