#ifndef SFML_TUT_OBJECTSSTORAGE_H
#define SFML_TUT_OBJECTSSTORAGE_H

#include "Enemy.h"
#include "Bullet.h"

class Turret;

class ObjectStorage {
private:
		std::list<Enemy*> enemies;
		std::list<Turret*> turrets;
		std::list<Bullet*> bullets;
public:
		void add_enemy(Enemy* enemy);
		void add_turrets(Turret* turret);
		void add_bullet(Bullet* bullet);
		void remove_bullet(Bullet* bullet);

		std::list<Enemy*>::iterator get_enemies_begin();
		std::list<Enemy*>::iterator get_enemies_end();

		std::list<Turret*>::iterator get_turrets_begin();
		std::list<Turret*>::iterator get_turrets_end();

		std::list<Bullet*>::iterator get_bullets_begin();
		std::list<Bullet*>::iterator get_bullets_end();

		std::list<Enemy*> get_enemy_in_range(sf::Shape* shape, float range);
};
#endif //SFML_TUT_OBJECTSSTORAGE_H
