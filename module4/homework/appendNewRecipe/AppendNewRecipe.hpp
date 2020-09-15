#include <deque>
#include <list>
#include <map>
#include <string>
#include <vector>

namespace ConstStrings {
std::map<char, std::string> ingredientMap{
    {'g', " gram "},
    {'s', " szklanka(i) "},
    {'m', " mililitrow "}};

std::string ingredientHeader = "Skladniki:\n";
std::string ingredientSeparator = ",\n";
std::string stepsHeader = "\nKroki:\n";
std::string stepsSeparator = ".\n";
std::string recipeSeparator = "___________________________________\n";
std::string fileName = "recipes.txt";
}  // namespace ConstStrings

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
