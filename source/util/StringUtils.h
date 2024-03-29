#pragma once

#include <vector>
#include <string>

class StringUtils {
public:
	static std::vector<std::string> split(const std::string&, char);
	static std::string capitalize(const std::string&);
};