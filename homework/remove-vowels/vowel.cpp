#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vec)
{
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            if(vec[i][j]=='a' || vec[i][j]=='e'  || vec[i][j]=='i' || vec[i][j]=='o' || vec[i][j]=='u' || vec[i][j]=='y' || vec[i][j]=='A' || vec[i][j]=='E'  || vec[i][j]=='I' || vec[i][j]=='O' || vec[i][j]=='U' || vec[i][j]=='Y')
            {
                vec[i].erase(j,1);
                j--;
            }
        }
    }
}
