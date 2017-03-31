#include<iostream>
#include"player.h"

int main() {
	jl::player p1("Player1",100,10);
	jl::player p2("Player2",100,10);
	std::cout << p1 << p2;
	p1.set_attack_damage(15);
	p1.set_hitpoints(200);
	p1.set_name("Player 1 (name change)");
	p2.set_attack_damage(45);
	p2.set_hitpoints(50);
	p2.set_name("Player 2 (name change)");
	std::cout << p1 << p2;
	return 0;
}