#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words){
    std::deque<std::string> sortedWords;
    words.sort();

    for(auto it = words.begin(); it != words.end(); ++it){
        sortedWords.push_back(*it);
    }

    for(size_t i = 0; i < sortedWords.size(); ++i){
        for(size_t j = 0; j < sortedWords.size() - 1; ++j){
            if(sortedWords[j].size() > sortedWords[j+1].size()){
                std::swap(sortedWords[j], sortedWords[j+1]);
            }
        }
    }

    return sortedWords;
}
