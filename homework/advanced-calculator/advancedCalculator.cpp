#include "advancedCalculator.hpp"

ErrorCode process(std::string tempString, double *out)
{
    stringFormatting(tempString);

    if (BadCharacterCheck(tempString) == ErrorCode::BadCharacter)
        return (ErrorCode::BadCharacter);

    std::string stringNumber1;
    std::string stringOperation;
    std::string stringNumber2;

    extractingOperands(tempString, stringNumber1, stringOperation, stringNumber2);

    if (BadFormatCheck(stringNumber1, stringOperation, stringNumber2) == ErrorCode::BadFormat)
        return (ErrorCode::BadFormat);

    double number1 = stod(stringNumber1);
    char operation = stringOperation[0];
    double number2 = stod(stringNumber2);

    if (DivideBy0Check(operation, number2) == ErrorCode::DivideBy0)
        return (ErrorCode::DivideBy0);

    if (SqrtOfNegativeNumberCheck(number1, operation, number2) == ErrorCode::SqrtOfNegativeNumber)
        return (ErrorCode::SqrtOfNegativeNumber);

    if (ModuleOfNonIntegerValue(number1, operation, number2) == ErrorCode::ModuleOfNonIntegerValue)
        return (ErrorCode::ModuleOfNonIntegerValue);

    *out = doMath(number1, operation, number2);
    return (ErrorCode::OK);
}

void stringFormatting(std::string &tempStr)
{
    tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), ' '), tempStr.end());
    for (const auto &el : tempStr)
    {
        if (el == '!')
            tempStr = tempStr + "1";
    }
}

ErrorCode BadCharacterCheck(const std::string &tempStr)
{
    for (int i = 0; i < tempStr.size(); i++)
    {
        if (!(isdigit(tempStr[i]) || tempStr[i] == '+' || tempStr[i] == '-' || tempStr[i] == '*' || tempStr[i] == '/' || tempStr[i] == '%' || tempStr[i] == '!' || tempStr[i] == '^' || tempStr[i] == '$' || tempStr[i] == '.' || tempStr[i] == ','))
        {
            std::cout << "Incorrect data (error code: BadCharacter)";
            return (ErrorCode::BadCharacter);
        }
    }
    return (ErrorCode::OK);
}

void extractingOperands(std::string &tempStr, std::string &stringNum1, std::string &stringOper, std::string &stringNum2)
{
    std::string quickChange;

    bool isFirst = true;
    for (int i = 0; i <= tempStr.size(); i++)
    {
        if (isFirst == true)
        {
            if (tempStr[i] == NULL)
            {
                stringOper = '+';
                stringNum2 = '+';
                break;
            }
            if ((tempStr[i] == '+' || tempStr[i] == '-' || tempStr[i] == '*' || tempStr[i] == '/' || tempStr[i] == '%' || tempStr[i] == '!' || tempStr[i] == '^' || tempStr[i] == '$') && i != 0)
            {
                isFirst = false;
                stringNum1 = quickChange;
                quickChange.clear();
                stringOper = tempStr[i];
                continue;
            }
            quickChange += tempStr[i];
        }
        else
        {
            quickChange += tempStr[i];
        }
    }
    stringNum2 = quickChange;
}

ErrorCode BadFormatCheck(const std::string &stringNum1, const std::string &operation, const std::string &stringNum2)
{
    int addCount = 0;
    int dotCount = 0;
    
    //stringNum1 check
    for (int i = 0; i < stringNum1.size(); i++)
    {
        if (stringNum1[i] == ',')
        {
            std::cout << "Incorrect data (error code: BadFormat)";
            return (ErrorCode::BadFormat);
        }
        if (stringNum1[i] == '+')
        {
            addCount++;
        }
        if (stringNum1[i] == '.')
        {
            dotCount++;
        }
    }
    if (stringNum1[0] == '+')
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }

    //stringNum2 check
    for (int i = 0; i < stringNum2.size(); i++)
    {
        if (stringNum2[i] == ',')
        {
            std::cout << "Incorrect data (error code: BadFormat)";
            return (ErrorCode::BadFormat);
        }
        if (stringNum2[i] == '+')
        {
            addCount++;
        }
        if (isdigit(stringNum2[stringNum2.size() - 1]))
        {
            std::cout << "Incorrect data (error code: BadFormat)";
            return (ErrorCode::BadFormat);
        }
        if (stringNum1[i] == '.')
        {
            dotCount++;
        }
    }
    if (!(isdigit(stringNum2[0]) || stringNum2[0] == '0' || stringNum2[0] == '-'))
    {
        std::cout << stringNum2[0] << std::endl;
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }
    if (stringNum2[0] == '+')
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }
    if (!isdigit(stringNum2[stringNum2.size() - 2]))
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }
    if (dotCount > 2)
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }

    //operation check
    if (operation[0] == '+')
    {
        addCount++;
    }
    if (addCount > 1)
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }
    if(operation[0]=='!' && stringNum2[0]!='1')
    {
        std::cout << "Incorrect data (error code: BadFormat)";
        return (ErrorCode::BadFormat);
    }

    return ErrorCode::OK;
}
ErrorCode DivideBy0Check(const char &oper, const double &num2)
{
    if (oper == '/' && num2 == 0)
    {
        std::cout << "Incorrect data (error code: DivideBy0)";
        return ErrorCode::DivideBy0;
    }
    else
        return ErrorCode::OK;
}

ErrorCode SqrtOfNegativeNumberCheck(const double &num1, const char &oper, const double &num2)
{
    if ((num1 < 0 && oper == '$') || (num1 < 0 && oper == '^' && (num2 < 1 && num2 > 0)))
    {
        std::cout << "Incorrect data (error code: SqrtOfNegativeNumber)";
        return ErrorCode::SqrtOfNegativeNumber;
    }
    else
        return ErrorCode::OK;
}

ErrorCode ModuleOfNonIntegerValue(const double &num1, const double &oper, const double &num2)
{
    if (oper == '%' && !(std::floor(num1) == num1 && std::floor(num2) == num2))
    {
        std::cout << "Incorrect data (error code: ModuleOfNonIntegerValue)";
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    return ErrorCode::OK;
}

double doMath(const double & num1, const char & oper, const double & num2)
{
    std::map<char, std::function<double(double, double)>> mathOperations{
    {'+', [](const double &num1, const double &num2)
     { return num1 + num2; }},
    {'-', [](const double &num1, const double &num2)
     { return num1 - num2; }},
    {'*', [](const double &num1, const double &num2)
     { return num1 * num2; }},
    {'/', [](const double &num1, const double &num2)
     { return num1 / num2; }},
    {'%', [](const double &num1, const double &num2)
     { return fmod(num1, num2); }},
    {'!', [](const double &num1, const double &num2) mutable
     {
         if (num1 >= 0)
         {
             return tgamma(num1 + 1);
         }
         return -tgamma(-num1 + 1);
     }},
    {'^', [](const double &num1, const double &num2)
     { return pow(num1, num2); }},
    {'$', [](const double &num1, const double &num2)
     { return pow(num1, (1 / num2)); }}};

    return mathOperations[oper](num1, num2);
}
