#include <string>

#include "other.h"

bool isSiteURLValid(const std::string& siteURL) {
	for (auto& c : siteURL) {
		if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
			return false;
		}
	}
	return true;
}
