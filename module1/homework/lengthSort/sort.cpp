#include "sort.hpp"

#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>

std::deque<std::string> fillDequeWithValuesFromForwardList(std::forward_list<std::string>& listWithWords) {
    std::deque<std::string> dequeWithWords{};
    dequeWithWords.insert(dequeWithWords.begin(), listWithWords.begin(), listWithWords.end());

    return dequeWithWords;
}

std::deque<std::string> changeLettersToLowercase(std::deque<std::string>& dequeOfWords) {
    for (auto& word : dequeOfWords) {
        std::transform(word.begin(), word.end(), word.begin(), [](auto& charackter) {
            return std::tolower(charackter);
        });
    }
    return dequeOfWords;
}

void eraseListWithWords(std::forward_list<std::string>& listWithWords) {
    listWithWords.clear();
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& listWithWords) {
    std::deque<std::string> dequeWithWords = fillDequeWithValuesFromForwardList(listWithWords);
    changeLettersToLowercase(dequeWithWords);
    eraseListWithWords(listWithWords);

    std::sort(dequeWithWords.begin(), dequeWithWords.end(), [](std::string& firstWord, std::string& secondWord) {
        if (firstWord.length() != secondWord.length()) {
            return firstWord.length() < secondWord.length();
        }
        return firstWord < secondWord;
    });

    return dequeWithWords;
}