#include "advancedCalculator.hpp"

int main()
{
    std::string in{};

    while (1) {
        std::cout << "Provide calculation: ";
        std::getline(std::cin, in);
        std::cout << in << std::endl;

        double res = 0.0;
        auto err = process(in, &res);
        if (err == ErrorCode::OK) {
            std::cout << "Result: " << res << std::endl;
        } else {
            std::cout << "Error: " << err << std::endl;
        }
    }
    return 0;
}