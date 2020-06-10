#include <vector>
#include <array>

namespace{
    constexpr uint8_t WIDTH = 32;
    constexpr uint8_t HEIGHT = 32;
}

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, WIDTH>, HEIGHT>&);
