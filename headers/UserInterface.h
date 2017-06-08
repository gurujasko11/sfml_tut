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


        sf::Text* game_hp_text;
        sf::Text* money_text;
		//---------------Turret-----------//
		sf::Text* lvl_text;
		sf::Text* damage_text;
		sf::Text* range_text;
		sf::Text* interval_text;
		//--------------------------------//
public:
		Game* game;
		sf::RectangleShape* turret1;
		sf::RectangleShape* turret2;
		sf::RectangleShape* turret3;
		sf::RectangleShape* turret4;

		sf::RectangleShape* next_wave_button;
		sf::RectangleShape* upgrade_button;
		sf::RectangleShape* sell_button;

		sf::RectangleShape* farthest_enemy_button;
		sf::RectangleShape* nearest_enemy_button;
		sf::RectangleShape* strongest_enemy_button;
		sf::RectangleShape* weakest_enemy_button;
		sf::RectangleShape* tick_shape;

		sf::RectangleShape* selected_turret_shape;

		Turret* selected_turret;
		std::function<Turret*()> turret_builder;
		UserInterface(sf::RenderWindow* window, Game* game);
        void update_score_text();
		void update_turret_ui();
        void update_game_hp_text();
        void update_money_text();
		void show();
		void handle_player_input(int x, int y);
		void set_tick_position();

		void draw_selected_turret();

		bool is_sell_button_clicked(int x, int y);
		bool is_next_wave_button_clicked(int x, int y);
		bool is_upgrade_button_clicked(int x, int y);

		bool is_shoot_strategy_button_clicked(int x, int y);
		Turret::find_function_type get_clicked_strategy(int x, int y);

};

#endif //SFML_TUT_USERINTERFACE_H
