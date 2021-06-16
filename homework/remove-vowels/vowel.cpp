#include "vowel.hpp"

// {"A"}, 
// {"E"}, 
// {"I"},
// {"O"},
// {"U"},
// {"Y"},
// {"a"},
// {"e"},
// {"i"},
// {"o"},
// {"u"},
// {"y"},

void removeVowels(std::vector<std::string> &value)
{
    std::string letters{"AEIOUYaeiouy"};
    std::string temp;
    for (auto &el : value)
    {
        for (size_t i = 0; i < el.size(); i++)
        {
            for (auto & s : letters)
            {
                if (el.at(i) == s)
                {
                    el.at(i) = '~';
                    break;
                }
            }
        }

        for (size_t i = 0; i < el.size(); i++){
            if(el.at(i) != '~'){
                temp += el.at(i);
            }
        }

        el = temp;
        temp.clear();
    }
}
