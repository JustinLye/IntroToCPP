#if !defined(JL_RWY_DIMS_HEADER_INCLUDED)
#define JL_RWY_DIMS_HEADER_INCLUDED
#pragma once

#include<iostream>

namespace jl {
class rwy_dims {
private:
    int tora; // takeoff run available
    int width; // width of the runway    
    int lda; // landing distance available    
    int cwy; // clearway [optional]
    int swy; // stopway [optional]
    int tord; // takeoff distance available (tora + cwy) [calculated]
    int asda; // Accelerate-Stop Distance Available (tora + swy) [calculated]
    int emda; // emergency landing distance available (lda + swy) [calculated]
public:
    rwy_dims(int t, int w, int l, int c = 0, int s = 0) : 
      tora(t), width(w), lda(l), cwy(c), swy(s), tord(t + c),
      asda(t + s), emda(l + s)
      { std::cout << "rwy_dims constructed\n"; }
    inline void output(std::ostream& s ) const {
        s << "\nDimensions\n\n";
        s << "  TORA:\t\t" << tora << "ft\n";
        s << "  Width:\t" << width << "ft\n";
        s << "  LDA:\t\t" << lda << "ft\n";
        s << "  CWY:\t\t" << cwy << "ft\n";
        s << "  SWY:\t\t" << swy << "ft\n";
        s << "  TORD:\t\t" << tord << "ft\n";
        s << "  ASDA:\t\t" << asda << "ft\n";
        s << "  EMDA:\t\t" << emda << "ft\n";
    }
    friend std::ostream& operator<<(std::ostream& s, const rwy_dims& d) {
        d.output(s);
        return s;
    }
};
}
#endif