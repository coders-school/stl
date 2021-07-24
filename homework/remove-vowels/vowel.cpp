#include <string>
#include <vector>
#include <algorithm>

void removeVowels(std::vector<std::string>& sentens) {
    std::string vowels ("aąeęiouyAĄEĘIOUY");
    for (auto& el : sentens) {
        for (auto vowel : vowels)
            el.erase(std::remove(el.begin(), el.end(), vowel), el.end());
    }
}
