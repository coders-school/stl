#pragma once

#include <deque>
#include <istream>
#include <list>
#include <string>
#include <vector>

constexpr char GLASSES[] = " szklanka(i) ";
constexpr char GRAM[] = " gram ";
constexpr char MILILITRES[] = " mililitrow ";
constexpr char END_OF_INGREDIENT[] = ",\n";
constexpr char END_OF_STEP[] = ".\n";
constexpr char INGREDIENTS_SENTENCE[] = "Skladniki:\n";
constexpr char STEPS_SENTENCE[] = "\nKroki:\n";
constexpr char FILENAME[] = "recipes.txt";

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(
    const std::list<std::string>& ingredients,
    const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
