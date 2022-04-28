#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    // check if correct format was used (only 1 operator per call, 1-2 operands)
    ErrorCode formatting = checkFormat(input);
    if(formatting == ErrorCode::BadFormat) {
        return ErrorCode::BadFormat;
    } else if(formatting == ErrorCode::BadCharacter) {
        return ErrorCode::BadCharacter;
    }
    // remove whitespaces from string
    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());
    // find correct operator
    // if using modulo, return error if A is not an integer
    // find both (or one) operands and store in variables
    // if dividing return error if B == 0
    // if using sqrt, return error if A < 0
    // calculate A @ B using correct operator
    // return result
    return ErrorCode::OK;
}

ErrorCode checkFormat(const std::string& str) {
    // case 1: using multiple operators in one call -------> ErrorCode::BadFormat
    // case 2: using , instead of . -------> ErrorCode::BadFormat
    // case 3: incorrect order, using ' ' between two operands -------> ErrorCode::BadFormat
    // case 4: using two operands with unary operator -------> ErrorCode::BadFormat
    // case 5: using forbidden character: A-Z a-z @ ; # \ ? @ & ] [ } { ~ ` -------> ErrorCode::BadCharacter
    // case 6: too many operands -------> ErrorCode::
    // case 7: using too many dot separators -------> ErrorCode::BadFormat
    if(checkForForbiddenCharacters(str)) {return ErrorCode::BadCharacter;}
    if(checkForCommas(str)) {return ErrorCode::BadFormat;}
    if(checkForMultipleOperators(str)) {return ErrorCode::BadFormat;}
    if(checkForAdjacentOperands(str)) {return ErrorCode::BadFormat;}
    if(checkForTwoOperandsWithUnaryOp(str)) {return ErrorCode::BadFormat;}
    if(checkForMultipleDotSeparators(str)) {return ErrorCode::BadFormat;}
    return ErrorCode::OK;
}
bool checkForMultipleOperators(const std::string& str) {
    return (std::count_if(begin(str), end(str), [](const char& c){
        return (
            (c == '+') || (c == '-') || (c == '*') || (c == '/') ||
            (c == '%') || (c == '!') || (c == '^') || (c == '$')
        );
    }) > 1);
}
bool checkForCommas (const std::string& str) {
    return std::any_of(begin(str),
                       end(str), 
                       [](const char& c){
                           return (c == ',');
                        }
    );
}
bool checkForForbiddenCharacters(const std::string& str) {
    return std::any_of(str.begin(), str.end(), [](const char& c){
        return (
            (c == '[') || (c == ']') || (c == '{') || (c == '}') ||
            (c == '<') || (c == '>') || (c == '`') || (c == '~') ||  
            (c == '&') || (c == '@') || (c == '?') || (c == '\\') ||
            (c == '|') || (c == '#') || (c == ';') || (c == ']') ||
            (c == '=') || (std::isalpha(c))
        );
    });
}
bool checkForAdjacentOperands(const std::string& str) {
    size_t pos = 0;
    size_t prevPos = 0;
     
    while(pos != std::string::npos) {
        pos = str.find(' ', pos+1);
        if(pos == std::string::npos) {return false;}
        prevPos = pos-1;
        if(pos >= str.length()-1) {return false;}
        while(str.at(pos+1) == ' ') {
            if(pos+1 == str.length()-1) {
                return false;
            }
            ++pos;
        }
        if((isdigit(str.at(prevPos))) && (isdigit(str.at(pos+1)))) {
            return true;
        }  
    }
    return false;
}
bool checkForTwoOperandsWithUnaryOp(const std::string& str) {
    // if ! detected AND ! is not the last char in string
        // if subrange from ! to end() contains non-white characters - return true
    // return false
    auto pos = str.find('!');
    if(pos != std::string::npos && pos != str.length()) {
        auto it = str.begin();
        std::advance(it, pos);
        if(std::any_of(it, str.end(), isspace)) {return true;}
    }
    return false;
}
bool checkForMultipleDotSeparators(const std::string& str) {
    
    if(str.at(0) == '.') {return true;}
    auto prevPos = 0;
    auto nextPos = 0;
    auto itBegin = str.begin();
    auto itEnd = str.end();
    while(prevPos != std::string::npos && nextPos != std::string::npos) {
        prevPos = str.find('.', nextPos+1);
        if(prevPos == std::string::npos) {return false;}
        nextPos = str.find('.', prevPos+1);
        if(nextPos == std::string::npos) {return false;}
        itBegin = str.begin();
        itEnd = str.begin();
        std::advance(itBegin, prevPos+1);
        std::advance(itEnd, nextPos);
        if(std::all_of(itBegin, itEnd, isdigit)) {return true;}
    }
    return false;
}