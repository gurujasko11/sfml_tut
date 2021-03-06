#ifndef TURRET_H
#define TURRET_H

#include <functional>
#include <chrono>
#include "Cell.h"
#include "Enemy.h"
#include "GlobalVariables.h"

class Level;

class Turret : public Cell, public Movable
{
public:

		enum find_function_type{
				FARTHEST,
				NEAREST,
				STRONGEST,
				WEAKEST
		} find_target_type;
		Level* level;
		int range;
		int lvl;
		int damage;
		Color color;

		std::chrono::milliseconds time_beetwen_shot = std::chrono::milliseconds(100000)/fps;
		std::chrono::time_point<std::chrono::system_clock> time_of_last_shot;

		Turret();
		Turret(Cell_type cell_type, sf::RectangleShape* shape, int range, int damage,Color color = Color::NONE, int lvl=1);
		std::list<Enemy*> find_enemies_in_range();
		std::function<Enemy*()> find_target;
		double get_fixed_range();
		double get_fixed_damage();
		std::chrono::milliseconds get_fixed_time();
		double get_lvl_factor();
		int get_lvl_factor_int();
		void shoot();
		bool can_shoot();
		void move() override;
		sf::Shape* get_shape() override;
		~Turret();
};

#endif //TURRET_H
