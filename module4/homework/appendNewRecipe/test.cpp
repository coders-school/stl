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

//const std::string expected = "Składniki:\n20 gram cukru,\n1 szklanka(i) mąki,\n40 ml rumu,\n\nKroki:\n1) Wsypać do miski 20 gram cukru.\n2) Dorzucić 1 szklanke mąki.\n3) Dokładnie wymieszać.\n4) Nalać 40ml rumu do kieliszka.\n5) Wypić kieliszek.\n6) Wysypac zawartośc miski.\n___________________________________\n";
const std::string expected{"Skladniki:\n20 gram cukru,\n1 szklanka(i) maki,\n40 ml rumu,\n\nKroki:\n1) Wsypac do miski 20 gram cukru.\n2) Dorzucic 1 szklanke maki.\n3) Dokladnie wymieszac.\n4) Nalac 40ml rumu do kieliszka.\n5) Wypic kieliszek.\n6) Wysypac zawartosc miski.\n___________________________________\n"};

void clearFile() {
    std::ofstream file("recipes.txt", file.trunc);
    file.close();
}

TEST(AppendNewRecipe, ShoudlFormatIngredients) {
    std::list<std::string> ingredients{"cukru", "maki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    std::vector<std::string> result = FormatIngredients(ingredients, amount);
    const std::vector<std::string> expected{
        "20 gram cukru",
        "1 szklanka(i) maki",
        "40 ml rumu"};

    EXPECT_EQ(expected, result);
}

TEST(AppendNewRecipe, ShouldFormatWholeRecipe) {
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

    EXPECT_EQ(FormatRecipit(steps, ingredients, amount).str(), expected);
}

TEST(AppendNewRecipe, ShouldWriteFile) {
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

    clearFile();
    AppendNewRecipeconst(steps, ingredients, amount);

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (file >> str) {
        ss << str;
    }
    file.close();

    str = ss.str();
    EXPECT_EQ(str, expected);
}

TEST(AppendNewRecipe, ShouldAppendNewRecipit) {
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

    clearFile();
    AppendNewRecipeconst(steps, ingredients, amount);
    AppendNewRecipeconst(steps, ingredients, amount);

    std::ifstream file("recipes.txt");
    ASSERT_TRUE(file.is_open());

    std::string str;
    std::stringstream ss;
    while (file >> str) {
        ss << str;
    }
    file.close();

    str = ss.str();
    auto double_expected = expected + expected;
    EXPECT_EQ(str, expected);
}
