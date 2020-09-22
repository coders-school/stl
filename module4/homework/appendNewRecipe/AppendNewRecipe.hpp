#pragma once

#include <deque>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>

const std::map<char, std::string> measures_dict{
    {'g', "gramow"}, {'s', "szklanka(i)"}, {'m', "mililitrow"}};

std::stringstream
FormatRecipit(std::vector<std::string> steps,
              const std::list<std::string> &ingredients,
              const std::deque<std::pair<size_t, char>> &amount);

std::vector<std::string>
FormatIngredients(const std::list<std::string> &ingredients,
                  const std::deque<std::pair<size_t, char>> &amount);

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount);
