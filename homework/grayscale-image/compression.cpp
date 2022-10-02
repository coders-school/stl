#include "compression.hpp"
#include <iostream>
#include <tuple>

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
        std::cout << unsigned(v.at(i)) << " ";
   }
   std::cout << std::endl;
}


std::vector<std::pair<uint8_t, uint8_t>> compress_single_line(const std::array<uint8_t, width>& v)
{
    std::vector<std::pair<uint8_t, uint8_t>>  output;
    uint8_t current_value = v[0];
    uint8_t old_value = v[0];
    int same_value_cnt = 0;
    std::cout << " s " << std::endl;
    for (size_t i = 0; i < std::size(v); ++i) {
           current_value = v[i];
           std::cout << " c = " << unsigned(current_value) << "\t";
           std::cout << " i = " << i << std::endl;
           if(current_value == old_value)
           {
                ++same_value_cnt;
           }
           else
           {
                output.push_back({old_value, same_value_cnt});
                old_value = current_value;
                same_value_cnt = 1;
           }
    }

    auto all_output_values_are_the_same = [&](){
        return output.empty();
    };

    auto are_still_unsaved_values = [&](){
        return same_value_cnt != 1;
    };

    if(all_output_values_are_the_same() or are_still_unsaved_values())
    {
        output.push_back({old_value, same_value_cnt});
    }
    std::cout << output.size() << std::endl;
    return output;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> input) {
    std::vector<std::pair<uint8_t, uint8_t>> pp;

    for (size_t h = 0; h < height; ++h) {
        auto line = input[h];
        print_line(line);
        auto compressed_line = compress_single_line(line);
        print_compressed_line_output(compressed_line);

        for(const auto& chunk : compressed_line)
        {
            pp.push_back(chunk);
        }
    }


    return pp;
}

std::tuple<bool, uint8_t, int> get_char_from_chunk(const std::pair<uint8_t, uint8_t>& chunk, int character_counter)
{
    bool end = false; 
    auto character = chunk.first;
    auto chunk_num = chunk.second;

    auto isEmptyChunk = [&](){ return chunk_num == 0;};
    auto wholeChunkIsAlreadyProcessed = [&](){ return character_counter == chunk_num;};

    auto print_values = [&](){
        std::cout << "get_char_from_chunk: end " << end << std::endl;
        std::cout << "get_char_from_chunk: character " << unsigned(character) << std::endl;
        std::cout << "get_char_from_chunk: character_counter " << character_counter << std::endl;
    };

    if(isEmptyChunk() or wholeChunkIsAlreadyProcessed())
    {
        std::cout << "get_char_from_chunk: Chunk empty or already processed" << std::endl;
        end = true;
        character = ' ';
        print_values();
        return std::make_tuple(end, character, character_counter);
    }
    else
    {
        std::cout << "Chunk needs to be process" << std::endl;
        if(character_counter++ < chunk_num)
        {
            std::cout << "get_char_from_chunk: Return next character" << std::endl;
            print_values();
            return std::make_tuple(end, character, character_counter);
        }
            
    }

    std::cout << "get_char_from_chunk: goto default state" << std::endl;
    return std::make_tuple(false, character, character_counter);
}

std::tuple<bool, uint8_t, int> get_char_from_input(const std::vector<std::pair<uint8_t, uint8_t>>& input, int chunk_number)
{
    bool isInputProcessed = true;
    auto number_of_chunks = input.size();
    static int character_counter = 0;

    std::cout << "get_char_from_input: number_of_chunks = " << number_of_chunks << std::endl;
    if(number_of_chunks > 0)
    {
        auto chunk = input[chunk_number];
        
        bool isChunkProcessed;
        uint8_t character;

        std::tie(isChunkProcessed, character, character_counter) =  get_char_from_chunk(chunk, character_counter);

        if(not isChunkProcessed)
        {
            std::cout << "get_char_from_input: not isChunkProcessed" << std::endl;
            return std::make_tuple(isInputProcessed = false, character, chunk_number);
        }
        else
        {
            std::cout << "get_char_from_input: isChunkProcessed true" << std::endl;
            std::cout << "get_char_from_chunk: chunk_number " << chunk_number << std::endl;
            auto areAnyChunksNeededToProcess = [&](){
                std::cout << "get_char_from_input: areAnyChunksNeededToProcess?" << std::endl;
                return ++chunk_number < number_of_chunks;
            };
            std::cout << "get_char_from_chunk: chunk_number1 " << chunk_number << std::endl;

            if(areAnyChunksNeededToProcess())
            {
                std::cout << "get_char_from_chunk: chunk_number2 " << chunk_number << std::endl;
                std::cout << "get_char_from_chunk: character " << character << std::endl;
                character_counter = 0;
                return std::make_tuple(isInputProcessed = false, character, chunk_number);
            }
            else
            {
                std::cout << "get_char_from_input: areAnyChunksNeededToProcess: no" << std::endl;    
            }
        }
    }
    std::cout << "get_char_from_input: goto default state" << std::endl;
    character_counter = 0;
    return std::make_tuple(isInputProcessed = true, ' ', chunk_number);
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> input) {
    std::array<std::array<uint8_t, width>, height> output{};

    //print_compressed_line_output(input);

    uint8_t char_num = 0;
    size_t chunk_num = 0;
    uint8_t character = 0;
    for(size_t w = 0; w < width; ++w)
    {
        for(size_t h = 0;  h < height; ++h)
        {
            //std::tie(character, char_num, chunk_num) = get_char_from_input(input);
            //std::cout << "[" << w << "][" << h << "]= " << unsigned(character) << std::endl;
            //output[w][h] = character;
        }
    }

    return output;
}