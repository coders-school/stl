#pragma once

#include <stdexcept>

struct BadFormatException : public std::invalid_argument{
	BadFormatException() : std::invalid_argument("BadFormat Exception"){};
};

struct BadCharacterException : public std::invalid_argument{
	BadCharacterException() : std::invalid_argument("BadCharacter Exception"){};
};