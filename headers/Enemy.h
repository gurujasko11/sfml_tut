#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <list>
#include "Background.h"
#include "Movable.h"
#include "Color.h"

class Game;

class Enemy : public Movable {
public:
		Enemy (sf::Shape* shape, float& speed, int hp, Color color = Color::NONE);

		Game* game = nullptr;
		bool is_on_target();
		float get_distance_from(sf::Shape* shape);
		void move() override;
		void next_target();
		void set_game(Game* game);

		static std::list<sf::Shape*> targets;
		sf::Shape* shape;
		sf::RectangleShape* hp_shape;

		float getSpeed () const;
		int getHp () const;
		sf::Shape* get_shape() override;
		~Enemy ();
		float base_hp;
		float hp;
        Color color;
		void hit_by_bullet(int damage);
private:
		std::list<sf::Shape*>::iterator index;
		float speed;
};

#endif //ENEMY_H
