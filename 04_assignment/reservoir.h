#if !defined(JL_RESERVOIR_HEADER_INCLUDED)
#define JL_RESERVOIR_HEADER_INCLUDED
#pragma once

#include<iostream>

namespace jl {
    class reservoir {
    private:
        double max_capacity; //maximum fluid ounces reservoir can hold
        double water_level; //total fluid ounces held in reservoir
    public:
        reservoir(double init_capacity) :
            max_capacity(init_capacity),
            water_level(init_capacity)
        { std::cout << "RESERVOIR constructed...\n"; }
        reservoir(const reservoir& copy_reservoir) :
            max_capacity(copy_reservoir.max_capacity),
            water_level(copy_reservoir.water_level)
        { std::cout << "RESERVOIR COPY constructed...\n"; }
        inline double get_max_capacity() const { return max_capacity; };
        inline double get_water_level() const { return water_level; };
        inline double dispense_fluid(double);
        inline void output(std::ostream&) const;
    };
    inline double reservoir::dispense_fluid(double fl_oz) {
        if(fl_oz > water_level)
            fl_oz = water_level;
        water_level -= fl_oz;
        std::cout << "RESERVOIR is DISPENSING " << fl_oz << " fluid ounces...\n";
        return fl_oz;
    }
    inline void reservoir::output(std::ostream& s) const {
        s << "Reservoir Maximum Capacity:  " << max_capacity << " fluid ounces...\n";
        s << "Reservoir Water Level:       " << water_level << " fluid ounces...\n";
    }
}


#endif