#pragma once

#if !defined(__generic_trim_h__)
#define __generic_trim_h__

#include <string>

namespace generic {

std::string trim_right(const std::string& s);
std::string trim_left(const std::string& s);
std::string trim(const std::string& s);

}

#endif
