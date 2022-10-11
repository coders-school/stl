#include "compression.hpp"
#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>

void print_compressed_line_output(const std::vector<std::pair<uint8_t, uint8_t>>& v)
{
    std::cout << "[";
    for(const auto& compressed_line_chunk : v)
    {
        std::cout << "{" << unsigned(compressed_line_chunk.first) << ", " << unsigned(compressed_line_chunk.second) << "}";
    }
    std::cout << "]\n";

}

void print_line(const std::array<uint8_t, width>& v)
{
   for (size_t i = 0; i < std::size(v); ++i) {
        //std::cout << unsigned(v.at(i)) << " ";
   }
   //std::cout << std::endl;
}


std::vector<std::pair<uint8_t, uint8_t>> compress_single_line(const std::array<uint8_t, width>& line)
{
    std::vector<std::pair<uint8_t, uint8_t>>  output;
    uint8_t character = *line.begin();
    uint8_t old_character = *line.begin();
    int number_of_same_characters = 0;
    std::for_each(line.begin(), line.end(), [&](uint8_t character) mutable {
           if(character == old_character)
           {
                ++number_of_same_characters;
           }
           else
           {
                auto chunk = std::make_pair(old_character, number_of_same_characters);
                output.push_back(chunk);
                number_of_same_characters = 1;
           }
           old_character = character;
    });

    auto all_characters_are_the_same = [&](){
        return output.empty();
    };

    auto are_still_any_unsaved_values = [&](){
        return number_of_same_characters != 1;
    };

    if(all_characters_are_the_same() or are_still_any_unsaved_values())
    {
        auto chunk = std::make_pair(old_character, number_of_same_characters);
        output.push_back(chunk);
    }

    return output;    
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed_bitmap;

    std::for_each(input.begin(), input.end(), [&](auto line){
        auto compressed_line = compress_single_line(line);
        std::transform(compressed_line.begin(), 
                        compressed_line.end(), 
                        std::back_inserter(compressed_bitmap),
                        [](auto chunk){ 
                            return chunk;
        });
    });

    return compressed_bitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::array<std::array<uint8_t, width>, height> output{};

    auto chunkIt = input.begin();
    std::for_each_n(output.begin(), height, [&](auto& row){
        
        std::cout << "git3" << std::endl;
        auto rowIt = row.begin();
        std::cout << "git4" << std::endl;

        do{
        uint8_t character;
        uint8_t number_of_same_characters;
        auto chunk = *chunkIt;
        std::tie(character, number_of_same_characters) = chunk;
        std::cout << std::to_string(character) << " ; " << std::to_string(number_of_same_characters) << std::endl;
        std::fill_n(rowIt, number_of_same_characters, character); 
        std::advance(rowIt, number_of_same_characters);
        std::advance(chunkIt, 1);
        }while(rowIt != row.end());

        std::cout << "git1" << std::endl;
        std::for_each(row.begin(), row.end(), [&](auto x) {std::cout << std::to_string(x) << " ";}); std::cout << std::endl;
        std::cout << "git2" << std::endl;
        std::cout << "git2" << std::endl;
        std::cout << "git2" << std::endl;
    });       
    std::cout << "git5" << std::endl;
    std::cout <<  output.size() << std::endl;
    std::for_each(output.begin(), output.end(), [&](auto row){
        std::for_each(row.begin(), row.end(), [&](auto character){
            std::cout << std::to_string(character) << " ";
        });
        std::cout << std::endl;
    });
    return output;
}