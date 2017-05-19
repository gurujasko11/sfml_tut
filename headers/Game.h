#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "Enemy.h"
#include "Turret.h"
#include "Background.h"
#include "ObjectsStorage.h"

class Game
{
private:
		ObjectStorage* objectStorage;

public:
		void play();
//private:
//		all fields are public cos there no seters provided
//		YET
//		TODO
		Game(Background& background, sf::RenderWindow* window);
		sf::RenderWindow* window;
		Background background;

		void move_enemies();

		void draw_enemies();
		void draw_turrets();

		void add_enemy(Enemy* enemy);
		void add_turret(Turret* turret);
};
#endif //GAME_H
