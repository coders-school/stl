#include <iostream>
#include <forward_list>
#include <deque>
#include <string>
#include <algorithm>

/*
Napisz funkcję lengthSort().

Ma ona przyjąć std::forward_list<std::string> i zwrócić std::deque<std::string> z posortowanymi słowami od najkrótszego do najdłuższego. Jeżeli dwa lub więcej słów ma tyle samo znaków posortuj je leksykograficznie.

    Input: std::forward_list<std::string>{"Three", "One", "Four", "Two"}
    Output: std::deque<std::string>{"One", "Two", "Four", "Three"}
*/



void print_fl(const std::forward_list<std::string>& input_fl)
{
    if (input_fl.empty())
        std::cout << "#### Given forward list is empty! ####" <<std::endl;
    else
    {
        for (auto it : input_fl)
            std::cout << it << " ";
        std::cout << '\n';
    }
}

void print_deque(const std::deque<std::string>& deque)
{

    if (deque.empty())
    {
        std::cout<< "#### Given deque is empty! ####\n";
    }
    else
    {
        for(const auto& el : deque)
        {
            std::cout << el << ' ';
        }
        std::cout<< '\n';
    }
}

bool compare_char(unsigned char x, unsigned char y)
{
    return tolower(x) < tolower(y);
}


bool compare_string(std::string input1, std:: string input2)
{
    if (input1.size() == input2.size())
        return std::lexicographical_compare(input1.begin(),input1.end(),input2.begin(),input2.end(), compare_char);

    return input1.size() < input2.size();
}



std::deque<std::string> lengthSort(std::forward_list<std::string> input)
{
    std::deque<std::string> output {};
    input.sort(compare_string);

    for (auto it = input.begin(); it != input.end(); ++it)
    {
        output.push_back(*it);

    }
    return output;
}


int main()
{
    std::forward_list<std::string> Input {"Three", "One", "Four", "Two"};
    //std::forward_list<std::string> Input2 {"Six", "Three", "One", "Four", "Two", "oNe" , "Seven", "Eight", "two", "one"};
    std::deque<std::string> Output = lengthSort(Input);

    print_fl(Input);
    print_deque(Output);


    return 0;
}
