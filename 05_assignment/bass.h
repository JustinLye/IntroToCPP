#if !defined(_JL_BASS_HEADER_INCLUDED_)
#define _JL_BASS_HEADER_INCLUDED_
#pragma once

#include"string_instrument.h"
#include<iostream>

namespace jl {
    class bass : public string_instrument {
    public:
        bass() { std::cout << "BASS constructed...\n"; }
        ~bass() { std::cout << "BASS destructed...\n"; }
        inline void play() { std::cout << "Soothing mellow sounds of BASS playing...\n"; }
        inline void pluck(const jl::instrument& i) { std::cout << "Bump of BASS string being plucked\n"; }
        inline void output(std::ostream& s) const { s << "BASS"; }
    };
}

#endif