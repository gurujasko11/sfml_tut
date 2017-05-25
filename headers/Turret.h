#ifndef TURRET_H
#define TURRET_H

#include <functional>
#include <chrono>
#include "Cell.h"
#include "Enemy.h"

class ObjectStorage;

class Turret : public Cell, public Movable
{
public:
		ObjectStorage* objectStorage;
		int range;
		int damage;

		std::chrono::duration<int> time_beetwen_shot = std::chrono::duration<int>(1);
		std::chrono::time_point<std::chrono::system_clock> time_of_last_shot = std::chrono::system_clock::now() - time_beetwen_shot;

		Turret();
		Turret(Cell_type cell_type, sf::RectangleShape& shape, int range);
		std::list<Enemy*> find_enemies_in_range();
		std::function<Enemy*()> find_target;
		void shoot();
		bool can_shoot();
		bool move() override;
		sf::Shape* get_shape() override;
		~Turret();
};

#endif //TURRET_H
