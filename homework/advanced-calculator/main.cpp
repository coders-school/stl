#include "advancedCalculator.hpp"

int main(){
    double result;
    process("5+ 11", &result);
    process("-11.230*-77.321", &result);
    process("6.7!", &result);
    return 0;
}
