#include "compression.hpp"

std::vector<std::pair<std::uint8_t, std::uint8_t>> compressGrayscale(const std::array<std::array<std::uint8_t, 240>, 160>& image_array) {
    std::vector<std::pair<std::uint8_t, std::uint8_t>> amount_of_gray;
    amount_of_gray.reserve(image_array.size());
    std::for_each(image_array.begin(), image_array.end(), [&amount_of_gray](std::array<std::uint8_t, 240> row){
        std::uint8_t unique = 0;
        std::uint8_t act_color = row[0];
        int it = 1;
        for (auto color_in_row : row) {
            if (act_color == color_in_row) {
                ++unique;
            }
            else {
                amount_of_gray.push_back(std::make_pair(act_color, unique));
                unique = 1;
            }
            if (row.size() == it) {
                amount_of_gray.push_back(std::make_pair(act_color, unique));
                unique = 1;
            }
            act_color = color_in_row;
            ++it;
        }
    }
    );
    amount_of_gray.shrink_to_fit();
    return amount_of_gray;
}

std::array<std::array<std::uint8_t, 240>, 160> decompressGrayscale(const std::vector<std::pair<std::uint8_t, std::uint8_t>>& image_vector) {
    std::array<std::array<std::uint8_t, 240>, 160> image_array;
    std::uint8_t amount = static_cast<std::uint8_t>(0);
    std::for_each(image_vector.begin(), image_vector.end(), [&image_array, &amount](std::pair<std::uint8_t, std::uint8_t> pairs){
        static int inside_array_size = 0;
        std::fill_n(image_array[inside_array_size].begin() + amount, std::get<1>(pairs), std::get<0>(pairs));
        amount += std::get<1>(pairs);
        if (amount == image_array[inside_array_size].size()) {
            amount = 0;
            ++inside_array_size;
        }
    }
    );
    return image_array;
}