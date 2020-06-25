#include "compression.hpp" 

std::vector<std::pair<uint8_t, uint8_t>> compressOneLine(const  std::array<uint8_t,width>& line){

    uint8_t value;
    uint8_t previous_value=line[0];
    uint8_t cnt=1;
    std::vector<std::pair<uint8_t, uint8_t>> vect;
    auto it= line.cbegin();
    ++it;
    for(;it<line.cend();it++){
        if(*it==previous_value){
            cnt++;            
        }
        else{
            vect.push_back(std::make_pair(previous_value,cnt));   
            cnt=1;
        } 
        previous_value=*it;
    }
    if(cnt>1){
          vect.push_back(std::make_pair(previous_value,cnt));
          }
          return vect;
}
std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& image){
    std::vector<std::pair<uint8_t, uint8_t>> compressedImage;
    for(auto& line:image){
        auto compressedLine = compressOneLine(line);
        compressedImage.insert(compressedImage.end(), compressedLine.begin(), compressedLine.end()); 
    }
    return compressedImage;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>> comressedImage){

 std::array<std::array<uint8_t, width>, height> original;
    uint8_t carriage = 0; // max widith specified in homework <255
    uint8_t row = 0;

    for (auto el : comressedImage) {
        for (size_t column = carriage; column < carriage + std::get<1>(el); ++column) 
            original[row][column] =std::get<0>(el);
        carriage += std::get<1>(el);
        if (carriage >= width) {
            carriage = 0;
            ++row;
        }
    }
    return original;
}
