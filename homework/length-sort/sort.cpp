#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string> lista) {
    std::deque<std::string> kolejka{};

    for (const auto& el : lista) {
        kolejka.push_back(el);
    }

    auto sortowanie = [](auto k, auto ko) {
        if (k.length() > ko.length()) {
            return false;
        } else if (k.length() == ko.length()) {
            if (k > ko)
                return false;
            else
                return true;
        } else {
            return true;
        }
    };

    std::sort(kolejka.begin(), kolejka.end(), sortowanie);
    return kolejka;
}