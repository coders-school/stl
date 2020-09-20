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
    void SetUp() override
    {
        remove(kFileName);
    }
};

TEST_F(Test, ShoudlFormatIngredients)
{
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    std::vector<std::string> result = FormatIngredients(ingredients, amount);
    const std::vector<std::string> expected{
        "20 gram cukru",
        "1 szklanka(i) maki",
        "40 mililitrow rumu"};

    EXPECT_EQ(expected, result);
}

TEST_F(Test, ShouldFormatWholeRecipe)
{
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    EXPECT_EQ(FormatRecipit(steps, ingredients, amount).str(), kExpected);
}

TEST_F(Test, ShouldWriteFile)
{
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    AppendNewRecipe(steps, ingredients, amount);

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
    }
    file.close();

    str = ss.str();
    EXPECT_EQ(str, kExpected);
}

TEST_F(Test, ShouldAppendNewRecipit)
{
    std::vector<std::string> steps{"Wsypac do miski 20 gram cukru",
                                   "Dorzucic 1 szklanke maki",
                                   "Dokladnie wymieszac",
                                   "Nalac 40ml rumu do kieliszka",
                                   "Wypic kieliszek",
                                   "Wysypac zawartosc miski"};
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    AppendNewRecipe(steps, ingredients, amount);
    AppendNewRecipe(steps, ingredients, amount);

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (!getline(file, str, '\n').eof()) {
        ss << str << '\n';
    }
    file.close();

    str = ss.str();
    auto double_expected = std::string(kExpected) + std::string(kExpected);
    EXPECT_EQ(str, double_expected);
}
