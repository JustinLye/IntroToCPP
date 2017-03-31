#if !defined(_JL_SECTION_HEADER_INCLUDED_)
#define _JL_SECTION_HEADER_INCLUDED_
#pragma once
#include"instrument.h"
#include<iostream>

namespace jl {
    class section {
    protected:
        static const int MAX_INSTRUMENTS = 100;
        int instrument_count = 0;
        jl::instrument* instruments[MAX_INSTRUMENTS];
    public:
		section() { std::cout << "SECTION constructed...\n"; }
        virtual void output(std::ostream&) const = 0;
        inline void cue() {
			std::cout << "Conductor is cueing the " << *this << "...\n";
            for(int i = 0; i < instrument_count; i++)
                instruments[i]->play();
        }
        inline bool add_instrument(jl::instrument* init_instr) {
            bool success = false;
            if(instrument_count < MAX_INSTRUMENTS) {
                instruments[instrument_count++] = init_instr;
                std::cout << *init_instr << " added to " << *this << '\n';
                success = true;
            }
            return success;
        }
        friend inline std::ostream& operator<<(std::ostream& s, const jl::section& sc) {
            sc.output(s);
            return s;
        }
    };
}
#endif