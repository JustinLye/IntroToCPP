#if !defined(JL_AIRPORT_HEADER_INCLUDED)
#define JL_AIRPORT_HEADER_INCLUDED
#pragma once

#include<iostream>
#include"airplane.h"
#include"airport_specs.h"
#include"control_tower.h"
#include"runway.h"
#include"terminal.h"

//I would like to add a procedure for a plane to request landing or takeoff
//This will be the "TurnKey()" event
//It should take a plane as the argument
//The first check will be to see if the runway is active
//If the landing request is non emergency the check if weather conditions allow
//for landing/takeoff
//If the landing request is emergency landing put emergency crews on standby
//The second check will be to see if the dimensions of the runway are capable of
//handling the request.
//The third step will be to assign a gate for the plane to park

//categorize aircraft into 3 wieght classes
//1. 12.5 K or less -- we'll say the runway has to be @ least 4.0 K ft
//2. 12.5 K to 60.0 K -- we'll say the runway has to be @ least 10.5 K ft
//2. 60.0 K or more -- we'll say the runway has to be @ least 13.5 K ft

namespace jl {


//Airport only supports one runway
class airport {
private:
    weather_sts curr_weather_sts;
    bool military_airport;
    bool us_airport;
    runway rwy;
public:
    airport( runway r, weather_sts cwsts, bool us_ap, bool mil_ap = false ) : 
      rwy(r), curr_weather_sts(cwsts), us_airport(us_ap), military_airport(mil_ap)
      { std::cout << "airport constructed\n"; } //airport constructor
    inline void output(std::ostream& s) const {
        s << curr_weather_sts;
        s << rwy;
    }
    friend std::ostream& operator<<(std::ostream&, const airport&);
};

    inline std::ostream& operator<<(std::ostream& s, const airport& a) {
        a.output(s);
        return s;
    }
}

#endif