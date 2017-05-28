#include <iostream>
#include "../headers/Bullet.h"
#include "../headers/GlobalVariables.h"
void Bullet::move() {
	if(enemy == NULL)
		return;
	move_shape_to_target();
//	if(enemy->get_distance_from(shape) < 1)
//		return true;TODO
//	return false;
}

void Bullet::move_shape_to_target()
{
	sf::Vector2<float> shift;
	shift.x = (enemy->shape)->getPosition().x - shape->getPosition().x;
	shift.y = (enemy->shape)->getPosition().y - shape->getPosition().y;

	if(abs(shift.x) < 1 && abs(shift.y) < 1)
	{
		shape->setPosition((enemy->shape)->getPosition());
		return;
	}

	float x = (speed * speed) / ((shift.x * shift.x) + (shift.y * shift.y));
	x = sqrt(x);
	shape->move(x*shift.x,x*shift.y);
}

Bullet::Bullet(sf::Shape* shape, Enemy* enemy, float power = 25, float speed = 5) :
				shape(shape),
				enemy(enemy),
				power(power),
				speed(speed) {};

Bullet::~Bullet() {
//	game->remove_bullet(this);//TODO
}

sf::Shape* Bullet::get_shape() {
	return shape;
}
