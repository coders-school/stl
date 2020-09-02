#include "IOFunctions.hpp"
#include <iostream>
#include <algorithm>

std::string readInput() {
  std::string inputString;
  std::getline(std::cin, inputString);
  return inputString;
}

bool askIfWantToExit() {
  std::cout << "Do you want to continue? (Y/N)" << std::endl;
  char letter = readFirstCharacter();
  if(letter == 'y' || letter == 'Y'){
    return true;
  }
  else if(letter == 'n' || letter == 'N'){
    return false;
  }
  else return askIfWantToExit();
}

char readFirstCharacter(){
  std::string inputString;
  std::getline(std::cin, inputString);
  char firstLetter = *inputString.begin();
  return firstLetter;
}