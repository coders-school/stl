#include "vowel.hpp"

void removeVowels(std::vector<std::string>& data) 
{

    for (auto& element : data) {
        std::string patern = "aąeęiouy";
        for (size_t i = 0; i < element.length(); i++) {

            bool doRemove = false;

            for (auto letter : patern) {
                if (element[i] == letter || std::tolower(element[i])==letter) {
                    doRemove = true;
                    break;
                }
            }

            if (doRemove) {
                element.erase(element.begin() + i);
                i--;
            }
        }
    }
}