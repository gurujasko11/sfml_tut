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

Bullet::Bullet(sf::Shape* shape, Enemy* enemy, float power = 100, float speed = 5, Color color) :
				shape(shape),
				enemy(enemy),
				power(power),
				speed(speed),
				color(color)
{};

Bullet::~Bullet() {
//	game->remove_bullet(this);//TODO
}

sf::Shape* Bullet::get_shape() {
	return shape;
}

void Bullet::hit(){
        int damage = this->power;
		int damage = more_damaged() ? damage*2 : less_damaged() ? damage/2 : damage;
		enemy->hit_by_bullet(damage);
}

bool Bullet::more_damaged(){
    return enemy->color != Color::NONE && this->color == enemy->color;
}

bool Bullet::less_damaged(){
    if(this->color == Color::RED && enemy->color == Color::GREEN)
        return true;
    if(this->color == Color::GREEN && enemy->color == Color::BLUE)
        return true;
    if(this->color == Color::BLUE && enemy->color == Color::RED)
        return true;
    return false;
}

