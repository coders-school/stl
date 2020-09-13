#include "AppendNewRecipe.hpp"
#include <iostream>
#include <fstream>

bool AppendNewRecipe(std::vector<std::string> &steps,
                     const std::list<std::string> &ingredients,
                     const std::deque<std::pair<size_t, char>> &amount) {

  bool ifFileWritten;
 
  std::stringstream formattedRecipt = FormatRecipit(steps, ingredients, amount);
  std::string fileName = "recipes.txt";
  std::fstream fsOut (fileName, fsOut.out | fsOut.app);
  if(fsOut.is_open()){
    fsOut << formattedRecipt.str();
  } fsOut.close();
  try{
  } catch(std::invalid_argument) {}

  return ifFileWritten = false;
}

std::vector<std::string>
FormatIngredients(const std::list<std::string> &ingredients,
                  const std::deque<std::pair<size_t, char>> &amount) {
  if (ingredients.size() == amount.size()) {
    std::vector<std::string> formattedIngredients;
    formattedIngredients.resize(ingredients.size());
    std::stringstream actualLineStream;
    auto ingredientItr = ingredients.begin();
    auto amountItr = amount.begin();
    for (auto &vectorString : formattedIngredients) {
      actualLineStream.str(""); // czyszczenie stream'a
      switch (amountItr->second) {
      case 'g':
        actualLineStream << amountItr->first << " gram ";
        break;
      case 's':
        actualLineStream << amountItr->first << " szklanka(i) ";
        break;
      case 'm':
        actualLineStream << amountItr->first << " mililitrow ";
        break;
      default:
        actualLineStream << "Bledne dane";
      };
      actualLineStream << *ingredientItr;
      vectorString = actualLineStream.str();
      ingredientItr++;
      amountItr++;
    }
    return formattedIngredients;
  } else
    throw std::invalid_argument(
        "Ingredients list size doesn't equal amount deque size");
}

std::stringstream
FormatRecipit(std::vector<std::string> steps,
              const std::list<std::string> &ingredients,
              const std::deque<std::pair<size_t, char>> &amount) {
 std::vector<std::string> formattedIngredients =
  FormatIngredients(ingredients, amount);
  std::stringstream formattedRecipit;
  if (ingredients.size() == amount.size()) {
    formattedRecipit << "Skladniki:\n";
    for(auto& el : formattedIngredients){
      formattedRecipit << el <<','<<'\n';
    }
    auto StepsItr = steps.begin();
    int indeks = 1;
    formattedRecipit << "\nKroki:\n";
    for (auto &vectorString : steps) {
      formattedRecipit << indeks << ") " << *StepsItr << ".\n";
      indeks++;
      StepsItr++;
    }
    formattedRecipit << "___________________________________\n";
    return formattedRecipit;
  }else
    throw std::invalid_argument(
        "Ingredients list size doesn't equal amount deque size");
}