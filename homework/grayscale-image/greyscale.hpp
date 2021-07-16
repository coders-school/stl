#include<array>
#include<vector>
//#include<utility>

constexpr uint8_t width = 32;
constexpr uint8_t height = 32;

std::vector<std::pair<uint8_t,uint8_t>>  compressGrayscale(std::array<std::array<uint8_t,width>,height>);
std::array<std::array<uint8_t,width>,height>  decompressGrayscale(std::vector<std::pair<uint8_t,uint8_t>>);
