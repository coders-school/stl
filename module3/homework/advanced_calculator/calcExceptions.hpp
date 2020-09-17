#pragma once


#include "errorCodes.hpp"
#include <stdexcept>


struct CalcException : public std::invalid_argument{
	CalcException(std::string message, ErrorCode code) 
		: std::invalid_argument(message)
		, errorCode(code){};

	ErrorCode errorCode; 
};


struct BadFormatException : public CalcException{
	BadFormatException() : CalcException("BadFormat Exception" , 
										 ErrorCode::BadFormat){};
};

struct BadCharacterException : public CalcException{
	BadCharacterException() : CalcException("BadCharacter Exception",
											ErrorCode::BadCharacter){};
};

struct DivideBy0Exception : public CalcException{
	DivideBy0Exception() : CalcException("DivideBy0 Exception", 
										 ErrorCode::DivideBy0){};
};

struct SqrtOfNegativeNumberException : public CalcException{
	SqrtOfNegativeNumberException() : CalcException("SqrtOfNegativeNumber Exception",
													 ErrorCode::SqrtOfNegativeNumber){};
};

struct ModuleOfNonIntegerValueException : public CalcException{
	ModuleOfNonIntegerValueException() : CalcException("ModuleOfNonIntegerValue Exception",
													    ErrorCode::ModuleOfNonIntegerValue){};
};
