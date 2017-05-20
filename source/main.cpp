#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include "../headers/Enemy.h"
#include "../headers/BG_Builder.h"
#include "../headers/Turret.h"
#include "../headers/Game.h"

	std::list<sf::Shape*> Enemy::targets = std::list<sf::Shape*>();
int main()
{
	BG_Builder bg_builder;
	bg_builder.add_point(0,1);
	bg_builder.add_point(6,1);
	bg_builder.add_point(6,5);
	bg_builder.add_point(11,5);
	bg_builder.add_point(11,2);
	bg_builder.add_point(13,2);
	bg_builder.add_point(13,6);
	bg_builder.add_point(14,6);
	bg_builder.add_point(14,8);
	bg_builder.add_point(12,8);
	bg_builder.add_point(12,9);
	bg_builder.add_point(6,9);
	bg_builder.add_point(6,7);
	bg_builder.add_point(2,7);
	bg_builder.add_point(2,14);
	bg_builder.add_point(6,14);
	bg_builder.add_point(6,12);
	bg_builder.add_point(11,12);
	bg_builder.add_point(11,14);
	bg_builder.add_point(15,14);


	sf::Texture nmTexture, rdTexture, bgTexture, fnTexture, trtTexture;
	rdTexture.loadFromFile("res/road_cell.png");
	bgTexture.loadFromFile("res/bg_cell.png");
	nmTexture.loadFromFile("res/nmy1.png");
	fnTexture.loadFromFile("res/finish_cell.png");
	trtTexture.loadFromFile("res/turret1.png");

	Background bg = bg_builder.build(rdTexture, bgTexture, fnTexture);


	sf::RenderWindow window(sf::VideoMode(832, 512), "SFML works!", sf::Style::Close);
	sf::CircleShape nm(16);
	sf::CircleShape nm2(16);
	sf::CircleShape nm3(16);
	sf::CircleShape nm4(16);

	sf::RectangleShape rc1(sf::Vector2<float>(32,32));
	sf::RectangleShape rc2(sf::Vector2<float>(32,32));
	rc1.setTexture(&trtTexture);
	rc1.setPosition(sf::Vector2<float>(6*32,6*32));
	rc2.setTexture(&trtTexture);
	rc2.setPosition(sf::Vector2<float>(9*32,6*32));
	Turret turret1(Cell::TURRET,rc1,150);
	Turret turret2(Cell::TURRET,rc2,150);

	nm.setPosition(sf::Vector2f(0.0f,32.0f));
	nm2.setPosition(sf::Vector2f(0.0f,32.0f));

	nm.setTexture(&nmTexture);
	nm2.setTexture(&nmTexture);


	sf::Vector2<float> target(824.0f, 312.0f);
//	std::list<sf::Vector2<float> *> targets = path.get_targets();

	float speed = 0.3;
	Enemy enemy(&nm, speed, 100);

	Game game(bg, &window);
	game.add_enemy(&enemy);
	game.add_turret(&turret1);
	game.add_turret(&turret2);

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
//		helper(targets,enemies, speed);
		game.play();
//		if(turret1.find_target(enemies) != NULL)
//		{
//			std::cout << turret1.find_target(enemies)->get_distance_from(&turret1.shape) << std::endl;
//		}
		window.display();
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
////			std::cout << ms++ << std::endl;
//		}
	}

	return 0;
}
