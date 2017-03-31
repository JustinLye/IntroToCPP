#include<iostream>
#include<string>
namespace jl {
	class player {
	private:
		std::string name;
		int hitpoints;
		int attack_damage;

	public:
	//constructors
		player () = delete;
		player (const std::string& n, int h, int ad) :
			name (n),
			hitpoints (h),
			attack_damage (ad)
        { }
		explicit player(const player& p) :
			name (p.name),
			hitpoints (p.hitpoints),
			attack_damage (p.attack_damage)
		{ }
	//accessors
		std::string get_name () const;
		int get_hitpoints () const;
		int get_attack_damage () const;
		void set_name (const std::string&);
		void set_hitpoints (int);
		void set_attack_damage(int);
	//operators
		friend std::ostream& operator<<(std::ostream&, const player&);
	};
    //accessor definitions
	inline std::string player::get_name() const { return name; }
	inline int player::get_hitpoints() const { return hitpoints; }
	inline int player::get_attack_damage() const { return attack_damage; }
	inline void player::set_name(const std::string& n) { name = n; }
	inline void player::set_hitpoints(int h) { hitpoints = h; }
	inline void player::set_attack_damage(int ad) { attack_damage = ad; }
	inline std::ostream& operator<<(std::ostream& s, const player& p) { 
		return s << "Name:\t\t" << p.name << '\n'
                 << "Hitpoints:\t" << p.hitpoints << '\n'
				 << "Attack Damage:\t" << p.attack_damage << '\n';
	}
}