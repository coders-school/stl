#include "grays.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160> generateNinja)
{
    auto tmp = generateNinja.front();
    auto count = 0;
    uint8_t multiply = 0;
    uint8_t el = 0;
    std::vector<std::pair<uint8_t, uint8_t>> vec;
    vec.reserve(240 * 160);

    for (auto height = 0; height < 160; height++)
    {
        for (auto width = 0; width < 240; width++)
        {
            if (tmp == generateNinja[width])
            {
                count++;
            }
            else
            {
                vec.emplace_back(el, count);
                count = 1;
            }
        }
    }
}