#include "grayscale.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> array_1)
{
    std::vector<std::pair<uint8_t, uint8_t>>compres_vec;
    uint8_t p = 0;
    int number = 0;
    p = array_1[0][0];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (array_1[i][j] == p) {
                number++;
            } 
            else {
                compres_vec.push_back(std::make_pair(p,number));
                p = array_1[i][j];
                number = 1;

            }

        }

        
    }
    if(p==array_1[height-1][width-1])
    {
     compres_vec.push_back(std::make_pair(p,number));

    }
    return compres_vec;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t>>array_2)
{

std::vector<uint8_t>tab;
tab.reserve(width*height);
std::array<std::array<uint8_t, width>, height>tab2; 


         for(int i=0;i<array_2.size();i++)
         {
          int k=array_2[i].second;
              for(int j=0;j<k;j++)
               {
                tab.push_back(array_2[i].first);
               }
         }

        auto it=tab.cbegin();
        for (int i = 0; i < height; i++) 
        {
            
            for (int j = 0; j < width; j++)
            {
              
            tab2[i][j]=*it;
            std::cout<<*it<<' ';
            it++;
                
            }
           
        } 

     return tab2;


}

void printMap(std::array<std::array<uint8_t, width>, height>map)
{

 for (int i = 0; i < height; i++) 
        {
            
            for (int j = 0; j < width; j++)
            {
              
            std::cout<<int(map[i][j])<<' ';
                
            }
            std::cout<<std::endl;
        } 

std::cout<<std::endl;

}