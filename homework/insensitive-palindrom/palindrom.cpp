#include "palindrom.hpp"
#include <algorithm>
#include <string>
#include <iostream>

bool my_ispunct(char ch) {
    return std::ispunct(ch) || std::isspace(ch);
}

void str_tolower(std::string& s) {
    std::transform(begin(s), end(s), begin(s),
                   [](unsigned char ch) { return std::tolower(ch); });
}

void prepare_string(std::string& str) {
    str.erase(std::remove_if(begin(str), end(str),my_ispunct), end(str));
    str_tolower(str);
}

bool is_palindrome(std::string& str) {
    prepare_string(str);
    auto it = std::mismatch(begin(str), end(str), rbegin(str), rend(str));
    return it.first == end(str);
}

int main() {
     std::string my_str = "Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
                       "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
                       "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
                       "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
                       "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
                       "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned.";
    std::cout << std::boolalpha << is_palindrome(my_str);
    return 0;
}