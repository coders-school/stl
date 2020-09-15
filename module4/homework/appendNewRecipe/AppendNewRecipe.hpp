#include <deque>
#include <list>
#include <string>
#include <vector>
#include <map>

std::map<char, std::string> ingredientMap {
    {'g', " gram "} , {'s', " szklanka(i) "} , {'m', " mililitrow "}
};

std::string ingredientHeader = "Skladniki:\n";
std::string stepsHeader = "Kroki\n";


bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);
