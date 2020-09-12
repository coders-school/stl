#include "AppendNewRecipe.hpp"

int main(){
    std::list<std::string> skladniki{"gin", "wóda", "tequilla", "sok pomarańczowy"};
    std::deque<std::pair<size_t, char>> ilosc{ {40, 'm'},
                                               {30, 'm'},
                                               {50, 'm'},
                                               {10, 'g'}};
    std::vector<std::string> kroki{"wrzuc wszystko", "wymieszaj", "wypij ze smakiem byczku smacznego"};
    AppendNewRecipe(kroki, skladniki, ilosc);

    return 0;
}