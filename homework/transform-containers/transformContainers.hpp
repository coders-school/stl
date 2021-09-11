#pragma once
#include <deque>
#include <list>
#include <map>
#include <string>

template<typename Container>
void print(Container container);
void printMap(std::map<int,std::string> c);
void removeListDuplicates(std::list<std::string>& list);
void removeDequeDuplicates(std::deque<int>& deque);
void generateMap(std::deque<int>& deque, std::list<std::string>& list, std::map<int,std::string>& map);
std::map<int,std::string> removeDuplicateAndTranformToMap( std::list<std::string>, std::deque<int>);
