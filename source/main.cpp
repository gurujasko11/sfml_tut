#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include "../headers/Enemy.h"
#include "../headers/BG_Builder.h"
#include "../headers/Turret.h"
#include "../headers/Game.h"
#include "../headers/Kieszonka.h"

std::list<sf::Shape*> Enemy::targets = std::list<sf::Shape*>();
int main()
{
	sf::RenderWindow window(sf::VideoMode(832, 512), "DEFENCE TOWER!", sf::Style::Close);
	Game game(&window);

//	game.stage->add_turret(get_turret1(),3,3);
//	game.stage->add_turret(get_turret1(),4,3);
//	game.stage->add_turret(get_turret1(),5,3);
//NIE DZIALA DODAWANIE TURRETOW
	game.stage->levels.push_back(new Level(&window));
	game.stage->level = game.stage->levels.begin();
	std::cout<<"INICJACJA"<<std::endl;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if(event.text.unicode < 128)
						std::cout << (char)event.text.unicode << std::endl;
//						printf("%c", event.text.unicode);
					break;
				case sf::Event::MouseButtonPressed:
				std::cout<<Enemy::targets.size() << std::endl;
				std::cout<< "Mouse clicked: " << sf::Mouse::getPosition().x <<", " << sf::Mouse::getPosition().y << std::endl;
					break;
				case sf::Event::MouseButtonReleased:
					std::cout<< "Mouse released: " << sf::Mouse::getPosition().x <<", " << sf::Mouse::getPosition().y << std::endl;
					break;
			}
		}
		std::cout<<"Przed game.play()"<<std::endl;
		game.play();
		std::cout<<"Po game.play()"<<std::endl;
		window.display();
	}

	return 0;
}
