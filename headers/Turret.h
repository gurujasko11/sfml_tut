#ifndef TURRET_H
#define TURRET_H

#include <functional>
#include <chrono>
#include "Cell.h"
#include "Enemy.h"
#include "GlobalVariables.h"

class Game;

class Turret : public Cell, public Movable
{
public:

		Game* game;
		int range;
		int damage;

		std::chrono::milliseconds time_beetwen_shot = std::chrono::milliseconds(100000)/fps;
		std::chrono::time_point<std::chrono::system_clock> time_of_last_shot = std::chrono::system_clock::now() - time_beetwen_shot;

		Turret();
		Turret(Cell_type cell_type, sf::RectangleShape& shape, int range);
		std::list<Enemy*> find_enemies_in_range();
		std::function<Enemy*()> find_target;
		void shoot();
		bool can_shoot();
		void move() override;
		sf::Shape* get_shape() override;
		~Turret();
};

#endif //TURRET_H
