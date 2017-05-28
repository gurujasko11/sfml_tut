#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Background.h"
#include "Movable.h"

class Enemy : public Movable {
public:
		Enemy (sf::Shape* shape, float& speed, int hp);

		bool is_on_target();
		float get_distance_from(sf::Shape* shape);
		void move() override;
		void next_target();

		static std::list<sf::Shape*> targets;
		sf::Shape* shape;

		float getSpeed () const;
		int getHp () const;
		sf::Shape* get_shape() override;
		~Enemy ();
		int hp;
private:
		std::list<sf::Shape*>::iterator index;
		float speed;
};

#endif //ENEMY_H
