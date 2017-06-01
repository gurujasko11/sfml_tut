#include "../headers/Background.h"
#include "../headers/BG_Builder.h"
#include "../headers/Turret.h"

Background get_background1() {
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
	return bg_builder.build();
}

Turret* get_turret1() {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/turret1.png");
	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2<float>(32,32));
	shape->setTexture(texture);
	return new Turret(Cell::TURRET,shape,150, 50);
}
Turret* get_turret2() {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/turret2.png");
	
	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2<float>(32,32));
	shape->setTexture(texture);
	return new Turret(Cell::TURRET,shape,150,50,Color::BLUE);
}
Turret* get_turret3() {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/turret3.png");
	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2<float>(32,32));
	shape->setTexture(texture);
	return new Turret(Cell::TURRET,shape,150,50,Color::RED);
}
Turret* get_turret4() {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile("res/turret4.png");
	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2<float>(32,32));
	shape->setTexture(texture);
	return new Turret(Cell::TURRET,shape,150,50,Color::GREEN);
}
