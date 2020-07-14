#include "transform.hpp"

#include <algorithm>

intStrMap removeDuplicateAndTranformToMap(strList strList, intDeque intDeq) {
    intStrMap returnValue{};
    if(strList.empty() || intDeq.empty()) {
        return returnValue;
    }
    strList.sort();
    std::sort(begin(intDeq), end(intDeq));
    strList.erase(std::unique(begin(strList), end(strList)), end(strList));
    intDeq.erase(std::unique(begin(intDeq), end(intDeq)), end(intDeq));
    if(strList.size() != intDeq.size()) {
        return returnValue;
    }
    std::transform(begin(intDeq), 
                   end(intDeq), 
                   begin(strList),
                   std::inserter(returnValue, end(returnValue)),
                   [](int num, std::string str){
                        return std::make_pair(num, str);
                   });
    return returnValue;
}
