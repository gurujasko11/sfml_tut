#ifndef SFML_TUT_BULLET_H
#define SFML_TUT_BULLET_H

#include "Enemy.h"

class ObjectStorage;

class Bullet : public Movable {
private:
		Enemy* enemy;
		float power;
		float speed;
		void move_shape_to_target();
public:
		ObjectStorage* objectStorage;
		sf::Shape* get_shape() override;
		sf::Shape* shape;
		bool move() override;
		~Bullet();
		Bullet(sf::Shape* shape, Enemy* enemy, ObjectStorage* objectStorage, float power, float speed);
};

#endif //SFML_TUT_BULLET_H
