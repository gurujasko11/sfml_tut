#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/Game.h"
#include "../headers/Kieszonka.h"

std::list<sf::Shape*> Enemy::targets = std::list<sf::Shape*>();
int main()
{
	sf::RenderWindow window(sf::VideoMode(832, 512), "DEFENCE TOWER!", sf::Style::Close);
	Game game(&window);
	game.stage->levels.push_back(nullptr);
	game.stage->levels.push_back(new Level(&window));
	game.stage->levels.push_back(new Level(&window));
	game.stage->levels.push_back(new Level(&window));
	game.stage->levels.push_back(new Level(&window));
	game.stage->level = game.stage->levels.begin();
//	std::cout<<"INICJACJA"<<std::endl;


	while (window.isOpen())
	{
		game.play();
		window.display();
	}

	return 0;
}
