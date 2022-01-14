#include "sort.hpp"

std::vector<std::pair<uint8_t,uint8_t>>compressGrayscale(std::array<std::array<uint8_t,width>,height>pgm_arr)
{
    std::vector<std::pair<uint8_t,uint8_t>>temp_result;
    std::array<uint8_t,width>temp_arr;

    for(int i=0;i<(int)height;i++)
    {
        for(int j=0;j<(int)width;j++)
        {
            temp_arr[j]=pgm_arr[i][j];
        }

        //std::cout<<std::endl;
        int previous_number=temp_arr[0];
        int same_colour_number=0;
        int current_number=0;
        for(auto element:temp_arr)
        {
            //std::cout<<(unsigned)element<<" ";

            current_number++;
            if(current_number==width)
            {
                if(element==previous_number)
                {
                    same_colour_number++;
                    temp_result.push_back({previous_number,same_colour_number});
                }
                else
                {
                    temp_result.push_back({previous_number,same_colour_number});
                    temp_result.push_back({element,1});
                }
            }
            else if(element==previous_number)
            {
                same_colour_number++;
            }
            else
            {
                temp_result.push_back({previous_number,same_colour_number});
                same_colour_number=1;
            }
            previous_number=element;
        }
        //std::cout<<"Koniec pojedynczego arraya"<<"\n";
    }
    return temp_result;
}

std::array<std::array<uint8_t,width>,height>decompressGrayscale(std::vector<std::pair<uint8_t,uint8_t>>compression_result)
{
    std::vector<uint8_t>temp_vec;
    std::array<std::array<uint8_t,width>,height>temp_arr;

    for(auto element : compression_result)
    {
        for(int i=0;i<std::get<1>(element);i++)
        {
            temp_vec.push_back(std::get<0>(element));
        }
    }
    /*for(auto element : temp_vec)
    {
        std::cout<<(unsigned)element<<" ";
    }
    std::cout<<std::endl;*/

    for(int i=0;i<(int)height;i++)
    {
        for(int j=0;j<(int)width;j++)
        {
            temp_arr[i][j]=temp_vec[width*i+j];
        }
    }
    return temp_arr;
}
