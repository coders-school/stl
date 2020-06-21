#include <string>
#include <algorithm>

bool is_palindrome(std::string sentence) {
	sentence.erase(std::remove_if(sentence.begin(), sentence.end(),
		[](char letter) { return !isalpha(letter); }),
		sentence.end());

	std::transform(sentence.begin(), sentence.end(), sentence.begin(), tolower);

	return std::equal(sentence.cbegin(), sentence.cbegin() + sentence.size() / 2, sentence.crbegin());
}

int main() {
    return 0;
}
