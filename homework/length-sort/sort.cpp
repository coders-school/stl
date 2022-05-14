#include "sort.hpp"


bool myCompAlphabatically(std::string a, std::string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a<b;
}

bool myCompSize(std::string a, std::string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a.size()<b.size();
}

void alphabaticallySort(std::deque<std::string>::iterator from, std::deque<std::string>::iterator to){
	//int n=a.size();
	//mycomp function is the defined function which 
	//sorts the strings in alphabatical order
	sort(from, to, myCompAlphabatically);
}

void sizeSort(std::deque<std::string>& a){
	int n=a.size();
	//mycomp function is the defined function which 
	//sorts the strings in alphabatical order
	sort(a.begin(),a.end(),myCompSize);
}

void sortSection(std::deque<std::string>& a){
	int n=a.size();
	//int temp = 0;
    //int max = 0;
    std::deque<std::string>::iterator it1 = a.begin();
    std::deque<std::string>::iterator it2 = a.begin();
    //for(auto word : a)
    //{
    //    if(word.size() > max) max = word.size();
    //}
    while(true)
    {
        //it2 = it1;
        if(it2 != a.end())
        {
            alphabaticallySort(it1, it2);
            break;
        }
        else
        {
            int temp = (*it1).size();
            while((*it2).size() == temp)
            {
                std::advance(it2, 1);
            }
            it2 -= 1;
            alphabaticallySort(it1, it2);
            it1 = it2;
        }

        //if(temp == max) break;
    }
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
    sizeSort(deq);

    return deq;
}
	