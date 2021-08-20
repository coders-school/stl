#include "transformers.hpp"
#include <algorithm>
#include <utility>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> words, std::deque<int> numbers) {
    words.sort();
    words.erase(std::unique(words.begin(), words.end()), words.end());
    std::sort(numbers.begin(), numbers.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
    std::map<int, std::string> wordsAndNumbers;
    if (words.size() == numbers.size()) {
        std::transform(numbers.begin(), numbers.end(), words.begin(), std::inserter(wordsAndNumbers, wordsAndNumbers.end()), [](auto& number, auto& word){return std::pair<int, std::string>(number, word);});
    }
    return wordsAndNumbers;
}