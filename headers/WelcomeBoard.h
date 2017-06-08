#ifndef SFML_TUT_WELCOMEBOARD_H
#define SFML_TUT_WELCOMEBOARD_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

class WelcomeBoard {
		int play_button_position_x = 250;
		int play_button_position_y = 250;
public:
		sf::RenderWindow* window;
		sf::RectangleShape* bg_shape;
		sf::RectangleShape* playButton;
		sf::RectangleShape* playAgainButton;

		sf::Text* score_text;

		sf::Texture* bg_texture;
		sf::Texture* play_button_texture;
		sf::Texture* play_again_button_texture;

		WelcomeBoard(sf::RenderWindow* window);
		bool is_play_button_pressed(int x, int y);

		void showWelcomeBoard();
		void showLooserBoard();
		int score;
};
#endif //SFML_TUT_WELCOMEBOARD_H
