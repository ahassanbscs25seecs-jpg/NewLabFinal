#pragma once

#include <limits>
#include <iostream>

/* The maximum amount of characters we ignore (discard) in input. */
const size_t IGNORE_SIZE = std::numeric_limits<std::streamsize>::max();

/* Checks if the url contains any whitespace characters--spaces, tabs, newline, carriage returns.*/
bool isSiteURLValid(const std::string& siteURL);
