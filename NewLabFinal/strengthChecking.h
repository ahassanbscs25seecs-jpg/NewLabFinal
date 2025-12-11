#pragma once

#include <iostream>
#include <string>
#include <set>

/*
 * hasEasyPattern: checks if the given password has an easy pattern or not.
 */
bool hasEasyPattern(const std::string& password);

/*
 * hasRepetition: Checks if the given password has repetition.
 */
bool hasRepetition(const std::string& password);

/*
 * calculateEntropy: Calculuates the entropy of the given code--i.e., the amount of variation.
 */
double calculateEntropy(const std::string& password);

/*
 * calculateStrengthScore: Calculates the strength score of the given code.
 */
int calculateStrengthScore(const std::string& password);

/*
 * strengthLabel: retrieves a strength label for the given strength score
 */
std::string strengthLabel(int points);

/*
 */
std::string getPasswordInput();
