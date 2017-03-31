#include<iostream>
#include<string>
#include "player.h"

int main() {

	jl::player p1("Player1",100,10);
	jl::player p2(p1);
	std::cout << "First player object:\n\n";

	std::cout << "Name:\t\t" << p1.get_name()
              << "\nHitpoints:\t" << p1.get_hitpoints()
              << "\nAttack Damage:\t" << p1.get_attack_damage() << '\n';

	std::cout << "\nSecond player object:\n\n";

	std::cout << "Name:\t\t" << p2.get_name()
              << "\nHitpoints:\t" << p2.get_hitpoints()
		      << "\nAttack Damage:\t" << p2.get_attack_damage() << '\n';
	return 0;
}
