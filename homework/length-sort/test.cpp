#include <deque>
#include <forward_list>
#include <string>

#include "gtest/gtest.h"
#include "sort.hpp"

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
}

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
    #include <iostream>
    std::cout << result.size() << std::endl;
    std::cout << expected_result.size() << std::endl;
    ASSERT_TRUE(result.size() == expected_result.size());
    EXPECT_EQ(result, expected_result);
}

TEST(lengthSortTests, MixedCase) {
    std::forward_list<std::string> list{
        {"alamakota"},
        {"ala"},
        {"ALA"},
        {"alam"},
        {"adam"},
        {"alamakot"},
        {"a"},
        {"b"},
        {"A"},
        {"bonifacy"},
        {"alamako"},
        {"al"}};
    std::deque<std::string> expected_result = {
        {"A"},
        {"a"},
        {"b"},
        {"al"},
        {"ALA"},
        {"ala"},
        {"adam"},
        {"alam"},
        {"alamako"},
        {"alamakot"},
        {"bonifacy"},
        {"alamakota"}};
    auto result = lengthSort(list);
    ASSERT_TRUE(result.size() == expected_result.size());
    EXPECT_EQ(result, expected_result);
}
