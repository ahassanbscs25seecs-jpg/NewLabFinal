#include "strengthChecking.h"

#include <iostream>
#include <string>
#include <set>
#include <cmath>

bool hasEasyPattern(const std::string& password) {
	std::string lower = password;

	for (char& c : lower)
		c = std::tolower(c);

	return lower.find("1234") != std::string::npos ||
		lower.find("abcd") != std::string::npos ||
		lower.find("qwerty") != std::string::npos ||
		lower.find("password") != std::string::npos ||
		lower.find("admin") != std::string::npos ||
		lower.find("1122") != std::string::npos ||
		lower.find("asdf") != std::string::npos ||
		lower.find("zxcv") != std::string::npos;

	return false;
}
bool hasRepetition(const std::string& password) {
	for (int i = 0; i < password.size() - 2; i++) {
		if (password[i] == password[i + 1] && password[i] == password[i + 2]) {
			return true;
		}
	}
	return false;
}

double calculateEntropy(const std::string& password) {
	double entropy = 0.00;
	int characterSetSize = 0;
	int len = (int)password.length();
	std::set<char> uniqueChars;
	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

	for (char ch : password) {
		unsigned char uch = static_cast<unsigned char>(ch);
		uniqueChars.insert(uch);

		if (isupper(uch))
			hasUpper = true;
		else if (islower(uch))
			hasLower = true;
		else if (isdigit(uch))
			hasDigit = true;
		else if (ispunct(uch))
			hasSpecial = true;
	}

	if (hasUpper)
		characterSetSize += 26;

	if (hasLower)
		characterSetSize += 26;

	if (hasDigit)
		characterSetSize += 10;

	if (hasSpecial)
		characterSetSize += 32;


	if (characterSetSize == 0)
		entropy = 0;
	else
		entropy = len * std::log2(characterSetSize);

	return entropy;
}

int calculateStrengthScore(const std::string& password) {
	int points = 0;
	std::set<char> uniqueChars;
	int len = (int)password.length();
	double entropy = calculateEntropy(password);

	// Entropy points 
	if (entropy <= 20)
		points += 5;
	else if (entropy <= 40)
		points += 15;
	else if (entropy <= 60)
		points += 25;
	else if (entropy <= 75)
		points += 40;
	else
		points += 50;

	// Character and Length points 
	bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
	for (char ch : password) {
		unsigned char uch = static_cast<unsigned char>(ch);
		uniqueChars.insert(uch);

		if (isupper(uch))  hasUpper = true;
		else if (islower(uch))  hasLower = true;
		else if (isdigit(uch))  hasDigit = true;
		else if (ispunct(uch))  hasSpecial = true;
	}
	if (hasUpper) points += 5;
	if (hasLower) points += 5;
	if (hasDigit) points += 5;
	if (hasSpecial) points += 10;

	if (len >= 12) points += 10;
	else if (len >= 10) points += 8;


	//UNique char bonus
	int unique_count = (int)uniqueChars.size();
	if (unique_count <= 4)
		points += 0;
	else if (unique_count <= 7)
		points += 5;
	else if (unique_count <= 10)
		points += 12;
	else if (unique_count <= 15)
		points += 15;
	else
		points += 30;

	//pattern penalty
	if (hasEasyPattern(password)) points -= 10;

	//Repeated char penality
	if (hasRepetition(password)) points -= 10;


	if (points > 100) points = 100;
	if (points < 0) points = 0;

	return points;
}

std::string strengthLabel(int points) {
	std::string label = "";

	if (points < 30) {
		label = "Weak";
	}
	else if (points < 60) {
		label = "Medium";
	}
	else if (points < 80) {
		label = "Strong";
	}
	else {
		label = "Very Strong";
	}

	return label;
}

std::string getPasswordInput() {
	std::string password;

	std::cout << "Enter your password (spaces allowed)" << std::endl;

	do {
		std::cout << "> ";
		std::getline(std::cin, password); // Accept spaces

		if (password.length() == 0) {
			std::cout << "Password cannot be empty!" << std::endl;
		}
	} while (password.length() == 0);

	return password;
}
