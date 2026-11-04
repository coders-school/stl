#include <algorithm>

bool isItLetter(char c)
{
	if (int(c) >= 97 && int(c) <= 122)
		return true;

	return false;
}

bool is_palindrome(std::string& input)
{
	std::for_each(begin(input), end(input), [](char& c) {c = std::tolower(c);});
	std::remove_if(begin(input), end(input), [](char& c) {if (!isItLetter(c)) return true;});


	for (int i = 0, j = input.size() - 1; i++, j--; i < j)
	{
		if (input[i] != input[j])
			return false;
		return true;
	}
	return true;
}
