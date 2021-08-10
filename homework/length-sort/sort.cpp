#include "sort.hpp"

void sortBySize(std::deque<std::string>& dq){
    for(int i=0;i<dq.size();i++){
        for(int j=0;j<dq.size()-1;j++){
            if(dq[j].size() > dq[j+1].size()){
                auto help = dq[j];
                dq[j] = dq[j+1];
                dq[j+1] = help;
            }
        }
    }
}

void sortByAlphabet(std::deque<std::string>& dq){
    for(int i=0;i<dq.size();i++){
        for(int j=0;j<dq.size()-1;j++){
            if(dq[j] > dq[j+1]){
                auto help = dq[j];
                dq[j] = dq[j+1];
                dq[j+1] = help;
            }
        }
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string> fl){
    std::deque<std::string> dq;
    for(auto it=fl.begin();it!=fl.end();it++){
        dq.push_back(*it);
    }
    sortByAlphabet(dq);
    sortBySize(dq);
    return dq;
}