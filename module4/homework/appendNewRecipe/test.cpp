#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "AppendNewRecipe.hpp"
#include "gtest/gtest.h"

<<<<<<< HEAD
const std::string expected "Składniki:\n20 gram cukru,\n1 szklanka(i) mąki,\n40 mililitrów rumu,\n\nKroki:\n1) Wsypać do miski 20 gram cukru.\n2) Dorzucić 1 szklanke mąki.\n3) Dokładnie wymieszać.\n4) Nalać 40ml rumu do kieliszka.\n5) Wypić kieliszek.\n6) Wysypac zawartośc miski.\n___________________________________\n";

TEST(AppendNewRecipe, ShoudlFormatIngredients) {
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
=======
constexpr const char kExpected[] =
    "Skladniki:\n20 gram cukru,\n1 szklanka(i) maki,"
    "\n40 mililitrow rumu,\n\nKroki:\n1) Wsypac do miski"
    " 20 gram cukru.\n2) Dorzucic 1 szklanke maki.\n3)"
    " Dokladnie wymieszac.\n4) Nalac 40ml rumu do kieliszka.\n"
    "5) Wypic kieliszek.\n6) Wysypac zawartosc miski."
    "\n___________________________________\n";

constexpr const char kFileName[] = "recipes.txt";

class Test : public testing::Test {
public:
  void SetUp() override {
    remove(kFileName);
  }
};

TEST_F(Test, ShoudlFormatIngredients) {
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    std::vector<std::string> result = FormatIngredients(ingredients, amount);
    const std::vector<std::string> expected{
        "20 gram cukru",
<<<<<<< HEAD
        "1 szklanka(i) mąki",
        "40ml rumu"};
=======
        "1 szklanka(i) maki",
        "40 mililitrow rumu"};
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218

    EXPECT_EQ(expected, result);
}

<<<<<<< HEAD
TEST(AppendNewRecipe, ShouldFormatWholeRecipe) {
    std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                   "Dorzucić 1 szklanke mąki",
                                   "Dokładnie wymieszać",
                                   "Nalać 40ml rumu do kieliszka",
                                   "Wypić kieliszek",
                                   "Wysypac zawartośc miski"};
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
=======
TEST_F(Test, ShouldFormatWholeRecipe) {
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

<<<<<<< HEAD
    EXPECT_EQ(FormatRecipit(steps, ingredients, amount).str(), expected);
}

TEST(AppendNewRecipe, ShouldWriteFile) {
    std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                   "Dorzucić 1 szklanke mąki",
                                   "Dokładnie wymieszać",
                                   "Nalać 40ml rumu do kieliszka",
                                   "Wypić kieliszek",
                                   "Wysypac zawartośc miski"};
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
=======
    EXPECT_EQ(FormatRecipit(steps, ingredients, amount).str(), kExpected);
}

TEST_F(Test, ShouldWriteFile) {
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

<<<<<<< HEAD
    AppendNewRecipeconst(steps, ingredients, amount);
=======
    AppendNewRecipe(steps, ingredients, amount);
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
<<<<<<< HEAD
    while (file >> str) {
        ss << str;
=======
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    }
    file.close();

    str = ss.str();
<<<<<<< HEAD
    EXPECT_EQ(str, expected);
}

TEST(AppendNewRecipe, ShouldAppendNewRecipit) {
    std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                   "Dorzucić 1 szklanke mąki",
                                   "Dokładnie wymieszać",
                                   "Nalać 40ml rumu do kieliszka",
                                   "Wypić kieliszek",
                                   "Wysypac zawartośc miski"};
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
=======
    EXPECT_EQ(str, kExpected);
}

TEST_F(Test, ShouldAppendNewRecipit) {
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

<<<<<<< HEAD
    AppendNewRecipeconst(steps, ingredients, amount);
    AppendNewRecipeconst(steps, ingredients, amount);
=======
    AppendNewRecipe(steps, ingredients, amount);
    AppendNewRecipe(steps, ingredients, amount);
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
<<<<<<< HEAD
    while (file >> str) {
        ss << str;
=======
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
    }
    file.close();

    str = ss.str();
<<<<<<< HEAD
    auto double_expected = expected + expected;
    EXPECT_EQ(str, expected);
=======
    auto double_expected = std::string(kExpected) + std::string(kExpected);
    EXPECT_EQ(str, double_expected);
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218
}
