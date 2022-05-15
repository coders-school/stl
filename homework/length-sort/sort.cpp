#include "sort.hpp"

bool myCompAlphabatically(std::string a, std::string b)
{
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return false;
}

bool myCompSize(std::string a, std::string b)
{
    return a.size() < b.size();
}

void sizeSort(std::deque<std::string>& a)
{
    sort(a.begin(), a.end(), myCompSize);
}

void swap(std::deque<std::string>::iterator& a, std::deque<std::string>::iterator& b)
{
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

void mySortAlphabatically(std::deque<std::string>& a, std::deque<std::string>::iterator from, std::deque<std::string>::iterator to)
{
    int count = 0;
    auto tmp1 = from;
    auto tmp2 = to;
    if (tmp1 == tmp2)
    {
        count = 1;
    }
    else
    {
        count = 1;
        do
        {
            count++;
            std::advance(tmp1, 1);
        } while (tmp1 != tmp2);
    }
    if (count > 1)
    {
        for (int i = 0; i < count; i++)
        {
            tmp1 = from;
            tmp2 = from;
            std::advance(tmp2, 1);
            for (int j = 0; j < count - i; j++)
            {
                if (myCompAlphabatically(*tmp1, *tmp2))
                {
                    swap(tmp1, tmp2);
                }
                std::advance(tmp1, 1);
                std::advance(tmp2, 1);
            }
        }
    }
}

void sortSection(std::deque<std::string>& a)
{

    std::deque<std::string>::iterator it1 = a.begin();
    std::deque<std::string>::iterator it2 = a.begin();

    while (true)
    {
        std::deque<std::string>::iterator end = a.end();
        end -= 1;
        if (it2 == end)
        {
            mySortAlphabatically(a, it1, it2);
            break;
        }
        else
        {
            int temp = (*it1).size();
            while ((*it2).size() == temp)
            {
                auto t = end;
                if (it2 != t) std::advance(it2, 1);
                else break;
            }

            it2 -= 1;
            mySortAlphabatically(a, it1, it2);

            it1 = it2;
            std::advance(it1, 1);
            std::advance(it2, 1);
        }
    }
}

std::deque<std::string> lengthSort(std::forward_list<std::string> list)
{
    std::deque<std::string> deq;
    for (auto word : list)
    {
        deq.push_back(word);
    }
    sizeSort(deq);
    sortSection(deq);
    return deq;
}