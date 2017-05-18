#ifndef TURRET_H
#define TURRET_H

#include <functional>
#include "Cell.h"
#include "Enemy.h"

class Turret : public Cell
{
public:
		int range;
		int damage;
		int delay;
		int current_delay;
		Turret();
		Turret(Cell_type cell_type, sf::RectangleShape* shape, int range);
		std::function<Enemy*(std::list<Enemy*>)> find_target;
};

#endif //TURRET_H
