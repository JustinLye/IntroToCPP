#include"string_section.h"
#include<iostream>


int main() {
    char z = 'z';
    jl::string_section ss;
    jl::violin* v = new jl::violin;
    jl::cello* c = new jl::cello;
    jl::bass* b = new jl::bass;
    ss.add_instrument(v);
    ss.add_instrument(c);
    ss.add_instrument(b);
    ss.cue();
    std::cin >> z;
    return 0;
}