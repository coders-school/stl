#include "advancedCalculator.hpp"

int main()
{
    std::cout << "Dodawanie, mnożenie, dzielenie, odejmowanie, (+, *, /, -)," << '\n';
    kalkulator['+'](1,2);
    kalkulator['*'](3,2);
    kalkulator['/'](1,2);
    kalkulator['-'](1,2);
    kalkulator['^'](4,2);
    kalkulator['%'](9,2);

}