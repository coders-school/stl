#include "palindrom.hpp"

bool is_high_letter(char a) {
    if (a >= 65 && a <= 90)
        return true;
    else
        return false;
}

bool is_low_letter(char a) {
    if (a >= 97 && a <= 122)
        return true;
    else
        return false;
}

bool isSame(char low, char high) {
    return high + 32 == low;
}

bool is_letter(char a) {
    return is_high_letter(a) || is_low_letter(a);
}

std::string::iterator setLastIterator(std::string::iterator it, std::string str) {
    if (is_letter(*it)) {
        return it;
    } else {
        if (it == str.begin()) {
            return it;
        } else {
            it--;
            return setLastIterator(it, str);
        }
    }
}

std::string::iterator setBeginIterator(std::string::iterator it, std::string str) {
    if (is_letter(*it)) {
        return it;
    } else {
        if (it == str.end()) {
            return it;
        } else {
            it++;
            return setBeginIterator(it, str);
        }
    }
}

bool is_equal(std::string::iterator it_a, std::string::iterator it_b) {
    auto a = *it_a;
    auto b = *it_b;
    if (a == b)
        return true;
    else {
        if (is_low_letter(a) && is_high_letter(b)) {
            return isSame(a, b);
        } else if (is_low_letter(b) && is_high_letter(a)) {
            return isSame(b, a);
        }
    }
    return false;
}

bool is_palindrome(std::string str) {
    auto it_begin = setBeginIterator(str.begin(), str);
    auto it_end = setLastIterator(str.end()--, str);

    while (it_begin <= it_end) {
        if (is_letter(*it_begin) && is_letter(*it_end)) {
            if (!is_equal(it_begin, it_end))
                return false;
            it_begin++;
            it_end--;
        } else if (!is_letter(*it_begin)) {
            it_begin++;
        } else if (!is_letter(*it_end)) {
            it_end--;
        } else {
            it_begin++;
            it_end--;
        }
    }

    return true;
}