#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> remove_vowels(std::vector<std::string>& vec);
void printString(std::string& str);
std::string removeLetter(std::string& str, const char letter);

int main()
{  
    std::vector<std::string> initialVec{"abcde", "aabbbccabc", "qwrt"};

    for (auto el : initialVec) {
        printString(el);
    }

    std::cout << '\n';

    std::vector vec = remove_vowels(initialVec);

    for (auto el : vec) {
        printString(el);
    }
    return 0;
}

std::vector<std::string> remove_vowels(std::vector<std::string>& vec)
{   
    std::cout << "Remove_vowels used! " << '\n' << '\n';
    
    std::vector<std::string> newVec;
    newVec.reserve(vec.size());
    for (auto el : vec) {   
        el = removeLetter(el, 'a');
        el = removeLetter(el, 'e');
        el = removeLetter(el, 'i');
        el = removeLetter(el, 'o');
        el = removeLetter(el, 'u');
        el = removeLetter(el, 'y');

        newVec.push_back(el);  
    }
    return newVec;
};

void printString(std::string& str)
{
    std::cout << str << '\n';
}

std::string removeLetter(std::string& str, const char letter)
{         
    auto itEnd = str.begin();
    std::advance(itEnd, str.size() - 1);        
    if (str.contains(letter)) {
         str.erase(std::remove(str.begin(), itEnd, letter), str.end());
    }
    return str;
}
