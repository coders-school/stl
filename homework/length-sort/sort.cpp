#include"sort.hpp"
#include<cstring>


bool compare(std::string& str1, std::string& str2)    {

    if(str1.length()<str2.length())   return true;
    if(str1.length()==str2.length())
        if(std::lexicographical_compare(str1.begin(),str1.end(),str2.begin(),str2.end()))
            return true;

    return false;
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& input) {

std::deque<std::string> output;
//sortowanie podobno działa na forward_liście
input.sort(compare);

//przepisanie do deque
for(auto&el:input)  output.emplace_back(el);
return output;
}

