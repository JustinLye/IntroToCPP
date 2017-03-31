#if !defined(JL_BREW_GROUP_HEADER_INCLUDED)
#define JL_BREW_GROUP_HEADER_INCLUDED
#pragma once

#include"hopper.h"
#include<iostream>

namespace jl {
    enum brew_grp_pos {
        HOME,
        WORK
    };
    class brew_group {
    private:
        hopper brew_grp_hopper;
        brew_grp_pos current_position;
        double basket_max_capacity;
        double basket_grounds_level;
    public:
        brew_group(double init_hopper_capacity) :
            brew_grp_hopper(init_hopper_capacity),
            current_position(jl::HOME),
            basket_max_capacity(8.0),
            basket_grounds_level(0.0)
        { std::cout << "BREW GROUP constructed...\n"; }
        brew_group(const brew_group& brew_group_copy ) :
            brew_grp_hopper(brew_group_copy.brew_grp_hopper),
            current_position(brew_group_copy.current_position),
            basket_max_capacity(brew_group_copy.basket_max_capacity),
            basket_grounds_level(brew_group_copy.basket_grounds_level)
        { std::cout << "BREW GROUP COPY constructed...\n"; }
        inline double get_basket_max_capacity() const { return basket_max_capacity; };
        inline double get_basket_grounds_level() const { return basket_grounds_level; };
        inline void output(std::ostream&) const;
        inline void move_to_home_position();
        inline void move_to_work_position();
        inline double fill_basket(double);
    };
    inline void brew_group::output(std::ostream& s) const {
        brew_grp_hopper.output(s);
        s << "Brew Group Current Position:  ";
        if(current_position == jl::HOME)
            s << "HOME...\n";
        else
            s << "WORK...\n";
        s << "Brew Group Maximum Basket Capacity:  " << basket_max_capacity << " grams...\n";
        s << "Brew Group Current Basket Grounds Level:  " << basket_grounds_level << " grams...\n";
    }
    inline void brew_group::move_to_home_position() {
        if(current_position != jl::HOME) {
            if(basket_grounds_level != 0) {
                basket_grounds_level = 0;
                std::cout << "BREW GROUP is DISPOSING of basket grounds into drop box...\n";
            }
            std::cout << "BREW GROUP is MOVING to HOME position...\n";
            current_position = jl::HOME;
        }
        std::cout << "BREW GROUP is in HOME position...\n";
    }
    inline void brew_group::move_to_work_position() {
        if(current_position != jl::WORK) {
            std::cout << "BREW GROUP is MOVING to WORK position...\n";
            std::cout << "BREW GROUP is TAMPING...\n";
            current_position = jl::WORK;
        }
        std::cout << "BREW GROUP is in WORK position...\n";
    }
    inline double brew_group::fill_basket(double grams) {
        if(grams > (basket_max_capacity - basket_grounds_level))
            grams = basket_max_capacity - basket_grounds_level;
        return brew_grp_hopper.dispense_grounds(grams);
    }




}


#endif