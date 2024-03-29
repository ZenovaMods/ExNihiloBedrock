#include "StringUtils.h"

#include <iostream>
#include <sstream>

std::vector<std::string> StringUtils::split(const std::string& str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str); // Turn the string into a stream.
	std::string tok;

	while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}

	return internal;
}

std::string StringUtils::capitalize(const std::string& str) {
	std::string ret = str;
	ret.front() = toupper(ret.front());
	return ret;
}
