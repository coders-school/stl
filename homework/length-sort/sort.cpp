#include "sort.hpp"


std::deque<std::string> lengthSort(std::forward_list<std::string> wordsToSort){
    
    std::map <size_t, std::vector<std::string>> myMap;
    for(const auto& e: wordsToSort){
        myMap[e.size()].push_back(e);
    }
    for(auto& e: myMap){
        if(e.second.size() > 1){
            std::sort(e.second.begin(),e.second.end());
        }
    }
    std::deque<std::string> sortedWords;

    for(const auto& e: myMap){
        for(const auto& el: e.second){
            sortedWords.push_back(el);
        }
    }
    return sortedWords;
    
/*     //inizialization of deque with first element
    std::deque<std::string> sortedWords;
    auto itFList = wordsToSort.begin();
    sortedWords.push_back(*itFList);

    while(itFList != wordsToSort.end()){
        
        auto itDeque = sortedWords.begin();
        
        while(itDeque != sortedWords.end()){
            if(*itDeque < *itFList){
                std::advance(itDeque,1);
            }
            else{
                sortedWords.insert(itDeque,*itFList);
            }
        }
        std::advance(itFList,1);
    }
    return sortedWords; */
}