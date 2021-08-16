#include "InsensitivePalindrom.h"

#include <algorithm>

std::string prepareString(std::string text) {
	std::for_each(text.begin(), text.end(), [](char& c) { c = std::tolower(c);	});
    text.erase(std::remove_if(text.begin(), text.end(), [](const char& c) { return !std::isalpha(c); } ), text.end());
	return text;
}

bool is_palindrome(const std::string& text) {
	auto data = prepareString(text);
	auto begin = data.begin();
	auto end = data.end() - 1;

	while (begin < end) {
		if (*begin != *end) {
			return false;
		}
		++begin;
		--end;
	}
	return true;
}
