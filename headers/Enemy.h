#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Background.h"

class Enemy
{
public:
		Enemy (sf::Shape* shape, float& speed, int hp);

		bool is_on_target();
		float get_distance_from(sf::Shape* shape);
		void move_shape_to_target();
		void next_target();

		static std::list<sf::Shape*> targets;
		sf::Shape* shape;

		float getSpeed () const;
		int getHp () const;

private:
		std::list<sf::Shape*>::iterator index;
		float speed;
		int hp;
};

#endif //ENEMY_H
