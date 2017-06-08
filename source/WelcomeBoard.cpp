#include <iostream>
#include "WelcomeBoard.h"
#include "../headers/WelcomeBoard.h"
#include "GlobalVariables.h"

WelcomeBoard::WelcomeBoard (sf::RenderWindow* window) : window(window) {

	bg_texture = new sf::Texture();
	bg_texture->loadFromFile("res/game_bg.png");
	bg_shape = new sf::RectangleShape(sf::Vector2<float>(window->getSize().x,window->getSize().y));
	bg_shape ->setTexture(bg_texture);
	bg_shape ->setPosition(sf::Vector2<float>(0,0));

	play_button_texture = new sf::Texture();
	play_button_texture->loadFromFile("res/play_button.png");
	playButton = new sf::RectangleShape(sf::Vector2<float>(350,100));
	playButton ->setTexture(play_button_texture);
	playButton ->setPosition(sf::Vector2<float>(play_button_position_x,play_button_position_x));

	play_again_button_texture = new sf::Texture();
	play_again_button_texture->loadFromFile("res/play_again_button.png");
	playAgainButton = new sf::RectangleShape(sf::Vector2<float>(350,100));
	playAgainButton ->setTexture(play_again_button_texture);
	playAgainButton ->setPosition(sf::Vector2<float>(play_button_position_x,play_button_position_x));

	score_text = new sf::Text();
	score_text ->setFont(*font);
	score_text ->setCharacterSize(24);
	score_text ->setPosition(sf::Vector2f(350, 50));
}

void WelcomeBoard::showWelcomeBoard() {
	window->draw(*bg_shape);
	window->draw(*playButton);
}

void WelcomeBoard::showLooserBoard() {
	window->draw(*bg_shape);
	score_text->setString("Your score"+std::to_string(score));
//	window->draw(*score_text);
	window->draw(*playAgainButton);
}

bool WelcomeBoard::is_play_button_pressed (int x, int y) {
	return (x > play_button_position_x && x < play_button_position_x + playButton->getSize().x && y > play_button_position_y && y < play_button_position_y + playButton->getSize().y);
}

