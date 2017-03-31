#include"player.h"
#include<string>

int main(){
	jl::player p("player one",100,10);
	std::cout << "name:\t\t" << p.get_name << '\n'
		      << "hitpoints:\t" << p.get_hitpoints << '\n'
			  << "attack damage:\t" << p.get_attack_damage << '\n';
	
	return 0;
}