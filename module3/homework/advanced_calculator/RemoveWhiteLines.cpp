#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <algorithm>

std::string removeSpaces(std::string);

int main() {

  std::fstream TestCases;
  TestCases.open("regexTests.txt");
  std::ofstream TestCasesWithoutSpaces;
  TestCasesWithoutSpaces.open("regexTestsWithoutSpaces.txt");

  std::string line;
  if (TestCases.is_open()) {
    while (getline(TestCases, line)) {
      std::cout << line << '\n';
      std::string lineWithoutSpaces = removeSpaces(line);
      std::cout << lineWithoutSpaces << '\n';
      TestCasesWithoutSpaces << lineWithoutSpaces << '\n';
        
    }
    TestCases.close();
  }
  TestCases.close();
  return 0;

  return 0;
}

std::string removeSpaces(std::string line) {
  line.erase(remove_if(line.begin(), line.end(), isspace),
                    line.end());
    return line;
}