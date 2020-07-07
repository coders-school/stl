#include "transform.hpp"

bool AnyContainerIsEmpty(const strList& strList, const intDeque& intDeq) {
    return strList.empty() || intDeq.empty();
}

bool ContainersSizeIsNotEqual(const strList& strList, const intDeque& intDeq) {
    return strList.size() != intDeq.size();
}

intStrMap removeDuplicateAndTranformToMap(strList strList, intDeque intDeq) {
    intStrMap returnValue{};
    if(AnyContainerIsEmpty(strList, intDeq)) { 
        return returnValue;
    }
    strList.sort();
    std::sort(begin(intDeq), end(intDeq));
    strList.erase(std::unique(begin(strList), end(strList)), end(strList));
    intDeq.erase(std::unique(begin(intDeq), end(intDeq)), end(intDeq));
    if(ContainersSizeIsNotEqual(strList, intDeq)) { 
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
