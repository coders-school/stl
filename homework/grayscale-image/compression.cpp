#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>>
compressGrayscale(std::array<std::array<uint8_t, width>, height> arr)
{
    std::vector<std::pair<uint8_t, uint8_t> > vecP{};
    std::vector<uint8_t> vec{};

    std::transform(begin(arr), end(arr), std::back_inserter(vec), [&vec](auto a) {
        return std::copy(begin(a), end(a), std::back_inserter(vec));
    });

    auto m = vec.begin();
    auto inc{ 1 };
    uint8_t cnt{ 1 };

    std::transform(begin(vec), end(vec), std::back_inserter(vecP), [&](auto a) {
        if ((inc++ % width == 0) || m != std::adjacent_find(m, vec.end())) {
            auto cnt_temp = cnt;
            cnt = 1;
            ++m;
            return (std::make_pair(a, cnt_temp));
        } else {
            ++cnt;
            ++m;
            return (std::make_pair(static_cast<uint8_t>(0), static_cast<uint8_t>(0)));
        }
    });

    vecP.erase(std::remove(begin(vecP), end(vecP),
                   std::make_pair(static_cast<uint8_t>(0), static_cast<uint8_t>(0))),
        end(vecP));

    return vecP;
}

std::array<std::array<uint8_t, width>, height>
decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> vecP)
{
    std::array<std::array<uint8_t, width>, height> out_arr{};
    std::vector<int> vec{};
    auto cnt{ 1 };

    std::transform(begin(vecP), end(vecP), std::back_inserter(vec), [&](auto p) {
        ++cnt;
        return (std::move(vec.insert(end(vec), p.second, p.first)),
            end(vec), std::back_inserter(vec));
    });

    std::copy(begin(vec), end(vec), out_arr.front().begin());

    return out_arr;
}
