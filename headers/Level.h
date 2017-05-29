#ifndef SFML_TUT_LEVEL_H
#define SFML_TUT_LEVEL_H

#include <set>
#include "Bullet.h"
#include "PushStrategy.h"

class Level {
public:
		std::list<Bullet*> bullets;
		std::list<Enemy*> enemies;
		std::set<Enemy*> enemies_to_delete;
		PushStrategy* pushStrategy;
		sf::RenderWindow* window;

		Level();
		void add_enemy(Enemy* enemy);
		void add_bullet(Bullet* bullet);


		void move_bullets();
		void move_enemies();

		void draw_bullets();
		void draw_enemies();

		void clean_enemies();
};
#endif //SFML_TUT_LEVEL_H
