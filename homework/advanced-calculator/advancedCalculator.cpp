#include "advancedCalculator.hpp"

Operations operation{
  {'+',std::plus<>{}},
  {'-',std::minus<>{}},
  {'*',std::multiplies<>{}},
  {'/',std::divides<>{}},
  {'%',[](auto lhs,auto rhs){
    return static_cast<int>(lhs) % static_cast<int>(rhs);}},
  {'^',[](auto lhs, auto rhs){return std::pow(lhs,rhs);}},
  {'$',[](auto lhs, auto rhs){return std::pow(lhs,1 / rhs);}},
  {'!',[](auto lhs, [[maybe_unused]] auto) {
             return lhs >= 0 ? tgamma(lhs + 1)
                             : -tgamma(fabs(lhs) + 1);
         }}
};
std::vector<char> characters {' ','!','$','%','*','+',',','-','.','/','0',
                            '1','2','3','4','5','6','7','8','9','^'};

std::vector<char> oper {'!','$','%','*','+','-','/','^'};

bool isOperation(const unsigned char c){
    return std::binary_search(oper.begin(),oper.end(),c);
}

bool badCharTest(const std::string & st){
  std::set<char> s (st.begin(),st.end());
  if(!std::includes(characters.begin(),
                    characters.end(),
                    s.begin(),
                    s.end())){
    return true;
  } 
  return false;
}

bool badFormatTest(const std::string & s){
  //s is empty
  if(s.empty()){
    return true;
  }
  //comma exist
  if(std::any_of(s.begin(),s.end(),[](unsigned char c){return c == ',';})){
      return true;
  }
  //wrong first character, example: !1+2
  if(s.at(0) != '-' &&  !isdigit(s.at(0))) {
    return true;
  }

    //too many dots
  auto dot = std::find_if(s.begin(),s.end(),[](unsigned char c){return c =='.';});
  auto secondChar = std::find_if(std::next(dot),s.end(),[](unsigned char c){return ispunct(c);});
  if(*secondChar == '.'){
    return true;
  }
  //wrong second character +-1+2
  if((s.at(0) == '+' || s.at(0) == '-') &&  !isdigit(s.at(1))){
      return true;
  }
  //wrong character, example: 1.2
  if(std::none_of(std::next(s.begin()),s.end(),isOperation)){
    return true;
  }
  
  //double operator, example:  1 +/ 2
//   char secondOper = *std::next(std::find_if(std::next(s.begin()), s.end(), isOperation));
//   if(secondOper != '-' && !isdigit(secondOper)){
//     return true;
//   }
  auto op = std::find_if(std::next(s.begin()),s.end(), isOperation);
  char secondOp {};
  if(*op != '!'){
    secondOp = *std::next(op);
    std::cout << "double operator, example:  1 +/ 2\n";
    if(secondOp != '-' && !isdigit(secondOp)){
      return true;
    }
  }
  
  //too many arguments
 
  if(std::count_if(std::next(s.begin()),s.end(),isOperation) > 1 && secondOp != '-'){
    std::cout << "too many arguments\n";
    return true;
  }
  // if(std::ispunct(*std::next(std::find_if(std::next(s.begin()), s.end(), isOperation)))){
  //   return true;
  // }
  
  //wrong format with factorial, example: 1!2
  if(std::any_of(s.begin(),s.end(),[](char c){return c == '!';}) && std::isdigit(s.back())){
    return true;
  }
  //wrong last character, example 1+
  if(std::ispunct(s.back()) && s.back() != '!'){
    return true;
  }
  return false;
}

std::string parsingInput(std::string & s){
  auto dSpaces = [](std::string r, const char c){
    return std::isspace(c) ? r : r += c;
  };
  return std::accumulate(s.begin(),s.end(),std::string{},dSpaces);
}

mathExpresion extracting(const std::string & s){
  std::unique_ptr<mathExpresion> mE = std::make_unique<mathExpresion>();
  
  std::string numS = ""; 
    
  for(int i = 0; i < s.size(); i++){
    if(i == 0){
      numS += s.at(i);
      continue;
    } 
    while((i != s.size() && !isOperation(s.at(i))) || isOperation(s.at(i-1))){
      numS += s.at(i);
      i++;
    }
    mE->secondArg = std::stod(numS);
    numS.clear();
    
    if(i < s.size() && isOperation(s.at(i))){
      mE->firstArg = mE->secondArg;
      mE->oper = s[i];
    }
  }
  return *mE;
}

ErrorCode process(std::string input, double* out){
  input = parsingInput(input);

  if(badCharTest(input)){
    return ErrorCode::BadCharacter;
  }
  if(badFormatTest(input)){
    return ErrorCode::BadFormat;
  }
  
  mathExpresion mE = extracting(input);
  
  if(mE.oper == '/' && mE.secondArg == 0){
    return ErrorCode::DivideBy0;
  }
  if(mE.oper == '%' &&
    ((mE.firstArg != static_cast<int>(mE.firstArg)) ||
    mE.secondArg != static_cast<int>(mE.secondArg))){
    return ErrorCode::ModuleOfNonIntegerValue;
  }
  
  if(mE.oper == '$' && mE.firstArg < 0){
    return ErrorCode::SqrtOfNegativeNumber;
  }

  auto ex = operation[mE.oper];
  *out = ex(mE.firstArg,mE.secondArg);
  
  return ErrorCode::OK;
}

bool requestForQuit(std::string & s){
  s = parsingInput(s);
  std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
  if(s == "quit"){
    return false;
  }
  return true;
}
