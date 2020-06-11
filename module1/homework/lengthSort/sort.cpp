#include "sort.hpp"

#include <algorithm>
#include <array>
#include <vector>

/*
///referencje?
struct StrCompare {
    bool operator()(std::string& str1, std::string& str2) {
        std::transform(str1.begin(), str1.end(), str1.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        std::transform(str2.begin(), str2.end(), str2.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (str1.length() > str2.length())
            return true;

        else if (str1.length() == str2.length()) {
            for (int i = 0; i < str1.length(); i++) {
                if (str1[i] == str2[i])
                    continue;
                else if (str1[i] > str2[i])
                    return false;

                return true;
            }
        }

        return false;
    }
};

std::deque<std::string>
lengthSort(std::forward_list<std::string> list) {
    list.sort(StrCompare());

    // std::array < std::string, list.std::vector<std::string> vec{};

    // std::copy(list.begin(), list.end(), vec);

    // std::sort(vec.begin(), vec.end(), CompareStrings);  //  czy tu na pewno można tak returnopwać od razu?

    // std::deque<std::string> sorted_strings;
    // for (auto el : list)
    //     sorted_strings.push_back(el);

    std::deque<std::string> result;
    std::transform(list.begin(), list.end(), std::back_inserter(result), [](std::string& s) { return s; });
    return result;
}
*/

#include <algorithm>

#include "sort.hpp"

struct StrCompare {
    bool operator()(const std::string& str1, const std::string& str2) {
        if (str1.size() == str2.size()) {
            return str1 < str2;
        }
        return str1.size() < str2.size();
    }
};

std::deque<std::string> lengthSort(std::forward_list<std::string> inputList) {
    inputList.sort(StrCompare());
    std::deque<std::string> result;
    for (const auto el : inputList)
        result.push_back(el);

    return result;
}
