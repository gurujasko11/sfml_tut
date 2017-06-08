#include <cmath>
#include <SFML/Graphics.hpp>
#include "../headers/Enemy.h"
#include "../headers/Game.h"
#include "../headers/GlobalVariables.h"

void Enemy::next_target() {
	index++;
	if(index == targets.end()) {
		game_hp->getInstance()->hp--;
		index = targets.begin();
		this->shape->setPosition(targets.front()->getPosition());
		this->hp_shape->setPosition(targets.front()->getPosition());
	}
}

Enemy::Enemy (sf::Shape* shape, float& speed, int hp = 100, Color color)
				: shape(shape),
				  speed(speed),
                  hp(hp),
                  base_hp(hp),
                  color(color){
	index = targets.begin();
	hp_shape = new sf::RectangleShape(shape->getPosition());
	hp_shape->setFillColor(sf::Color::Yellow);
	hp_shape->setSize(sf::Vector2f(cell_size,4));
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
	hp_shape->setSize(sf::Vector2f(cell_size*(hp/base_hp),4));
	hp_shape->move(x*shift.x,x*shift.y);
}

void Enemy::hit_by_bullet(int damage) {
	hp -= damage;
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
