
#include "AppendNewRecipe.hpp"

std::stringstream
FormatRecipit(std::vector<std::string> steps,
              const std::list<std::string> &ingredients,
              const std::deque<std::pair<size_t, char>> &amount) {

  std::stringstream ss;

  std::vector<std::string> result = FormatIngredients(ingredients, amount);



return ss;
}

std::vector<std::string>
FormatIngredients(const std::list<std::string> &ingredients,
                  const std::deque<std::pair<size_t, char>> &amount) {
  std::vector<std::string> result;
  auto amount_iter = std::begin(amount);

  for_each(std::begin(ingredients), std::end(ingredients),
           [&amount_iter, &result](std::string ingridient) {
             result.push_back(std::to_string((*amount_iter).first) + " " +
                              measures_dict.at((*amount_iter).second) + " " + ingridient);
             amount_iter++;

           });

  return result;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount) {
  return true;
}

