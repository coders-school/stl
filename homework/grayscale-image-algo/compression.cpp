#include <algorithm>
#include <ranges>
#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr_bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    vec_c.reserve(width * height);
    auto last_color = arr_bitmap[0][0];
    int counter = 0;
    int temp = 0;

    std::ranges::for_each(arr_bitmap,
        [&vec_c, &last_color, &counter, &temp](const auto& row) {
            std::ranges::for_each(row,
                [&vec_c, &last_color, &counter, &temp](const auto& value) {
                    if (value == last_color && temp == 0) {
                        counter++;
                    }
                    else {
                        vec_c.emplace_back(last_color, counter);
                        last_color = value;
                        counter = 1;
                        temp = 0;
                    }
                });
                temp = 1;
        });
    vec_c.emplace_back(last_color, counter);  // add last pair to vec_c

    return vec_c;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> &vec_bitmap) 
{
    std::array<std::array<uint8_t, width>, height> arr_dec;
    auto bitmap_iter = arr_dec.front().begin();
    // is an iterator that will traverse all elements of arr_dec to fill them with values. 
    // auto is used to automatically infer the type of bitmap_iter based on the assigned value (arr_dec.front().begin())
    // front() returns a reference to the first element of this array, which is also an array. 
    // begin() is called on this "inner" array, returning an iterator pointing to its first element.
    for (const auto& pair : vec_bitmap){
        std::fill_n(bitmap_iter, pair.second, pair.first);
        std::advance(bitmap_iter, pair.second);
    }  
    return arr_dec;
}


/*
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale2(const std::array<std::array<uint8_t, height>, width>& bitmap)
{
    std::vector<std::pair<uint8_t, uint8_t>> vec_c;
    vec_c.reserve(width * height);
    auto last_color = bitmap[0][0];
    int counter = 0;

    for (const auto& row : bitmap)
    {      
        std::transform(row.begin(), row.end(), std::back_inserter(vec_c),
           [&counter, &last_color, &bitmap](uint8_t value) mutable {          
               if (value == last_color) {
                   counter++;
               }
               else { 
                   last_color = value;
                   counter = 1; 
                   return std::pair<uint8_t, uint8_t>(last_color, counter); 
               }
               return std::pair<uint8_t, uint8_t>(last_color, counter); 
           });

        // vec_c.erase(unique(vec_c.begin(), vec_c.end(),
        //     [](const auto & pair1, const auto &pair2){
        //
        //     return pair1.first == pair2.first;
        // })
        //, vec_c.end());
    }
    return vec_c;
}


/*bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
                     { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
                     { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };
// vec_c = {0, 4}, {1, 2}, {2, 1}, {3, 1}, {0, 27}, {4, 3}, {1, 5}, {0, 22}, {2, 5}, {1, 1}, {2, 4}, {0, 182},



int main()
{
    std::array<std::array<uint8_t, height>, width>
        bitmap = { { { 0, 0, 0, 1, 1, 2, 3, 0, 0, 0 },
            { 0, 0, 4, 4, 4, 1, 1, 1, 1, 1 },
            { 2, 2, 2, 2, 2, 1, 2, 2, 2, 2 } } };
   
    std::vector<std::pair<uint8_t, uint8_t>> vec_c = compressGrayscale(bitmap);
    std::for_each(begin(vec_c), end(vec_c), [vec_c](const std::pair<uint8_t, uint8_t>& p) {
    std::cout << "{" << static_cast<int>(p.first) << ", " << static_cast<int>(p.second) << "}, ";

//    for (auto it = vec_c.begin(); it != vec_c.end(); ++it) {
      //  std::cout << "{" << it->first << ", " << it->second << "}, ";
    //}
    });
    std::cout << std::endl;
    return 0;
}
*/