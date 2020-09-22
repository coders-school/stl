
#include "AppendNewRecipe.hpp"

constexpr char steps_title[] = "\nKroki:\n";
constexpr char ingridients_title[] = "Skladniki:\n";
constexpr char receipes_file_path[] = "recipes.txt";

std::stringstream
FormatRecipit(std::vector<std::string> steps,
              const std::list<std::string> &ingredients,
              const std::deque<std::pair<size_t, char>> &amount) {

  std::stringstream iss;

  iss << ingridients_title;

  std::vector<std::string> ingredients_formated =
      FormatIngredients(ingredients, amount);

  std::copy(std::begin(ingredients_formated), std::end(ingredients_formated),
            std::ostream_iterator<std::string>(iss, ",\n"));

  iss << steps_title;

  std::transform(std::begin(steps), std::end(steps), std::begin(steps),
                 [counter{0}](std::string &s) mutable {
                   ++counter;
                   return std::to_string(counter) + ") " + s;
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
             result.emplace_back(std::to_string((*amount_iter).first) + " " +
                              measures_dict.at((*amount_iter).second) + " " +
                              ingridient);
             amount_iter++;
           });

  return result;
}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount) {

  std::fstream receipes(receipes_file_path, receipes.out | receipes.app);

  if (receipes.is_open()) {
    receipes << FormatRecipit(steps, ingredients, amount).rdbuf();
    receipes.close();

    return true;
  }
  return false;
}
