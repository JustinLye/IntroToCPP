#if !defined(JL_ESPRESSO_MACHINE_HEADER_INCLUDED)
#define JL_ESPRESSO_MACHINE_HEADER_INCLUDED
#pragma once
#include"reservoir.h"
#include"boiler.h"
#include"brew_group.h"
#include<iostream>

namespace jl {
    class espresso_machine {
    private:
        reservoir m_reservoir;
        boiler m_boiler;
        brew_group m_brew_group;
    public:
        espresso_machine(const reservoir& init_reservoir,const boiler& init_boiler,const brew_group& init_brew_group) :
            m_reservoir(init_reservoir),
            m_boiler(init_boiler),
            m_brew_group(init_brew_group)
        { std::cout << "ESPRESSO MACHINE constructed...\n"; }
        espresso_machine(const espresso_machine& copy_machine) :
            m_reservoir(copy_machine.m_reservoir),
            m_boiler(copy_machine.m_boiler),
            m_brew_group(copy_machine.m_brew_group)
        { std::cout << "ESPRESSO MACHINE COPY constructed...\n"; }
        inline void pour_shot();
        friend inline std::ostream& operator<<(std::ostream&, const espresso_machine&);
    };
    inline void espresso_machine::pour_shot() {
        if(!m_boiler.fill(m_reservoir.dispense_fluid(m_boiler.get_max_capacity())))
            if(!m_boiler.fill(m_reservoir.dispense_fluid(1.0))) {
                std::cout << "REFILL RESERVOIR...\n";
                return;
            }
        m_boiler.heat_fluid();
        if(!m_brew_group.fill_basket(8.0)) {
            std::cout << "REFILL BEAN HOPPER...\n";
            return;
        }
        m_brew_group.move_to_home_position();
        m_brew_group.move_to_work_position();
        m_boiler.dispense_fluid(1.0);
        std::cout << "ESPRESSO MACHINE is POURING shot through group head...\n";
        std::cout << "ESPRESSO SHOT is READY...\n";
        m_brew_group.move_to_home_position();
    }
    inline std::ostream& operator<<(std::ostream& s, const espresso_machine& mach) {
        mach.m_reservoir.output(s);
        mach.m_boiler.output(s);
        mach.m_brew_group.output(s);
        return s;
    }
}


#endif