#ifndef SFML_TUT_BULLET_H
#define SFML_TUT_BULLET_H

#include "Enemy.h"

class Bullet : public Movable {
private:
		Enemy* enemy;
		float power;
		float speed;
		void move_shape_to_target();
public:
		sf::Shape* get_shape() override;
		sf::Shape* shape;
		void move() override;
		~Bullet();
		Bullet(sf::Shape* shape, Enemy* enemy, float power, float speed);
};

#endif //SFML_TUT_BULLET_H
