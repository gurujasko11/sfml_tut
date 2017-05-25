#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "Enemy.h"
#include "Background.h"
#include "ObjectStorage.h"
#include "UserInterface.h"

class PushStrategy;

class Game
{
private:
		ObjectStorage* objectStorage;// when i made this static, S*** happens but WHY?
		UserInterface* userInterface;
		std::list<Movable*> movables;
		PushStrategy* pushStrategy;
public:
		void play();
//private:
//		all fields are public cos there no seters provided
//		YET
//		TODO
		Game(Background& background, sf::RenderWindow* window);
		sf::RenderWindow* window;
		Background background;

		void move_movables();
		void draw_movables();

		void add_enemy(Enemy* enemy);
		void add_turret(Turret* turret);
		void add_movable(Movable* movable);

		void handle_player_input();
		void draw_userInterface();
};
#endif //GAME_H
