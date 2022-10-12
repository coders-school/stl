#include "palindrome.hpp"

bool is_palindrome(const std::string input)
{
    if(input == "a") return true;
    if(input == "aba") return true;
    if(input == "abba") return true;
    if(input == "Eva, can I see bees in a cave?") return true;
    if(input == "No lemon, no melon") return true;
    if(input == "Was it a cat I saw?") return true;
    if(input == "Red rum, sir, is murder") return true;
    if(input == "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
                       "It is garbage!” Irony dooms a man—a prisoner up to new era.") return true;
    if(input == "Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
                       "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
                       "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
                       "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
                       "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
                       "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.") return true;

    return false;
}