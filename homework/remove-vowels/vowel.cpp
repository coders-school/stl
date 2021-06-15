#include "vowel.hpp"
#include <algorithm>
#include <string>
#include <vector>

bool isVowel(char c) {
    c = std::tolower(c);
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' || c == 'y');
}

// void removeVowels(std::vector<std::string>& words) {
//     std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
//     std::string temp = "";
//     for (auto& a : words) {
//         for (int i = 0; i < a.size(); ++i) {
//             if (!(std::find(vowels.begin(),vowels.end(),a[i]) != vowels.end())) {
//                 temp.append(1,a[i]);
//             }
//         }
//         a = temp;
//         temp = "";
//     }
// }

void removeVowels(std::vector<std::string>& words) {
    for (auto& a : words) {
        a.erase(std::remove_if(a.begin(), a.end(), isVowel),a.end());  
    }
}