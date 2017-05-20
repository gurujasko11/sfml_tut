#ifndef SFML_TUT_BULLET_H
#define SFML_TUT_BULLET_H

#include "Enemy.h"

class Bullet {
private:
		Enemy* enemy;
		float power;
		float speed;
		void move_shape_to_target();
public:
		sf::Shape* shape;
		bool execute();

		Bullet(sf::Shape* shape, Enemy* enemy, float power, float speed);
};

#endif //SFML_TUT_BULLET_H
