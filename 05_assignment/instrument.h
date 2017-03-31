#if !defined(_JL_INSTRUMENT_HEADER_INCLUDED_)
#define _JL_INSTRUMENT_HEADER_INCLUDED_
#pragma once
#include<iostream>
namespace jl {

    class instrument {
    public:
		instrument() { std::cout << "INSTRUMENT constructed...\n"; }
        virtual void play() = 0;
        virtual void output(std::ostream&) const = 0;
        friend inline std::ostream& operator<<(std::ostream& s, const jl::instrument& si) {
            si.output(s);
            return s;
        }
    };
}



#endif