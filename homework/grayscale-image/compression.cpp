#include"compression.hpp"

std::vector<std::pair<uint8_t,uint8_t>>  compressGrayscale(std::array<std::array<uint8_t,width>,height> bitmap) {
std::vector<std::pair<uint8_t,uint8_t>>  out;
std::pair<uint8_t,uint8_t> p;

for(auto& el_h:bitmap)  {               //przeglądanie po wierszach

    for(auto& el_v:el_h)    {           //przeglądanie po kolumnach (el. w wierszu)
        if (&el_v==el_h.begin())    {   //zerowanie, gdy pierwszy element w rzędzie
            p.second=1;
            p.first=el_v;
            }
        else    {                       //zliczanie (kompresja) gdy każdy następny element w rzędzie
            if(el_v==p.first)
                p.second++;
            else    {
                out.push_back(p);
                p.first=el_v;
                p.second=1;
                }
            }
       }
        out.push_back(p);               //załadowanie ostatniego elementu

    }

//.first -  wartość pixela
//.secound - ilość pixeli o danej wartości
return out;
}



std::array<std::array<uint8_t,width>,height>  decompressGrayscale(std::vector<std::pair<uint8_t,uint8_t>>  compressed)   {
std::array<std::array<uint8_t,width>,height> out;

auto input_it = compressed.begin();

for(auto& row:out)  {
    uint8_t ix = 0;         //index do zliczania elementów o danej wartości, które już są przepisane do bitmapy
    for(auto& el:row)    {
        el=input_it->first;
        if(++ix==input_it->second)  {
            input_it++;
            ix=0;
        }        
    }
}

return out;
}

void printMap(std::array<std::array<uint8_t,width>,height> bitmap)  {
    for(auto& el_h:bitmap)  {               //przeglądanie po wierszach
        for(auto& el_v:el_h)    {           //przeglądanie po kolumnach (el. w wierszu)
            std::cout<<(char)(el_v+32);
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}