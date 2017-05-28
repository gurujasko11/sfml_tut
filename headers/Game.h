#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include "Enemy.h"
#include "Background.h"
#include "UserInterface.h"
#include "Bullet.h"
#include "Turret.h"

class PushStrategy;


class Game
{
private:
		UserInterface* userInterface;
		PushStrategy* pushStrategy;
		std::chrono::time_point<std::chrono::system_clock> time_of_last_tick = std::chrono::system_clock::now();
public:
//		const std::chrono::duration<double, std::milli> second = std::chrono::duration<double, std::milli>(1000.0);
		void play();
//private:
//		all fields are public cos there no seters provided
//		YET
//		TODO
		bool can_tick();
		Game(Background& background, sf::RenderWindow* window);
		sf::RenderWindow* window;
		Background background;

		std::list<Bullet*> bullets;
		std::list<Enemy*> enemies;
		std::list<Turret*> turrets;
		void move_movables();
		void draw_movables();

		void add_enemy(Enemy* enemy);
		void add_turret(Turret* turret);
		void add_bullet(Bullet* bullet);

		void handle_player_input();
		void draw_userInterface();
};
#endif //GAME_H
