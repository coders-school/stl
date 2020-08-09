#include "compress.hpp"
#include <vector>
#include <array>
#include <algorithm>

compressed_vec compressGrayscale(bitmap_array const bitmap)
{
    compressed_vec out_vec;
    const uint8_t* registered_value = nullptr;
    for(auto row = bitmap.begin(); row < bitmap.end(); row++)
    {
        registered_value = row->begin();
        while(true)
        {

            auto iter = std::find_if(registered_value, row->end(),
                [registered_value](
                uint8_t elem)
                {
                    return elem != *registered_value;
                }
            );

            out_vec.push_back(std::make_pair(*registered_value,
                    iter - registered_value));
            registered_value = iter;
            if(iter == row->end()) break;
        }
    }

    return out_vec;

}