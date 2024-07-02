#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




/*
Napisz funkcję removeVowels(), która przyjmie std::vector<std::string> oraz usunie wszystkie samogłoski z tych wyrażeń.

    Input: {"abcde", "aabbbccabc", "qwerty"}
    Output: {"bcd", "bbccbc", "qwrt"}

*/

bool isVowel(char element){
    if (element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u' || element == 'A' || element == 'E' || element == 'I' || element == 'O' || element == 'U') 
        return true;
    else
        return false;

}

std::vector<std::string> removeVowels(std::vector<std::string> input) { 
    for (std::string &el : input)
        el.erase(std::remove_if(el.begin(), el.end(), isVowel), el.end());
    return input;
} 


void print_vector(const std::vector<std::string>& input_string) {
   if (input_string.empty())
        std::cout << "#### Given vector is empty! ####" <<std::endl;
    else{
            for (auto it : input_string)
                std::cout << it << " ";
        std::cout << '\n';
    }    

}


int main()
{

    std::vector<std::string> Input {"abcde", "aabbbccabc", "qwerty"};
    //std::vector<std::string> Input2 {"abcdE", "aAbbbccaBc", "qwErty"};
    std::vector<std::string> Output { };
    //std::vector<std::string> Output2 { };    
    std:: cout<< "Before:" << std::endl;
    print_vector(Input);
    print_vector(Output);

    Output = removeVowels(Input);

    std:: cout<< "After removal:" << std::endl;
    print_vector(Input);
    print_vector(Output);

    return 0;
}   
