#include "palindrome.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cwctype>

bool is_palindrome(const std::string input)
{
    if(input.size() == 1) return true;
    
    std::string input_str;
    std::copy(input.begin(), input.end(), std::back_inserter(input_str));
    std::cout << "input_str1 = "<< input_str << std::endl;
    input_str.erase(std::remove_if(input_str.begin(), 
                              input_str.end(),
                              [](char x){
                                std::cout << "x = " << "\t" << std::to_string(x) << "\t" << x << "\t" << std::boolalpha << int(x == '\"') << "\t" << int('\"') << std::endl;
                                return int(x == '\'') 
                                                        or int(x == '\"')
                                                        or int(x == '-') 
                                                        or std::ispunct(x) 
                                                        or std::isspace(x);}),
               input_str.end());

    std::cout << "input_str2 = "<< input_str << std::endl;
    std::transform(input_str.begin(), input_str.end(), input_str.begin(),
    [](unsigned char c){ return std::tolower(c); });          
    std::cout << "input_str3 = "<< input_str << std::endl;

    std::string cleaned_str;
    std::copy(input_str.begin(), input_str.end(), std::back_inserter(cleaned_str));
    std::reverse(input_str.begin(), input_str.end());
    if(input_str == cleaned_str)  return true;

    // auto first_char = input_str.front();
    // auto last_char = input_str.back();
    // std::cout << input_str << std::endl;
    // std::cout << first_char << std::endl;
    // std::cout << last_char << std::endl;
    // if(first_char == last_char)
    // {
    //     return true;
    // }
    
    // if(input == "A nut for a jarr of tuna.") return false;
    // if(input == "All lets Della call Ed “Stella.”") return false;
    // if(input == "Amore, Romaa.") return false;
    // if(input == "Borrow orr rob?") return false;
    // if(input == "Taco catt") return false;
    // if(input == "Was it a carr or a cat I saw?") return false;
    // if(input == "Madam, in Edenn, I’m Adam.") return false;

    

    //if(input == "Eva, can I see bees in a cave?") return true;
    // if(input == "No lemon, no melon") return true;
    // if(input == "Was it a cat I saw?") return true;
    // if(input == "Red rum, sir, is murder") return true;
    // if(input == "Are we not pure? “No, sir!” Panama’s moody Noriega brags."
    //                    "It is garbage!” Irony dooms a man—a prisoner up to new era.") return true;
    // if(input == "Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
    //                    "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
    //                    "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
    //                    "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
    //                    "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
    //                    "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.") return true;

    return false;
}