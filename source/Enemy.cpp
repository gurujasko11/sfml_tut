#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Enemy.h"
#include "../headers/Background.h"

void Enemy::next_target() {
	index++;
	if(index == targets.end()) {
		index = targets.begin();
		this->shape->setPosition(targets.front()->getPosition());
	}
}

Enemy::Enemy (sf::Shape* shape, float& speed, int hp = 100)
				: shape(shape),
				  speed(speed),
					hp(hp){
	index = targets.begin();
}

void Enemy::move()
{
	sf::Vector2<float> shift;
	shift.x = (*index)->getPosition().x - shape->getPosition().x;
	shift.y = (*index)->getPosition().y - shape->getPosition().y;

	if(abs(shift.x) < 1 && abs(shift.y) < 1)
	{
		next_target();
		return;
	}

	float x = (speed * speed) / ((shift.x * shift.x) + (shift.y * shift.y));
	x = sqrt(x);
	shape->move(x*shift.x,x*shift.y);
}

//bool Enemy::is_on_target ()
//{
//	sf::Shape* next_target = *index;
//	if(next_target->getPosition().x == shape->getPosition().x && next_target->getPosition().y == shape->getPosition().y)
//	{
//		return true;
//	}
//	return false;
//}

float Enemy::get_distance_from(sf::Shape* shape)
{
	return sqrt(
					  (shape->getPosition().x-this->shape->getPosition().x) *
						(shape->getPosition().x-this->shape->getPosition().x)
	        + (shape->getPosition().y-this->shape->getPosition().y) *
					  (shape->getPosition().y-this->shape->getPosition().y)
	);
}

float Enemy::getSpeed () const {
	return speed;
}

int Enemy::getHp () const {
	return hp;
}

sf::Shape* Enemy::get_shape(){
	return shape;
}

Enemy::~Enemy() {

}
