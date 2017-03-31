#if !defined(JL_TERMINAL_HEADER_INDCLUDED)
#define JL_TERMINAL_HEADER_INCLUDED

#pragma once

#include<iostream>

namespace jl {

class terminal {
private:
    int total_gates;
    int resturants;
    int concourses;
public:
    terminal(int g, int r, int c) : total_gates(g), resturants(r), concourses(c) { std::cout << "terminal constructed\n"; }
    void output(std::ostream& s) const;
    friend std::ostream& operator<<(std::ostream& s, const terminal& t);
};
    inline void terminal::output(std::ostream& s) const {
        s << "Terminal contains the following:\n";
        s << '\t' << total_gates << " gates\n";
        s << '\t' << resturants << " resturants\n";
        s << '\t' << concourses << " concourses\n";
    }

    inline std::ostream& operator<<(std::ostream& s, const terminal& r) {
        r.output(s);
        return s;
    }
}

#endif