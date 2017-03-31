#include "trim.h"

namespace generic {

std::string trim_right(const std::string& s) {
	std::string::size_type e = s.find_last_not_of(" \t\n\r\f");
	return std::string(s, 0, e == std::string::npos ? 0 : e + 1);
}

std::string trim_left(const std::string& s) {
	std::string::size_type b = s.find_first_not_of(" \t\n\r\f");
	return std::string(s, b == std::string::npos ? 0 : b, std::string::npos);
}

std::string trim(const std::string& s) {
	const char* ws = " \t\n\r\f";
	std::string::size_type e = s.find_last_not_of(ws);
	std::string::size_type b = s.find_first_not_of(ws);
	if (b == std::string::npos) { b = 0; }
	return std::string(s, b, e == std::string::npos ? 0 : e - b + 1);
}

}

