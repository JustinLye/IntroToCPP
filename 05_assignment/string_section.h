#if !defined(_JL_STRING_SECTION_HEADER_INCLUDED_)
#define _JL_STRING_SECTION_HEADER_INCLUDED_

#pragma once

#include"instrument.h"
#include"section.h"
#include"string_instrument.h"
#include"bass.h"
#include"cello.h"
#include"violin.h"
#include<iostream>

namespace jl {
    class string_section : public section {
    public:
        string_section() { std::cout << "STRING_SECTION constructed...\n"; }
        ~string_section() { 
			for (int i = 0; i < instrument_count; i++) {
				delete instruments[i];
			}
			std::cout << "STRING_SECTION destructed...\n";
		}
        inline void output(std::ostream& s) const { s << "STRING SECTION"; }
    };
}

#endif