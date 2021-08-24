# pragma once
#include <deque>
#include <list>
#include <map>
#include <string>

void removeDuplicate(std::list<std::string> &);
void removeDuplicate(std::deque<int> &);
void TranformToMap(std::list<std::string>&, std::deque<int>&,std::map<int, std::string>&);
std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> &, std::deque<int> &);
