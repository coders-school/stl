#include"palindrom.hpp"

bool is_high_letter(char a)
{
    if(a >= 65 && a <= 90) return true;
    else return false;
}

bool is_low_letter(char a)
{
    if(a >= 97 && a <= 122) return true;
    else return false;
}

bool is_palindrome(std::string str)
{
     auto p = str.size()/2;
     auto q = str.size()/2;
     if(str.size() % 2 == 0) q++;
     while(p != -1 && q == str.size())
     {
         if(str[p] != str[q])
         {

         }
     }
}