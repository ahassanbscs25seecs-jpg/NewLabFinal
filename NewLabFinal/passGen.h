#pragma once

#include <string>

enum class CharClasses : int {
	SPECIAL = 0,
	UPPER,
	LOWER,
	DIGITS,
};

const int MAX_PASSWORD_LEN = 20;

long int genSeed(const std::string& randStr);
std::string genNewPassword(int len, bool charTypes[4], bool hasRepetition);
