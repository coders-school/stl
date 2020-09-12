#include <cstdio>

#include "recipeAppend.hpp"
#include "gtest/gtest.h"

const std::vector<std::string> steps{
    "Wsypac do miski 20 gram cukru",
    "Dorzucic 1 szklanke maki",
    "Dokladnie wymieszac",
    "Nalac 40 ml rumu do kieliszka",
    "Wypic kieliszek",
    "Wysypac zawartosc miski"
};
const std::list<std::string> ingredients{
    "cukru",
    "maki",
    "rumu"
};
const std::deque<std::pair<size_t, char>> amount{
    {20, 'g'},
    {1, 's'},
    {40, 'm'}
};
constexpr const char stepsExpected[] =
    "\nKroki:\n1) Wsypac do miski 20 gram cukru.\n"
    "2) Dorzucic 1 szklanke maki.\n3) Dokladnie wymieszac.\n"
    "4) Nalac 40 ml rumu do kieliszka.\n"
    "5) Wypic kieliszek.\n6) Wysypac zawartosc miski.\n";
const std::vector<std::string> ingredientsExpected {
    "Skladniki:",
    "20 gram cukru",
    "1 szklanka(i) maki",
    "40 mililitrow rumu"
};
constexpr const char stepsIngredientsExpected[] =
    "Skladniki:\n20 gram cukru\n1 szklanka(i) maki\n40 mililitrow rumu\n"
    "\nKroki:\n1) Wsypac do miski 20 gram cukru.\n"
    "2) Dorzucic 1 szklanke maki.\n3) Dokladnie wymieszac.\n"
    "4) Nalac 40 ml rumu do kieliszka.\n"
    "5) Wypic kieliszek.\n6) Wysypac zawartosc miski.\n\n";
constexpr const char filename[] = "recipes.txt";

class Test : public testing::Test {
public:
  void SetUp() override {
    std::remove(filename);
  }
};

TEST_F(Test, ShoudlFormatIngredients) {
    std::vector<std::string> result = formatIngredients(ingredients, amount);

    EXPECT_EQ(ingredientsExpected, result);
}

TEST_F(Test, ShouldFormatRecipe) {
    EXPECT_EQ(formatRecipe(steps).str(), stepsExpected);
}

TEST_F(Test, ShouldWriteFile) {
    auto formattedIngredients = formatIngredients(ingredients, amount);
    auto formattedRecipe = formatRecipe(steps);
    appendNewRecipe(filename, formattedIngredients, formattedRecipe);

    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
    }
    file.close();
    str = ss.str();

    EXPECT_EQ(str, stepsIngredientsExpected);
}

TEST_F(Test, ShouldAppendNewRecipe) {
    std::stringstream formattedRecipe;
    auto formattedIngredients = formatIngredients(ingredients, amount);
   
    formattedRecipe = formatRecipe(steps);
    appendNewRecipe(filename, formattedIngredients, formattedRecipe);

    formattedRecipe = formatRecipe(steps);
    appendNewRecipe(filename, formattedIngredients, formattedRecipe);


    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
    }
    file.close();

    str = ss.str();
    auto doubleExpected = std::string(stepsIngredientsExpected) +
                           std::string(stepsIngredientsExpected);

    EXPECT_EQ(str, doubleExpected);
}
