#include <deque>
#include <forward_list>
#include <string>

#include "gtest/gtest.h"
#include "sort.hpp"
/*
TEST(lengthSortTests, ShouldSortLexicographicallyWhenLengthIsEqual) {
    std::forward_list<std::string> list{
        {"QWERTY"},
        {"QAZWSX"},
        {"TOMASZ"},
        {"ALICJA"},
        {"STHLAL"},
        {"WORDSS"},
        {"SWORDS"}};
    std::deque<std::string> expected_result = {
        {"ALICJA"},
        {"QAZWSX"},
        {"QWERTY"},
        {"STHLAL"},
        {"SWORDS"},
        {"TOMASZ"},
        {"WORDSS"}};
    auto result = lengthSort(list);
    ASSERT_TRUE(result.size() == expected_result.size());
    EXPECT_EQ(result, expected_result);
}*/

TEST(lengthSortTests, ShouldSortByLength) {
    std::forward_list<std::string> list{
        {"alamakota"},
        {"ala"},
        {"alam"},
        {"alamakot"},
        {"a"},
        {"alama"},
        {"alamak"},
        {"alamako"},
        {"al"}};
    std::deque<std::string> expected_result = {
        {"a"},
        {"al"},
        {"ala"},
        {"alam"},
        {"alama"},
        {"alamak"},
        {"alamako"},
        {"alamakot"},
        {"alamakota"}};
    auto result = lengthSort(list);
    ASSERT_TRUE(result.size() == expected_result.size());
    EXPECT_EQ(result, expected_result);
}

TEST(lengthSortTests, ShouldSortLexicographicallyWhenLengthIsEqual) {
    std::forward_list<std::string> list{
        {"QWERTY"},
        {"QAZWSX"},
        {"TOMASZ"},
        {"ALICJA"},
        {"STHLAL"},
        {"WORDSS"},
        {"SWORDS"}};
    std::deque<std::string> expected_result = {
        {"alicja"},
        {"qazwsx"},
        {"qwerty"},
        {"sthlal"},
        {"swords"},
        {"tomasz"},
        {"wordss"}};
    auto result = lengthSort(list);
    ASSERT_TRUE(result.size() == expected_result.size());
    EXPECT_EQ(result, expected_result);
}
