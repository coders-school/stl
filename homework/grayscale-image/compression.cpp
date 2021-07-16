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
                // std::cout<<'{'<<(int)p.first<<", "<<(int)p.second<<"} ";
                p.first=el_v;
                p.second=1;
                }
            }
       }
        out.push_back(p);               //załadowanie ostatniego elementu
        //std::cout<<'{'<<(int)p.first<<", "<<(int)p.second<<"} \n";

    }

return out;
}



std::array<std::array<uint8_t,width>,height>  decompressGrayscale(std::vector<std::pair<uint8_t,uint8_t>>  compressed)   {
std::array<std::array<uint8_t,width>,height> out;

return out;
}