#include "insensitivePalindrom.hpp"

#include <iostream>

int main(){
   auto str = "Że też łże jeż? łże też!";
   if(is_palindrome(str)){
      std::cout<<"Is palindrome\n";
   }else{
      std::cout<<"Isn't palindrome\n";
   }

   return 0;
}
