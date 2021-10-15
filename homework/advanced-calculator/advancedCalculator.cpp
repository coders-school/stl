#include "advancedCalculator.hpp"
#include <regex>

std::map<char, std::function<double(double, double)>> mathematical_tasks = {

	{ '+', [](double a, double b) {return a + b; } },
	{ '-', [](double a, double b) {return a - b; } },
	{ '*', [](double a, double b) {return a * b; } },
	{ '/', [](double a, double b) {return a / b; } },
	{ '%', [](double a, double b) {return static_cast<int>(a) % static_cast<int>(b); } },
	{ '!', [](double a, double b) {return Factorial(a); }},
	{ '^', [](double a, double b) {return pow(a, b); } },
	{ '$', [](double a, double b) {return pow(a, 1.0 / b); } },
};


ErrorCode process(const std::string& input, double* out)
{

	ErrorCode error{};

	std::string result = RemoveNotNeccessertyCharacters(input);

	error = CheckBadCharacter(result);
	if (!error) { error = CheckModuleNonIntegerValue(result); }
	if (!error) { error = CheckNegativeNumber(result); }
	if (!error) { error = CheckBadFormat(result); }
	if (error != ErrorCode::OK)return error;

	auto parameters = getNumbers(result);

	if (!error) { error = CheckDivideBy0(parameters); }
	if (error != ErrorCode::OK)return error;

	double first_digit = 0;
	double second_digit = 0;
	char middle = '\0';

	if (!parameters[0].empty()) { first_digit = strtod(parameters[0].c_str(), nullptr); }
	if (!parameters[1].empty()) { middle = parameters[1][0]; }
	if (!parameters[2].empty()) { second_digit = strtod(parameters[2].c_str(), nullptr); }

	* out = mathematical_tasks.at(middle)(first_digit, second_digit);
	return error;
}

std::vector<std::string> getNumbers(std::string_view str)
{

	std::vector<std::string> out;
	std::vector<char> operators = { '+', '-', '*', '/', '%', '!', '^', '$' };
	if (str.empty()) { return out; }
	std::string first{};
	std::string last{};
	auto result = std::find_first_of(str.begin() + 1, str.end(), operators.begin(), operators.end());

	if (result != std::end(str)) {
		auto const index = std::distance(std::begin(str), result);
		std::for_each(str.begin(), str.begin() + index, [&first](auto x) {
			first.push_back(x);
			});

		out.push_back(first);
		std::string middle_operator{ str.at(index) };
		out.push_back(middle_operator);


		std::for_each(str.begin() + index + 1, str.end(), [&last](auto x) {
			last.push_back(x);
			});
		out.push_back(last);
	}

	return out;
}

ErrorCode CheckBadFormat(std::string_view str)
{
	std::vector<std::string> v{ "++", ",", "!+", "^%" };
	for (const auto& p : v) {
		auto result = std::find_end(str.begin(), str.end(), p.begin(), p.end());
		if (result != str.end()) {
			return ErrorCode::BadFormat;
		}
	}

	auto dots = std::count(str.begin(), str.end(), '.');
	if (dots > 2) {
		return ErrorCode::BadFormat;
	}

	if (!str.empty() && (*str.begin() == '+' || *(str.end() - 1) == '+')) {
		return ErrorCode::BadFormat;
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '!' && str.size() - 1 > i) {
			return ErrorCode::BadFormat;
		}
	}

	return ErrorCode::OK;
}

std::string RemoveNotNeccessertyCharacters(const std::string& str)
{
	auto result = std::regex_replace(str, std::regex("\\ "), "");
	result = std::regex_replace(result, std::regex("\\+-"), "-");
	result = std::regex_replace(result, std::regex("\\--"), "+");
	return result;
}


ErrorCode CheckBadCharacter(std::string_view str)
{
	if (str.empty()) {
		return ErrorCode::BadCharacter;
	}
	std::vector<char> valid_characters = { '+', '-', '*', '/', '%', '!', '^', '$', '.', ',' };

	auto it = std::find_if_not(std::begin(str), std::end(str), [&valid_characters](auto character) {

		for (const auto& c : valid_characters) {
			if (std::isdigit(character) || c == character) {
				return true;
			}
		}
		return false;
		});

	if (it != str.end()) {
		return ErrorCode::BadCharacter;
	}

	return ErrorCode::OK;
}


ErrorCode CheckModuleNonIntegerValue(std::string_view str)
{
	bool is_double = false;
	auto is_module = false;
	std::for_each(std::begin(str), std::end(str), [&](auto x) {
		if (x == '.') {
			is_double = true;
		}
		if (x == '%') {
			is_module = true;
		}
		});

	if (is_module && is_double) {
		return ErrorCode::ModuleOfNonIntegerValue;
	}
	return ErrorCode::OK;
}

ErrorCode CheckDivideBy0(std::vector<std::string> params)
{
	char division = params.at(1).at(0);
	double divider = 0;
	if (!params.at(2).empty()) {
		divider = std::stod(params.at(2), nullptr);
	}
	if (divider == 0 && division == '/') {
		return ErrorCode::DivideBy0;
	}
	return ErrorCode::OK;
}



ErrorCode CheckFactorial(std::vector<std::string> params)
{
	char factorial = params.at(1).at(0);
	double first_number = 0;

    if (!params.at(2).empty()) {
		first_number = std::stod(params.at(0), nullptr);
	}
	if (first_number == 0 && factorial != '!') {
		return ErrorCode::DivideBy0;
	}
	return ErrorCode::OK;
}

double Factorial(double n)
{
	return n > 0 ? std::tgamma(n + 1) : std::tgamma(-n + 1) * -1;
}

ErrorCode CheckNegativeNumber(std::string_view str)
{
	auto it = std::find(begin(str), end(str), '$');
	if (it != end(str) && str.at(0) == '-') {

		return ErrorCode::SqrtOfNegativeNumber;
	}
	return ErrorCode::OK;
}
