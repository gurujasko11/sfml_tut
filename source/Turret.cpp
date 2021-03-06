#include <iostream>
#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/FinderCatalog.h"
#include "../headers/Bullet.h"
#include "../headers/Level.h"

Turret::Turret()
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
	color = Color::NONE;
	find_target_type = find_function_type::NEAREST;
}

Turret::Turret(Cell_type cell_type, sf::RectangleShape* shape, int range, int damage, Color color,int lvl)
				: Cell(cell_type, shape),
				  range(range),
				  damage(damage),
				  color(color),
				  lvl(lvl)
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
	find_target_type = find_function_type::NEAREST;
}

bool Turret::can_shoot() {
//	std::cout<<get_fixed_time().count()<<std::endl;
	if(time_of_last_shot + get_fixed_time() < std::chrono::system_clock::now()) {
		return true;
	}
	return false;
};

void Turret::shoot () {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/bull1.png");
	sf::CircleShape* bullet_shape = new sf::CircleShape(8);
	bullet_shape -> setTexture(texture);
	bullet_shape -> setPosition(shape->getPosition());
	level -> add_bullet(new Bullet(bullet_shape,find_target(), get_fixed_damage(), 5, this->color));
	time_of_last_shot = std::chrono::system_clock::now();
}

std::list<Enemy*> Turret::find_enemies_in_range() {
	std::list<Enemy*> result;
	for(std::list<Enemy*>::iterator i=level->enemies.begin(); i != level->enemies.end();i++) {
//	std::cout<<"w find enemies in range"<<std::endl;
		if((*i)->get_distance_from(shape) < get_fixed_range())
			result.push_back(*i);
	}
	return result;
}

double Turret::get_fixed_range() {
	return range*get_lvl_factor();
}
double Turret::get_fixed_damage() {
	return damage*get_lvl_factor();
}
std::chrono::milliseconds Turret::get_fixed_time() {
	return std::chrono::milliseconds(100000/(fps*get_lvl_factor_int()));
}

int Turret::get_lvl_factor_int() {
	return ((2*lvl+7)/9);
}

double Turret::get_lvl_factor() {
	return (double)((2*lvl+7)/9);
}
void Turret::move() {
	if(can_shoot() && find_target() != NULL) {
		shoot();
	}
}

sf::Shape* Turret::get_shape(){
	return shape;
}

Turret::~Turret () {
	//TODO tylko co?
}

