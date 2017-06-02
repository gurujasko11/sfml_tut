#ifndef SFML_TUT_USERINTERFACE_H
#define SFML_TUT_USERINTERFACE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <functional>
#include "Turret.h"

class Game;

class UserInterface {
private:
		sf::RenderWindow* window;
		sf::RectangleShape* UI_Background;
		sf::Text* score_text;
public:
		Game* game;
		sf::RectangleShape* turret1;
		sf::RectangleShape* turret2;
		sf::RectangleShape* turret3;
		sf::RectangleShape* turret4;

		sf::RectangleShape* next_wave_button;
		sf::RectangleShape* upgrade_button;
		sf::RectangleShape* sell_button;

		Turret* selected_turret;
		std::function<Turret*()> turret_builder;
		UserInterface(sf::RenderWindow* window, Game* game);
        void update_score_text();
		void show();
		void handle_player_input(int x, int y);

		bool is_sell_button_clicked(int x, int y);
		bool is_upgrade_button_clicked(int x, int y);

};

#endif //SFML_TUT_USERINTERFACE_H
