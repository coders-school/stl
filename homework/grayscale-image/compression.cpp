#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> result;
    uint8_t next_el = ' ';
    auto compare = [&](auto el){
        if(el != next_el) {
            std::fill_n(std::back_inserter(result), 1, std::make_pair(el, 1));
        }
        else {
            result[result.size() - 1].second += 1;
        }
        next_el = el;
    };
    std::for_each(arr.begin(), arr.end(), [&](auto a){
        next_el = ' ';
        std::for_each(a.begin(), a.end(), compare);
    });
    return result;
}

 std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& vec) {
     std::array<std::array<uint8_t, width>, height> result{};
     std::for_each(vec.begin(), vec.end(), [it = result.begin(), counter = 0](const auto& el) mutable {
         std::fill_n(it->begin() + counter, el.second, el.first);
         counter += el.second;
         if(counter == width) {
             ++it;
             counter = 0;
         }
     });
     return result;
 }

