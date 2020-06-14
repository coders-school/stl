#include "uniquemap.hpp"

#include <algorithm>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string>& inputList,
                                                           std::deque<int>& inputDeque) {

auto readyTotransform = [&](auto input){
    std::sort(input.begin(), input.end());
    input.erase(std::unique(input.begin(), input.end()), input.end());
};

readyTotransform(inputList);
readyTotransform(inputDeque);


//std::sort(inputList.begin(), inputList.end());
//std::sort(inputDeque.begin(), inputDeque.end());

//inputList.erase(std::unique(inputList.begin(), inputList.end()), inputList.end());
//inputDeque.erase(std::unique(inputDeque.begin(), inputDeque.end()), inputDeque.end());

std::map<int, std::string> outputMap;
std::transform(inputDeque.begin(), inputDeque.end(), inputList.begin(), outputMap.begin());

return outputMap;
}