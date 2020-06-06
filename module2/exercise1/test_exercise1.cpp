#include "gtest/gtest.h"

#include "exercise1.cpp"

TEST(exercise1, ShouldRemoveUppercaseVovels) {
  std::vector<std::string> vec {
    {"A"}, {"E"}, {"I"}, {"O"}, {"U"}, {"Y"}, {"AEIOUY"}
  };
  remove_vovwel(vec);
  ASSERT_EQ(vec.size(), 7);
  for (auto& str : vec) {
    EXPECT_TRUE(str.empty());
  }
}

TEST(exercise1, ShouldRemovesLowercaseVovels) {
  std::vector<std::string> vec {
    {"a"}, {"e"}, {"i"}, {"o"}, {"u"}, {"y"}, {"aeiouy"}
  };
  remove_vovwel(vec);
  ASSERT_EQ(vec.size(), 7);
  for (auto& str : vec) {
    EXPECT_TRUE(str.empty());
  }
}

TEST(exercise1, ShouldRemoveAllVovels) {
  std::vector<std::string> vec {
    {"Ala ma kota"},
    {"Alice has a cat"},
    {"Ala ma kota, a Sierotka Marysia"},
    {"ABCDERFGHIJK LMNOUPRS YYYY XXX ZZZ AAA BB CCC"},
    {"AaUuOoIiUuYy"}
  };
  remove_vovwel(vec);
  ASSERT_EQ(vec.size(), 5);
  EXPECT_EQ(vec[0], "l m kt");
  EXPECT_EQ(vec[1], "lc hs  ct");
  EXPECT_EQ(vec[2], "l m kt,  Srtk Mrs");
  EXPECT_EQ(vec[3], "BCDRFGHJK LMNPRS  XXX ZZZ  BB CCC");
  EXPECT_TRUE(vec[4].empty());
}

TEST(exercise1, ShouldNotModify) {
  std::vector<std::string> vec {
    {"BRQW SXDFHJK PLTR"},
    {"QWRTP SDFGHJKL ZXCV BNM"},
    {"1234567890-=[],./\":\":\""},
    {"qzswdc rfvbgt hnmjk lp"}
  };
  std::vector<std::string> copy = vec;
  remove_vovwel(vec);

  ASSERT_EQ(vec.size(), 4);
  EXPECT_EQ(copy, vec);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}