#include "transformContainers.hpp"

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list_str, std::deque<int> deq_int)
{
    std::map<int, std::string> map;

    auto print_list = [&] (int id) {
        std::cout << "@" << id << ": ";
        for (auto i : list_str)
            std::cout << i << ' ';
        std::cout << '\n';
    };

    print_list(1);

    //std::sort(list_str.begin(), list_str.end());
    std::sort(deq_int.begin(), deq_int.end());
    list_str.sort();
    
    auto last_list = std::unique(list_str.begin(), list_str.end());
    auto last_deq = std::unique(deq_int.begin(), deq_int.end());

    list_str.erase(last_list, list_str.end());
    deq_int.erase(last_deq, deq_int.end());

    print_list(2);

    return map;
}