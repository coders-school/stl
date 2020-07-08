#include "compression.hpp"

#include <iostream>

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
    returnValue.reserve(maximumVectorSize);
    bool breakColumnLoop{};
    size_t repetitionCount{};
    size_t repetitionIterator{};
    size_t ColumnIterator{};
    
    for(size_t rowIterator = 0; rowIterator < height; ++rowIterator) {
        breakColumnLoop = false;
        ColumnIterator = repetitionIterator = 0;
        while(!breakColumnLoop) {
            if(input[rowIterator][ColumnIterator] == input[rowIterator][repetitionIterator]) {
                ++repetitionCount;
                ++repetitionIterator;
            } else {
                returnValue.emplace_back(input[rowIterator][ColumnIterator], 
                                         static_cast<uint8_t>(repetitionCount));
                repetitionCount = 0;
                ColumnIterator = repetitionIterator;
            }
            if (repetitionIterator == width) {
                returnValue.emplace_back(input[rowIterator][ColumnIterator], 
                                         static_cast<uint8_t>(repetitionCount));
                repetitionCount = 0;
                breakColumnLoop = true;
            }
        }
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
