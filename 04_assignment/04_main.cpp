#include"espresso_machine.h"
#include<iostream>

int main() {
    jl::reservoir e_reservoir(48);
    jl::boiler e_boiler(12, 94);
    jl::brew_group e_brew_group(36);
    jl::espresso_machine e_machine(e_reservoir, e_boiler, e_brew_group);

    std::cout << "Output espresso_machine to cout...\n";
    std::cout << e_machine;
    std::cout << "\nCopy espresso_machine using copy constructor...\n";
    jl::espresso_machine e_machine_copy(e_machine);
    std::cout << "\nOutput espresso_machine COPY to cout...\n";
    std::cout << e_machine_copy;
    std::cout << "\nInvoke composite class function pour_shot()...\n";
    e_machine.pour_shot();
    std::cout << "\nOutput espresso_machine after pour_shot() function call...\n";
    std::cout << e_machine;
    return 0;
}

