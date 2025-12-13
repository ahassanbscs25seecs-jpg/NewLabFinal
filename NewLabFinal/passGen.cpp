#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

#include "passGen.h"

const char SPECIAL[] = "!@#$%^&*?/";
const char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char LOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char DIGITS[] = "0123456789";

/* Combine the characters in the random string into a number to be used as the random seed*/
long int genSeed(const std::string& randStr) {
	std::srand((unsigned int)std::time(nullptr));
	long int seed = std::rand();

	for (int i = 0; i < randStr.length(); i++) {
		seed |= randStr[i];
		seed <<= 2;
		seed *= 3;
	}

	return seed;
}

/* Generate a new password given the options we passed in */
std::string genNewPassword(int len, bool charTypes[4], bool hasRepetition) {
	std::string pass;

	// Build allowed character sets + guarantee each type
	std::vector<const char*> allowedSets;
	std::vector<int> allowedSizes;

	/* If we want digits */
	if (charTypes[(int)CharClasses::DIGITS]) {
		allowedSets.push_back(DIGITS);
		allowedSizes.push_back(sizeof(DIGITS) - 1);
	}

	/* If we want special */
	if (charTypes[(int)CharClasses::SPECIAL]) {
		allowedSets.push_back(SPECIAL);
		allowedSizes.push_back(sizeof(SPECIAL) - 1);
	}

	/* If we want uppercase letters */
	if (charTypes[(int)CharClasses::UPPER]) {
		allowedSets.push_back(UPPER);
		allowedSizes.push_back(26);
	}

	/* If we want lowercase letters */
	if (charTypes[(int)CharClasses::LOWER]) {
		allowedSets.push_back(LOWER);
		allowedSizes.push_back(26);
	}

	// First: ensure at least one from each selected type
	for (size_t i = 0; i < allowedSets.size(); i++) {
		const char* set = allowedSets[i];
		int size = allowedSizes[i];
		pass.push_back(set[std::rand() % size]);
	}

	/* Fill the rest of the password */
	if (hasRepetition) {
		/* Fill with repetition allowed. */
		while (pass.length() < len) {
			int index = std::rand() % allowedSets.size();
			const char* set = allowedSets[index];
			int size = allowedSizes[index];

			pass.push_back(set[std::rand() % size]);
		}
	} else {
		/* Fill without repetition. */
		bool isUsed[128] = { false };

		while (pass.size() < len) {
			char c;

			/* Find an unused character */
			while (true) {
				int i = std::rand() % allowedSets.size();
				const char* charSet = allowedSets[i];
				int size = allowedSizes[i];

				c = charSet[std::rand() % size];
				if (!isUsed[c]) {
					break;
				}
			}

			isUsed[c] = true;
			pass.push_back(c);
		}
	}

	return pass;
}
