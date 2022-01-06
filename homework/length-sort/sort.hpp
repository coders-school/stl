#pragma once

#include <deque>
#include <forward_list>
#include <string>

// Returns std::deque with words sorted from the shortest to the longest or
// lexicographically if they have the same length.
// Takes words to sort
std::deque<std::string> lengthSort(const std::forward_list<std::string>& words);