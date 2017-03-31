#if !defined(JL_BOILER_HEADER_INCLUDED)
#define JL_BOILER_HEADER_INCLUDED
#pragma once

#include<iostream>
#include<iomanip>
#include<Windows.h>

namespace jl {
    class boiler {
    private:
        double max_capacity;
        double water_level;
        double brewing_temp;
        double current_temp;
    public:
        boiler(double init_max_capacity, double init_brewing_temp) :
            max_capacity(init_max_capacity),
            water_level(0),
            brewing_temp(init_brewing_temp),
            current_temp(0)
        { std::cout << "BOILER constructed...\n"; }
        boiler(const boiler& copy_boiler) :
            max_capacity(copy_boiler.max_capacity),
            water_level(copy_boiler.water_level),
            brewing_temp(copy_boiler.brewing_temp),
            current_temp(copy_boiler.current_temp)
        { std::cout << "BOILER COPY constructed...\n"; }
        inline double get_max_capacity() const { return max_capacity; };
        inline double get_water_level() const { return water_level; };
        inline double get_brewing_temp() const { return brewing_temp; };
        inline double get_current_temp() const { return current_temp; };
        inline void output(std::ostream&) const;
        inline void heat_fluid();
        inline void cool_fluid() { current_temp = 0; };
        inline double dispense_fluid(double);
        inline double fill(double);
    };

    inline void boiler::output(std::ostream& s) const {
        s << "Boiler Maximum Capacity:  " << max_capacity << " fluid ounces...\n";
        s << "Boiler Water Level:       " << water_level << " fluid ounces...\n";
        s << "Boiler Brewing Temperture:  " << brewing_temp << " degrees celsius...\n";
        s << "Boiler Current Temperture:  " << current_temp << " degrees celsius...\n";
    }
    inline void boiler::heat_fluid() {
        std::cout << "BOILER is HEATING to " << brewing_temp << " degrees celsius...\n";
        std::cout << std::setprecision(2);
        while(current_temp < brewing_temp) {
            Sleep(100);
            current_temp += 1;
            if(static_cast<int>(current_temp) % 25 == 0) {
                std::cout << "temperature is " << current_temp << " degrees celsius...\n";
            }
        }
        std::cout << "temperature has reached " << current_temp << " degrees celsius...\n";
    }
    inline double boiler::dispense_fluid(double fl_oz) {
        if(fl_oz > water_level)
            fl_oz = water_level;
        water_level -= fl_oz;
        std::cout << "BOILER is DISPENSING " << fl_oz << " fluid ounces...\n";
        return fl_oz;
    }
    inline double boiler::fill(double fl_oz) {
        if(fl_oz > (max_capacity - water_level))
            fl_oz = max_capacity - water_level;
        water_level += fl_oz;
        std::cout << "BOILER is REFILLING " << fl_oz << " fluid ounces...\n";
        return fl_oz;
    }



}


#endif