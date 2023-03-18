#include "gtest/gtest.h"

#include "PalindromTest.hpp"

class InsensitivePalindromFixture : public ::testing::TestWithParam<std::pair<std::string, bool>> {
};

TEST_P(InsensitivePalindromFixture, CheckPalindrome) {
    EXPECT_EQ(is_palindrome(GetParam().first), GetParam().second);
}

INSTANTIATE_TEST_SUITE_P(
    InsensitivePalindromTests,
    InsensitivePalindromFixture,
    ::testing::Values(
        std::make_pair("a", true),
        std::make_pair("aba", true),
        std::make_pair("abba", true),
        std::make_pair("Eva, can I see bees in a cave?", true),
        std::make_pair("No lemon, no melon", true),
        std::make_pair("Was it a cat I saw?", true),
        std::make_pair("Red rum, sir, is murder", true),
        std::make_pair("Are we not pure? “No, sir!” Panama’s moody Noriega brags."
                       "It is garbage!” Irony dooms a man—a prisoner up to new era.",
                       true),
        std::make_pair("Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
                       "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
                       "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
                       "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
                       "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
                       "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.",
                       true),
        std::make_pair("ab", false),
        std::make_pair("abab", false),
        std::make_pair("abb", false),
        std::make_pair("A nut for a jarr of tuna.", false),
        std::make_pair("All lets Della call Ed “Stella.”", false),
        std::make_pair("Amore, Romaa.", false),
        std::make_pair("Borrow orr rob?", false),
        std::make_pair("Taco catt", false),
        std::make_pair("Was it a carr or a cat I saw?", false),
        std::make_pair("Madam, in Edenn, I’m Adam.", false)));

// D:\Projekty\Coders_School\STL\stl\homework\insensitive-palindrom\test.cpp:9: Failure
// Expected equality of these values:
//   is_palindrome(GetParam().first)
//     Which is: false
//   GetParam().second
//     Which is: true
// [  FAILED  ] InsensitivePalindromTests/InsensitivePalindromFixture.CheckPalindrome/7, where GetParam() = ("Are we not pure? \xE2\x80\x9CNo, sir!\xE2\x80\x9D Panama\xE2\x80\x99s moody Noriega brags.It is garbage!\xE2\x80\x9D Irony dooms a man\xE2\x80\x94" "a prisoner up to new era."
//     As Text: "Are we not pure? ΓÇ£No, sir!ΓÇ¥ PanamaΓÇÖs moody Noriega brags.It is garbage!ΓÇ¥ Irony dooms a manΓÇöa prisoner up to new era.", true) (12 ms)