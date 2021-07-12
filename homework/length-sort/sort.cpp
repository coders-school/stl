#include"sort.hpp"
#include<cstring>


bool compare(std::string str1, std::string str2)    {
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1<len2)   return true;
    if(len1>len2)   return false;
    if(len1==len2)  {
        if(str1.compare(str2)<0) return true;
        return false;

        /*auto letter2=str2.begin();
        for(char& letter:str1)  {
            //jak porównać chary z uwzględnieniem wielkości litery??
            
            if(letter<letter2)  return true;
            if(letter>letter2)  return false;
            letter2++;
        }   */
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string>& input) {

std::deque<std::string> output;
//sortowanie podobno działa na forward_liście

output = input.sort(compare);



return output;
}

