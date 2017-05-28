#include <iostream>
#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/FinderCatalog.h"
#include "../headers/Bullet.h"
#include "../headers/Game.h"

Turret::Turret()
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
}

Turret::Turret(Cell_type cell_type, sf::RectangleShape& shape, int range)
				: Cell(cell_type, shape),
				  range(range)
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
}

bool Turret::can_shoot() {
	if(time_of_last_shot + time_beetwen_shot < std::chrono::system_clock::now()) {
		return true;
	}
	return false;
};

void Turret::shoot () {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/bull1.png");
	sf::CircleShape* bullet_shape = new sf::CircleShape(8);
	bullet_shape -> setTexture(texture);
	bullet_shape -> setPosition(shape.getPosition());
	game -> add_bullet(new Bullet(bullet_shape,find_target(), 25, 5));
	time_of_last_shot = std::chrono::system_clock::now();
}

std::list<Enemy*> Turret::find_enemies_in_range() {
	std::list<Enemy*> result;
	for(std::list<Enemy*>::iterator i=game->enemies.begin(); i != game->enemies.end();i++) {
		if((*i)->get_distance_from(&shape) < range)
			result.push_back(*i);
	}
	return result;
}

void Turret::move() {
	if(can_shoot() && find_target() != NULL) {
		shoot();
	}
}

sf::Shape* Turret::get_shape(){
	return &shape;
}

Turret::~Turret () {
	//TODO
}

