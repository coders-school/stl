#include "sort.hpp"
#include <forward_list>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words)
{
    std::deque<std::string> sorted_words;
    std::string temp_word;

    for(std::forward_list<std::string>::iterator it = words.begin(); it != words.end(); it++)
    {
        sorted_words.push_back(*it);
    }

    int sort_begin = 0;
    int moved_word_id = sort_begin;
    while (sort_begin < sorted_words.size())
    {
        for(int j = sort_begin; j < sorted_words.size(); j++)
        {
            if(moved_word_id != j)
            {
                if(sorted_words[moved_word_id].length() < sorted_words[j].length())
                {
                    moved_word_id = j;
                }
                else if ((sorted_words[moved_word_id]).length() == (sorted_words[j]).length())
                {
                    for(int k = 0; k < (sorted_words[j]).length(); k++)
                    {
                        if((sorted_words[moved_word_id])[k] < (sorted_words[j])[k])
                        {
                            moved_word_id = j;
                            break;
                        }
                        else if((sorted_words[moved_word_id])[k] > (sorted_words[j])[k])
                        {
                            break;
                        }
                    }
                }
            }
        }
        temp_word = sorted_words[moved_word_id];
        sorted_words.erase(sorted_words.begin() + moved_word_id);
        sorted_words.push_front(temp_word);
        sort_begin++;
        moved_word_id = sort_begin;
    }

    return sorted_words;
}