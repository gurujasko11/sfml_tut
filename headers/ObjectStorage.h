#ifndef SFML_TUT_OBJECTSSTORAGE_H
#define SFML_TUT_OBJECTSSTORAGE_H

#include "Enemy.h"
#include "Bullet.h"

class Turret;
class Game;

class ObjectStorage {
private:
		std::list<Enemy*> enemies;
		std::list<Turret*> turrets;
		Game* game;
public:
		void add_enemy(Enemy* enemy);
		void add_turrets(Turret* turret);
		void add_bullet(Bullet* bullet);
		void remove_bullet(Bullet* bullet);

		std::list<Enemy*>::iterator get_enemies_begin();
		std::list<Enemy*>::iterator get_enemies_end();

		ObjectStorage(Game* game);

		std::list<Bullet*> bullets;
};
#endif //SFML_TUT_OBJECTSSTORAGE_H
