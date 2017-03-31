#if !defined(JL_RNWY_SPCS_HEADER_INCLUDED)
#define JL_RNWY_SPCS_HEADER_INCLUDED
#pragma once

namespace jl {

//Runway Surfaces
//source: en.wikipedia.org/wiki/Runway Surface type codes
enum rw_srfc {
    ASP, //Asphalt
    CLA, //Clay
    CON, //Concrete
    COP, //Composite
    COR, //Coral
    GRE, //Graded or rolled earth, grass on graded earth
    GRS, //Grass or earth not graded or rolled
    GVL, //Gravel
    ICE, //Ice
    LAT, //Laterite
    MAC, //Macadam
    PEM, //Partially concrete
    PER, //Permanent surface
    PSP, //Marsden Matting (derived from pierced/perforated steel planking)
    SAN, //Sand
    SMT, //Sommerfeld Tracking
    SNO, //Snow
    U //Unknown surface
}; //runway surfaces

//Runway Number
enum rw_num { 
  RW_01 = 1, //Heading 10 degrees North East
  RW_02, //Heading 20 degrees (North East)
  RW_03, //Heading 30 degrees (North East)
  RW_04, //Heading 40 degrees (North East)
  RW_05, //Heading 50 degrees (North East)
  RW_06, //Heading 60 degrees (North East)
  RW_07, //Heading 70 degrees (North East)
  RW_08, //Heading 80 degrees (North East)
  RW_09, //Heading 90 degrees (East)
  RW_10, //Heading 100 degrees (South East)
  RW_11, //Heading 100 degrees (South East)
  RW_12, //Heading 120 degrees (South East)
  RW_13, //Heading 130 degrees (South East)
  RW_14, //Heading 140 degrees (South East)
  RW_15, //Heading 150 degrees (South East)
  RW_16, //Heading 160 degrees (South East)
  RW_17, //Heading 170 degrees (South East)
  RW_18, //Heading 180 degrees (South)
  RW_19, //Heading 190 degrees (South West)
  RW_20, //Heading 200 degrees (South West)
  RW_21, //Heading 210 degrees (South West)
  RW_22, //Heading 220 degrees (South West)
  RW_23, //Heading 230 degrees (South West)
  RW_24, //Heading 240 degrees (South West)
  RW_25, //Heading 250 degrees (South West)
  RW_26, //Heading 260 degrees (South West)
  RW_27, //Heading 270 degrees (West)
  RW_28, //Heading 280 degrees (North West)
  RW_29, //Heading 290 degrees (North West)
  RW_30, //Heading 300 degrees (North West)
  RW_31, //Heading 310 degrees (North West)
  RW_32, //Heading 320 degrees (North West)
  RW_33, //Heading 330 degrees (North West)
  RW_34, //Heading 340 degrees (North West)
  RW_35, //Heading 350 degrees (North West)
  RW_36  //Heading 360 degrees (North)
};

//Current Weather
enum weather_sts {
  FAIR, //Fair weather conditions(high visibility)
  RAIN, //Current percipitation(low)
  SLEET,//Current percipitation(Sleeting)
  SNOWING, //Current percipitation(Snowing)
  SNOW, //Sufaces covered with snow no percipitation
  WET, //Sufaces are wet, but no percipitation(overcast & medium visibility)
  FOG //Low visiblity
};

inline std::ostream& operator<<(std::ostream& s, const weather_sts w) {
    s << "Current weather is ";
    switch(w)
    {
    case FAIR:
        s << "FAIR\n";
        break;
    case RAIN:
        s << "RAIN\n";
        break;
    case SLEET:
        s << "SLEET\n";
        break;
    case SNOWING:
        s << "SNOWING\n";
        break;
    case SNOW:
        s << "SNOW\n";
        break;
    case WET:
        s << "WET\n";
        break;
    case FOG:
        s << "FOG\n";
        break;
    }
    return s;
}

inline std::ostream& operator<<(std::ostream& s, const rw_num r) {
    rw_num n1 = r;
    rw_num n2 = (r <= RW_18) ? rw_num(r + 18) : rw_num(r - 18);
    s << "\nRunway\t" << (int)n1 << '/' << (int)n2 << '\n';
    return s;
}

inline std::ostream& operator<<(std::ostream& s, const rw_srfc& r) {
    s << "\nSurface\t";
	switch (r)
	{
	case jl::ASP:
		s << "Asphalt";
		break;
	case jl::CLA:
		s << "Clay";
		break;
	case jl::CON:
		s << "Concrete";
		break;
	case jl::COR:
		s << "Coral";
		break;
	case jl::GRE:
		s << "Graded or rolled earth";
		break;
	case jl::GRS:
		s << "Grass or earth not graded or rolled";
		break;
	case jl::GVL:
		s << "Gravel";
		break;
	case jl::ICE:	
		s << "Ice";
		break;
	case jl::LAT:
		s << "Laterite";
		break;
	case jl::MAC:
		s << "Macadam";
		break;
	case jl::PEM:
		s << "Partially concrete";
		break;
	case jl::PER:
		s << "Permanent surface";
		break;
	case jl::PSP:
		s << "Marsden Matting";
		break;
	case jl::SAN:
		s << "Sand";
		break;
	case jl::SMT:
		s << "Sommerfeld Tracking";
		break;
	case jl::SNO:
		s << "Snow";
		break;
	case jl::U:
	default:
        s << "Unknown surface";
		break;
	}
    s << '\n';
    return s;
}

}

#endif