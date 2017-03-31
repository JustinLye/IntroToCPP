#if !defined(JL_RUNWAY_HEADER_INCLUDED)
#define JL_RUNWAY_HEADER_INCLUDED
#pragma once

#include<iostream>
#include<string>
#include"rwy_dims.h"
#include"airport_specs.h"

namespace jl {

enum rw_type { VISUAL, NON_PRECISION, PRECISION };

class runway {
private:
    // subtract degrees if the runway is < 18
    // add 18 degrees if the runway is >= 18
    rw_type type;
    rw_srfc surface; //Surface material of runway
    bool active; //Takeoff or Landing currently in progress
    rw_num name;
    rwy_dims dimensions;
public:
    runway(rw_num n, rw_type t, rw_srfc s,rwy_dims rd) : 
      name(n), type(t), surface(s), dimensions(rd), active(false) {
        std::cout << "runway constructed\n";
      }
    void output(std::ostream& ) const;
    friend std::ostream& operator<<(std::ostream&, const runway&);
};
    inline void runway::output(std::ostream& s ) const {
        s << name; 
        s << surface;
        s << dimensions;
    }
    inline std::ostream& operator<<(std::ostream& s, const runway& r) {
        r.output(s);
        return s;
    }
}

#endif