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

    //print_compressed_line_output(input);

    using input_t = std::vector<std::pair<uint8_t, uint8_t>>;
    std::queue<uint8_t> q;

    for(size_t iter = 0; iter < input.size(); ++iter)
    {
        std::pair<uint8_t, uint8_t> x = input.at(iter);
        auto character = x.first;
        auto howmany = x.second;
        for(int i = 0; i < howmany; ++i)
            q.push(character);
    }

    for(size_t w = 0; w < width; ++w)
    {
        for(size_t h = 0;  h < height; ++h)
        {
            //std::tie(character, char_num, chunk_num) = get_char_from_input(input);
            uint8_t character = q.front();
            q.pop();
            //std::cout << "[" << w << "][" << h << "]= " << unsigned(character) << std::endl;
            output[w][h] = unsigned(character);
        }
    }

    return output;
}