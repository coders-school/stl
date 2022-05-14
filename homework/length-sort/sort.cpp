#include "sort.hpp"


bool mycomp(std::string a, std::string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a<b;
}

void alphabaticallySort(std::deque<std::string>& a){
	int n=a.size();
	//mycomp function is the defined function which 
	//sorts the strings in alphabatical order
	sort(a.begin(),a.end(),mycomp);
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list)
{
    //std::sort(list.begin(), list.end());
    std::deque<std::string> deq;
    for(auto word : list)
    {
        deq.push_back(word);
    }
    //std::sort(deq.begin(), deq.end());
    alphabaticallySort(deq);
    return deq;
}
	