#include "inputStringCheck.hpp"
#include <algorithm>

bool isZero(const std::string& input) {
    return (input == "0" ||
            input == "-0" ||
            input == "0.0" ||
            input == "-0.0");
}

bool isDouble(const std::string& input) {
    if (isEmpty(input))
        return false;

    auto inputIt = input.begin();
    if (*inputIt == '-')
        inputIt++;

    if (*inputIt == '.' || inputIt == input.end())
        return false;

    int dotCounter = 0;
    for (inputIt; inputIt != input.end(); inputIt++) {
        if (*inputIt == '.')
            dotCounter++;
        if (!(std::isdigit(*inputIt) || *inputIt == '.') || dotCounter > 1)
            return false;
    }
    return true;
}

bool isIntiger(const std::string& input) {
    if (isEmpty(input))
        return false;

    auto inputIt = input.begin();
    if (*inputIt == '-')
        inputIt++;

    for (inputIt; inputIt != input.end(); inputIt++) {
        if (!std::isdigit(*inputIt))
            return false;
    }
    return true;
}

bool isNegative(const std::string& input) {
    return input.front() == '-';
}

bool isEmpty(const std::string& input) {
    return input.empty();
}

void removeSpaces(std::string& input) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
}
