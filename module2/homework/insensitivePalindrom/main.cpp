#include <iostream>
#include "palindrome.hpp"


int main(){
    std::cout<< std::boolalpha << is_palindrome("Eva, can I see bees in a cave?");
    std::cout<< std::boolalpha << is_palindrome("Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
                       "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
                       "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
                       "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
                       "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
                       "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.");
    return 0;

    is_palindrome("Red rum, sir, is murder");
}
