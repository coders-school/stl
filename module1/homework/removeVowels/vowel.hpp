#pragma once

#include <vector>
#include <string>

const std::string vovels = "aeioyAEIOY";

void removeVowels(std::vector<std::string>& lines)
{
    for(auto& line : lines)
    {
        for (int i = 0; i < line.length(); i++)
        {
            if(vovels.find(line[i]) != std::string::npos)
            {
                line.erase(i, 1);
            }
        }
    }
}