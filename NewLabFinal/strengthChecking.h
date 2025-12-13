#pragma once

#include <iostream>
#include <string>
#include <set>

/* Checks if the given password has an easy pattern or not. */
bool hasEasyPattern(const std::string& password);

/* Checks if the given password has repetition. */
bool hasRepetition(const std::string& password);

/* Calculuates the entropy of the given code--i.e., the amount of variation. */
double calculateEntropy(const std::string& password);

/* Calculates the strength score of the given code. */
int calculateStrengthScore(const std::string& password);

/* Retrieves a strength label for the given strength score */
std::string strengthLabel(int points);

/* Retrieves the password from the user and returns it as a std::string */
std::string getPasswordInput();
