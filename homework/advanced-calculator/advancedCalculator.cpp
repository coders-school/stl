#include "advancedCalculator.hpp"

std::map<char, std::function<double(double a, double b)>> Wrapper{
    {'+', [](auto lhs, auto rhs){return lhs + rhs;}},
    {'-', [](auto lhs, auto rhs){return lhs - rhs;}},
    {'*', [](auto lhs, auto rhs){return lhs * rhs;}},
    {'/', [](auto lhs, auto rhs){return lhs / rhs;}},
    {'%', [](auto lhs, auto rhs){return static_cast<int>(lhs) % static_cast<int>(rhs);}},
    {'!', [](auto lhs, auto rhs){return (lhs < 0 ? std::tgamma(-lhs+ 1) * (-1) : std::tgamma(lhs + 1));}},
    {'^', [](auto lhs, auto rhs){return pow(lhs,rhs);}},
    {'$', [](auto lhs, auto rhs){return std::pow(lhs, 1.0 / rhs);}}
};

ErrorCode process(std::string input, double* out)
{
   
    char operation{};
    double a{},b{};

    size_t str_size = input.size();


    auto noSpace = std::remove(input.begin(), input.end(), ' ');
    input.erase(noSpace, input.end());
    
    auto c = input.find_first_of("+*/-%!^$", 1);


    if (input.find_first_of("#@&?\\[]=qwert;", 0) != std::string::npos) {
        return ErrorCode::BadCharacter;
    }

    if (input.find_first_of(",", 0) != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    if (input.find_first_of("+*/%!^$", c + 1) != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    if (!std::isdigit(input[0]) && input[0] != '-') {
        if (std::isalpha(input[0])) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    }

 

    // find doubled symbols in operation
    if (input.find_first_of("+*/%!^$", c + 1) != std::string::npos) {
        return ErrorCode::BadFormat;
    }

    // find doubled '.' in operation
    if (std::count(input.substr(0, c).begin(),
            input.substr(0, c).end(), '.')
            > 2
        || std::count(input.substr(c, str_size).begin(),
               input.substr(c, str_size).end(), '.')
            > 2) {
        return ErrorCode::BadFormat;
    }

    //    if (!std::isdigit(input[str_size - 1]) && input[str_size - 1] != '!') {
    //      std::cout<<"TUTAJ\n";
    //     return ErrorCode::BadFormat;
    //    }

    std::string A =  input.substr(0, c);
    std::string B = "";
    B = input.substr(c+1,input.size());
    
    operation = input[c];
    if(operation == '!' && B != "") 
    {
        return ErrorCode::BadFormat;
    }

  

    if(operation == '/') 
    {
         b = stod(B);
         if(b == 0.0) {
        return ErrorCode::DivideBy0;
         }
    }
    

    std::cout<<"input=" <<input<<".\n";
    std::cout<<"A=" <<A<<".\n";
    std::cout<<"B=" <<B<<".\n";
    std::cout<<"operation=" <<operation<<".\n";
    
    a = stod(A);

      if (operation == '$' && a < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if(B.size() > 0 )
    {
        b = stod(B);
    }
    
    double iptr{};
    // find module operation on non-integral value
    if (operation == '%' && (std::modf(a, &iptr) != 0 || std::modf(b, &iptr) != 0)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
   
    

   

    *out = Wrapper[operation](static_cast<double>(a), b);
    std::cout<<"\n"<<*out;
    
    return ErrorCode::OK;

}