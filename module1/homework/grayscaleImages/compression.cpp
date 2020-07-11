#include "compression.hpp"

#include <iostream>
#include <limits>

char convert2Printable(uint8_t input) {
    return ::isgraph(input) ?  input : ' ';
}

void printMap(const RawMap& input) {   
    for(const auto& row : input) {
        for(const auto & cell : row) {
           std::cout << convert2Printable(cell);
        }
        std::cout << '\n';
        }
}

void printVectorOfPairs(const Compressed& input) {
    int elementCounter = 0;
    for(const auto& element : input) {
        elementCounter ++;
        std::cout << "{" << +element.first << ", " << +element.second << "}" << ' ';
        if(elementCounter % 32 == 0) {
            std::cout << "\n";
            
        }
    }
    std::cout << '\n';
}

Compressed compressGrayscale(const RawMap& input) {
    Compressed returnValue{};
    size_t maximumVectorSize = height * width;
    static_assert(width <  std::numeric_limits<uint8_t>::max());
    returnValue.reserve(maximumVectorSize);
    uint8_t repetitionCount{};
    size_t repetitionIterator{};
    size_t columnIterator{};
    
    for(size_t rowIterator = 0; rowIterator < height; ++rowIterator) {
        columnIterator = 0;
        repetitionCount = 1;
        for(int i = 1 ; i < width ; i++)
        {
            bool repetitionOccurs = input[rowIterator][columnIterator] == input[rowIterator][columnIterator + repetitionCount];
            if(repetitionOccurs){
                ++repetitionCount;
            } else{
                returnValue.emplace_back(input[rowIterator][columnIterator],
                                         repetitionCount);
                columnIterator += repetitionCount;
                repetitionCount = 1;
            }
        }
        returnValue.emplace_back(input[rowIterator][columnIterator],
                                 repetitionCount);
    }   
    returnValue.shrink_to_fit();
    return returnValue;
}

RawMap decompressGrayscale(const Compressed& inVec) {
    RawMap retArr{};
    size_t rowIterator{}, columnIterator{}, repetitionIterator{}, vectorIterator{};
    while(rowIterator < height) {
        columnIterator = 0;
        while(columnIterator < width) {
            repetitionIterator = 0;
            while(repetitionIterator < static_cast<size_t>(inVec[vectorIterator].second)) {
                retArr[rowIterator][columnIterator] = inVec[vectorIterator].first;
                ++columnIterator;
                ++repetitionIterator;
            }
            ++vectorIterator;
        }
        ++rowIterator;
    }
    return retArr;
}
