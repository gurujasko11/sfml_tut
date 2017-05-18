#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "Enemy.h"
#include "Turret.h"
#include "Background.h"

class Game
{
public:
		void play();
//private:
//		all fields are public cos there no seters provided
//		YET
//		TODO
		Game(Background& background, sf::RenderWindow* window);
		sf::RenderWindow* window;
		std::list<Enemy*> enemies;
		std::list<Turret*> turrets;
		Background background;

		void move_enemies();

		void draw_enemies();
		void draw_turrets();

};
#endif //GAME_H
