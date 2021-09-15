#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height>& array) {
    
    std::vector<std::pair<uint8_t, uint8_t>> res;

    auto count = [&res](const auto& row) {
        for (auto it = row.begin(), e = row.end(); it != e; /*Empty*/) {
            const auto it2 = std::find_if(it, e, [&it](const auto& val) { return val != *it; });
            res.emplace_back(*it, std::distance(it, it2));
            it = it2;
        }
    };

    std::for_each(array.cbegin(), array.cend(), count);

    return res;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>& pair) {
    std::array<std::array<uint8_t, width>, height> ret;

    auto fill = [&pair](auto& row){
        auto it = row.begin();
        size_t i = 0;
        while(it != row.end())
        {   
            it = std::fill_n(it, pair.at(i).second, pair.at(i).first);
            if (i < pair.size()) ++i;
        }
    };

    std::for_each(ret.begin(), ret.end(), fill);

    return ret;
}