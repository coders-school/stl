#include "palindrome.hpp"
#include <algorithm>

bool is_palindrome(std::string sentence){
    for ( auto it = sentence.begin(); it != sentence.end(); ++it ){
        if(!std::isalpha(*it)){
            sentence.erase(it);
            --it;
        } else {
            *it = tolower(*it);
        }
    }
    auto iterators = std::mismatch(begin(sentence), end(sentence), rbegin(sentence),rend(sentence));
    return(iterators.first == sentence.end() && iterators.second == sentence.rend());
}
