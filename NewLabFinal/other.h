#pragma once

#include <limits>
#include <iostream>

const size_t IGNORE_SIZE = std::numeric_limits<std::streamsize>::max();

bool isSiteURLValid(const std::string& siteURL);
