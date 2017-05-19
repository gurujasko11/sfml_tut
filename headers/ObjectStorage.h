#ifndef SFML_TUT_OBJECTSSTORAGE_H
#define SFML_TUT_OBJECTSSTORAGE_H

#include "Enemy.h"
#include "Turret.h"

class Turret;

class ObjectStorage {
private:
		std::list<Enemy*> enemies;
		std::list<Turret*> turrets;
public:
		void add_enemy(Enemy* enemy);
		void add_turrets(Turret* turret);

		std::list<Enemy*>::iterator get_enemies_begin();
		std::list<Enemy*>::iterator get_enemies_end();

		std::list<Turret*>::iterator get_turrets_begin();
		std::list<Turret*>::iterator get_turrets_end();

		std::list<Enemy*> get_enemy_in_range(sf::Shape* shape, float range);
};
#endif //SFML_TUT_OBJECTSSTORAGE_H
