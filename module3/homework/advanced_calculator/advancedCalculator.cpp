#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double& out){


    return ErrorCode::Ok;
}


class mathOperationData{

    public:
    mathOperationData();
    double getFirstValue();
    double getSecondValue();
    char getSign();
    void setString(std::string string);
    void setResult(double result);

    private:
    double firstValue_;
    double secondValue_;
    char sign_;
    double result_;
}