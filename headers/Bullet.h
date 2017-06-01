#ifndef SFML_TUT_BULLET_H
#define SFML_TUT_BULLET_H

#include "Enemy.h"
#include "Color.h"

class Bullet : public Movable {
private:
		float speed;
		Color color;
		void move_shape_to_target();

        bool more_damaged();
        bool less_damaged();
public:
		float power;
		Enemy* enemy;
		sf::Shape* get_shape() override;
		sf::Shape* shape;
		void move() override;
        void hit();
		~Bullet();
		Bullet(sf::Shape* shape, Enemy* enemy, float power, float speed, Color color = Color::NONE);
};

#endif //SFML_TUT_BULLET_H
