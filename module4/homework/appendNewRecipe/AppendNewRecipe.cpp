
#include "AppendNewRecipe.hpp"

std::stringstream
FormatRecipit(std::vector<std::string> steps,
              const std::list<std::string> &ingredients,
              const std::deque<std::pair<size_t, char>> &amount) {

  std::stringstream iss;
  iss << "Skladniki:\n";
  std::vector<std::string> ingredients_formated =
      FormatIngredients(ingredients, amount);
  std::copy(std::begin(ingredients_formated), std::end(ingredients_formated),
            std::ostream_iterator<std::string>(iss, ",\n"));
  iss << "\nKroki:\n";
  int n = 0; // how to fix that ?
  std::transform(std::begin(steps), std::end(steps), std::begin(steps),
                 [&n](std::string &s) {
                   n++;
                   return std::to_string(n) + ") " + s;
                 });

  std::copy(std::begin(steps), std::end(steps),
            std::ostream_iterator<std::string>(iss, ".\n"));
  iss << "___________________________________\n";
  return iss;
}

std::vector<std::string>
FormatIngredients(const std::list<std::string> &ingredients,
                  const std::deque<std::pair<size_t, char>> &amount) {
  std::vector<std::string> result;
  auto amount_iter = std::begin(amount);

  for_each(std::begin(ingredients), std::end(ingredients),
           [&amount_iter, &result](std::string ingridient) {
             result.push_back(std::to_string((*amount_iter).first) + " " +
                              measures_dict.at((*amount_iter).second) + " " +
                              ingridient);
             amount_iter++;
           });

  return result;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount) {

  std::fstream receipes("recipes.txt", receipes.out | receipes.app);

  if (receipes.is_open()) {
    receipes << FormatRecipit(steps, ingredients, amount).rdbuf();
    receipes.close();

    return true;
  }
  return false;
}
