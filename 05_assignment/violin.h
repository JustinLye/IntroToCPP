#if !defined(_JL_VIOLIN_HEADER_INCLUDED_)
#define _JL_VIOLIN_HEADER_INCLUDED_

#pragma once
#include"string_instrument.h"
#include<iostream>

namespace jl {
    class violin : public string_instrument {
    public:
        violin() { std::cout << "VOILIN constructed...\n"; }
        ~violin() { std::cout << "VOILIN destructed...\n"; }
        inline void play() { std::cout << "High pitch sounds of a VIOLIN playing...\n"; }
        inline void pluck(const jl::instrument& i) { std::cout << "Pinging sound of VIOLIN being plucked...\n"; }
        inline void output(std::ostream& s) const { s << "VIOLIN"; }
    };
}


#endif