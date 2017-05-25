#include <SFML/Graphics/Texture.hpp>
#include "../headers/UserInterface.h"

UserInterface::UserInterface(sf::RenderWindow* window) : window(window) {
	UI_Background = new sf::RectangleShape(sf::Vector2f(320.0f,512.0f));
	UI_Background->setPosition(sf::Vector2f(512.0f,0.0f));
	sf::Texture* bg_texture = new sf::Texture;
	bg_texture->loadFromFile("res/UI_BG.png");
	UI_Background->setTexture(bg_texture);
}

void UserInterface::show() {
	window->draw(*UI_Background);
}
