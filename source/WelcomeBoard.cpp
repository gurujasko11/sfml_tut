#include <iostream>
#include "WelcomeBoard.h"
#include "../headers/WelcomeBoard.h"

WelcomeBoard::WelcomeBoard (sf::RenderWindow* window) : window(window) {

	bg_texture = new sf::Texture();
	bg_texture->loadFromFile("res/game_bg.png");
	bg_shape = new sf::RectangleShape(sf::Vector2<float>(window->getSize().x,window->getSize().y));
	bg_shape ->setTexture(bg_texture);
	bg_shape ->setPosition(sf::Vector2<float>(0,0));

	play_button_texture = new sf::Texture();
	play_button_texture->loadFromFile("res/play_button.png");
	playButton = new sf::RectangleShape(sf::Vector2<float>(400,100));
	playButton ->setTexture(play_button_texture);
	playButton ->setPosition(sf::Vector2<float>(play_button_position_x,play_button_position_x));
}

void WelcomeBoard::show () {
	window->draw(*bg_shape);
	window->draw(*playButton);
}

bool WelcomeBoard::is_play_button_pressed (int x, int y) {
	return (x > play_button_position_x && x < play_button_position_x + playButton->getSize().x && y > play_button_position_y && y < play_button_position_y + playButton->getSize().y);
}

