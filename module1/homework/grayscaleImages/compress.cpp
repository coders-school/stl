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

bitmap_array decompressGrayscale(const compressed_vec comp_vec)
{
    int num_of_row = 0;
    std::vector<uint8_t> row = {};
    bitmap_array decompressed_data;
    for(const auto pair : comp_vec)
    {
        row.insert(row.end(), std::get<1>(pair), std::get<0>(pair));
        if(row.size() == width)
        {
            std::copy(row.begin(), row.end(), (decompressed_data[num_of_row]).begin());
            num_of_row++;
            row.erase(row.begin(), row.end());
            row.shrink_to_fit();
        }
    }

    return decompressed_data;
}