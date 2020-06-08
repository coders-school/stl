#include <algorithm>
#include <iterator>
#include <map>
#include <math.h>
#include <regex>
#include <vector>

double factorial(double num) {
  return num > 1.0 ? num * factorial(num - 1) : 1.0;
}

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNagativeNumber,
    ModuleOfNonIntegerValue
};

const std::map<ErrorCode, std::string> error_output {
  {ErrorCode::BadCharacter, "Bad Character, Please provide only number and operator"},
  {ErrorCode::BadFormat, "Bad Format, Please provide format: number operator number"},
  {ErrorCode::DivideBy0, "Can't divide by 0!"},
  {ErrorCode::SqrtOfNagativeNumber, "Can't calculate sqrt of nagative number"},
  {ErrorCode::ModuleOfNonIntegerValue, "Can't calculate module on non integer value"}
};

std::map<char, std::function<double(double, double)>> operators {
  {'+', [](double lhs, double rhs){ return lhs + rhs; }},
  {'-', [](double lhs, double rhs){ return lhs - rhs; }},
  {'*', [](double lhs, double rhs){ return lhs * rhs; }},
  {'/', [](double lhs, double rhs){ return lhs / rhs; }},
  {'%', [](double lhs, double rhs){ return (int)lhs % (int)rhs; }},
  {'!', [](double lhs, double rhs){ return factorial(lhs); }},
  {'^', [](double lhs, double rhs){ return std::pow(lhs, rhs); }},
  {'$', [](double lhs, double rhs){ return std::pow(lhs, -rhs); }}
};

ErrorCode validate(double num1, double num2, char op) {
  switch (op) {
    case '/':
      return num2 == 0 ? ErrorCode::DivideBy0 : ErrorCode::OK;
    case '%':
      double tmp;
      if (modf(num1, &tmp) == 0.0 && modf(num2, &tmp) == 0.0)
        return ErrorCode::OK;
      return ErrorCode::ModuleOfNonIntegerValue;
    case '$':
      return num1 < 0 ? ErrorCode::SqrtOfNagativeNumber : ErrorCode::OK;
    case '+':
    case '-':
    case '!':
    case '*':
    case '^':
      return ErrorCode::OK;
  }
  return ErrorCode::BadCharacter;
}

ErrorCode extract(const std::string& input, std::vector<std::string>* output) {
    output->clear();
    std::string str;
    std::remove_copy_if(begin(input), end(input), std::back_inserter(str), ::isspace);

    // ((optioanl) - | digit | (optioanl) . | (digit)) | (every character exclude !) | (The same like at the begining.)
    const std::regex pattern("(-?[0-9]+\\.?[0-9]*)([^!]{1})(-?[0-9]+\\.?[0-9]*)");
    const std::regex pattern2("(-?[0-9]+\\.?[0-9]*)!");
    std::smatch match;
    if (std::regex_match(str, match, pattern)) {
        // The first match is the whole string; the next
        // match is the first parenthesized expression.
        if (match.size() == 4) {
          output->push_back(match[1]);
          output->push_back(match[2]);
          output->push_back(match[3]);
          return ErrorCode::OK;
        }
    } else if (std::regex_match(str, match, pattern2)) {
        if (match.size() == 2) {
          output->push_back(match[1]);
          output->push_back("!");
          return ErrorCode::OK;
        }
    }
    return ErrorCode::BadFormat;
}

ErrorCode process(std::string input, double* out) {
  std::vector<std::string> split_str;
  if (auto ec = extract(input, &split_str) ; ec != ErrorCode::OK) {
    return ec;
  }

  double first_num = std::stod(split_str[0]);
  char op = split_str[1][0];
  double second_num {};
  if (op != '!') {
    second_num = std::stod(split_str[2]);
  }
  if (auto ec = validate(first_num, second_num, op) ; ec != ErrorCode::OK) {
    return ec;
  }

  *out = operators[op](first_num, second_num);
  return ErrorCode::OK;
}
