#if !defined(_JL_CELLO_HEADER_INCLUDED_)
#define _JL_CELLO_HEADER_INCLUDED_
#pragma once

#include"string_instrument.h"
#include<iostream>

namespace jl {
    class cello : public string_instrument {
    public:
        cello() { std::cout << "CELLO constructed...\n"; }
        ~cello() { std::cout << "CELLO destructed...\n"; }
        inline void play() { std::cout << "Low pitch sounds of a CELLO playing...\n"; }
        inline void pluck(const jl::instrument& i) { std::cout << "Thung of CELLO string being plucked...\n"; }
        inline void output(std::ostream& s) const { s << "CELLO"; }
    };
}

#endif