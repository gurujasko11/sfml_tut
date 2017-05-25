#ifndef SFML_TUT_USERINTERFACE_H
#define SFML_TUT_USERINTERFACE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class UserInterface {
private:
		sf::RenderWindow* window;
		sf::RectangleShape* UI_Background;
public:
		UserInterface(sf::RenderWindow* window);
		void show();
};

#endif //SFML_TUT_USERINTERFACE_H
