#include "sort.hpp"

std::deque<std::string> lengthSort(std::forward_list<std::string>& words)
{
    words.sort();
    std::deque<std::string> deque(std::begin(words), std::end(words)); // put elements from forward_list to deque

    for (int i = 0; i < deque.size(); i++){
        std::string temp = deque[i];
        int j = i - 1;
        while(j >= 0 && temp.length() < deque[j].length())
        {
            deque[j + 1] = deque[j];
            j--;
        }
        deque[j + 1] = temp;
    }
    return deque;
}