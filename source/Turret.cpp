#include <iostream>
#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/FinderCatalog.h"
#include "../headers/ObjectStorage.h"

//std::function<Enemy*()> Turret::default_finder = [this]() -> Enemy* {
//		Enemy* result = NULL;
//		std::list<Enemy*> enemies = this->find_enemies_in_range();
//		std::list<Enemy*>::iterator it = enemies.begin();
//		while(it != enemies.end())
//		{
//			if((*(it))->get_distance_from(&shape) < this->range)
//			{
//				if(result == NULL
//				   ||
//				   (*(it))->get_distance_from(&shape) < result->get_distance_from(&shape))
//				{
//					result = *it;
//				}
//			}
//			it++;
//		}
//		return result;
//};

std::list<Enemy*> Turret::find_enemies_in_range() {
	std::list<Enemy*> result;
	for(std::list<Enemy*>::iterator i=objectStorage->get_enemies_begin(); i!=objectStorage->get_enemies_end();i++) {
		if((*i)->get_distance_from(&shape) < range)
			result.push_back(*i);
	}
	return result;
}
Turret::Turret()
//				: find_target(FinderCatalog::default_finder(this))
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
}


Turret::Turret(Cell_type cell_type, sf::RectangleShape& shape, int range)
				: Cell(cell_type, shape),
				  range(range)
//				  find_target(FinderCatalog::default_finder(this))
{
	find_target = std::bind(&FinderCatalog::closest_enemy_finder, this);
}

bool Turret::can_shoot() {
	if(time_of_last_shot + time_beetwen_shot < std::chrono::system_clock::now()) {
//		time_of_last_shot = std::chrono::system_clock::now();
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
	objectStorage -> add_bullet(new Bullet(bullet_shape,find_target(), 10, 1));
	time_of_last_shot = std::chrono::system_clock::now();
}
