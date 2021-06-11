#include "vowel.hpp"

void removeVowels(std::vector<std::string>& v)
   {
       for(auto& s : v)
       {
           std::string s2 = "";
           for(auto i=s.begin(); i != s.end(); i++)
           {
               if(!(*i == 'A' || *i == 'a'
               || *i == 'O' || *i == 'o'
               || *i == 'E' || *i == 'e'
               || *i == 'I' || *i == 'i'
               || *i == 'U' || *i == 'u'
               || *i == 'Y' || *i == 'y'))
               {
                   s2 += *i;
               }
           }
           s=s2;
       }

   }

