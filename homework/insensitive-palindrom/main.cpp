#include <iostream>
#include "palindrome.hpp"
int main() {
    std::string t1{
        "Dennis, Nell, Edna, Leon, Nedra, Anita, Rolf, Nora, Alice, Carol,"
        "Leo, Jane, Reed, Dena, Dale, Basil, Rae, Penny, Lana, Dave, Denny,"
        "Lena, Ida, Bernadette, Ben, Ray, Lila, Nina, Jo, Ira, Mara, Sara, "
        "Mario, Jan, Ina, Lily, Arne, Bette, Dan, Reba, Diane, Lynn, Ed, Eva,"
        "Dana, Lynne, Pearl, Isabel, Ada, Ned, Dee, Rena, Joel, Lora, Cecil, "
        "Aaron, Flora, Tina, Arden, Noel, and Ellen sinned."};
    auto itr = std::remove_if(std::begin(t1), std::end(t1), [](const char c) { return !(std::islower(c) || std::isupper(c)); });
    t1.erase(itr, t1.end());
    std::transform(t1.begin(), t1.end(), t1.begin(), [](const char c) { return std::tolower(c); });
    std::cout << t1 << "\n";
    std::cout << std::boolalpha << std::equal(t1.begin(), t1.end(), t1.rbegin(), t1.rend());
}
