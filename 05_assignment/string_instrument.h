#if !defined(_JL_STRING_INSTRUMENT_HEADER_INCLUDED_)
#define _JL_STRING_INSTRUMENT_HEADER_INCLUDED_

#pragma once
#include"instrument.h"
#include<iostream>

namespace jl {
    class string_instrument : public instrument {
    private:
    public:
		string_instrument() { std::cout << "STRING_INSTRUMENT constructed...\n"; }
        virtual void play() = 0;
        virtual void output(std::ostream&) const = 0;
        virtual void pluck(const jl::instrument&) = 0;
    };
}

#endif