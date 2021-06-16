#include "vowel.hpp"

void removeVowels (std::vector<std::string>& input_sentences) {
    std::regex vowels("a|A|e|E|i|I|o|O|u|U|y|Y|ą|Ą|ę|Ę");
    std::for_each(input_sentences.begin(), input_sentences.end(), [vowels](std::string& sentence_from_vector){
        sentence_from_vector = std::regex_replace(sentence_from_vector, vowels, "");
    });
}