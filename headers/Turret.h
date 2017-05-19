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
		Turret();
		Turret(Cell_type cell_type, sf::RectangleShape& shape, int range);
		std::list<Enemy*> find_enemies_in_range();
		std::function<Enemy*()> find_target;

};

#endif //TURRET_H
