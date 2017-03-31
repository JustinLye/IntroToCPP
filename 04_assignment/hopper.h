#if !defined(JL_HOPPER_HEADER_INCLUDED)
#define JL_HOPPER_HEADER_INCLUDED
#pragma once
#include<iostream>

namespace jl {
    class hopper {
    private:
        double max_capacity;//Maximum volume in cubic grams
        double grounds_level;
    public:
        hopper(double init_capacity) :
            max_capacity(init_capacity),
            grounds_level(init_capacity)
        { std::cout << "HOPPER constructed...\n"; }
        hopper(const hopper& hopper_copy) :
            max_capacity(hopper_copy.max_capacity),
            grounds_level(hopper_copy.grounds_level)
        { std::cout << "HOPPER COPY constructed...\n"; }
        inline double get_max_capacity() const { return max_capacity; };
        inline double get_grounds_level() const { return grounds_level; };
        inline double dispense_grounds(double);
        inline void fill(double);
        inline void output(std::ostream&) const;
    };
    inline double hopper::dispense_grounds(double grams) {
        if(grams > grounds_level)
            grams = grounds_level;
        grounds_level -= grams;
        std::cout << "HOPPER is GRINDING...\n" << "HOPPER DISPENSING " << grams << " grams of coffee grounds...\n";
        return grams;
    }
    inline void hopper::fill(double grams) {
        if(grams > (max_capacity - grounds_level))
            grams = max_capacity - grounds_level;
        grounds_level += grams;
        std::cout << "HOPPER is REFILLING " << grams << " grams of coffee grounds...\n";
    }
    inline void hopper::output(std::ostream& s) const {
        s << "Hopper Maximum Capacity:  " << max_capacity << " grams...\n";
        s << "Hopper Current Grounds Level:  " << grounds_level << " grams...\n";
    }
}
#endif