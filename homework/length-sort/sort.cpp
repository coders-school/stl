#include "sort.hpp"

struct compare_length {
    bool operator()(const std::string &l, const std::string &r) const {
        return l.size()<r.size();
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> input){
    std::deque<std::string> output;

  //copy forward list to deque
    auto numb = std::distance(std::begin(input), std::end(input));
    output.resize(numb);
    std::copy(std::begin(input),std::end(input),std::begin(output));

  //sort alphabeticaly when equal
    std::sort(output.begin(), output.end());

  //sort by size, from shortest
    std::sort(std::begin(output), std::end(output), compare_length());  
  

  return output;
}