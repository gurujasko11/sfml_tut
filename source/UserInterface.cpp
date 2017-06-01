#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../headers/UserInterface.h"
#include "../headers/GlobalVariables.h"
#include "../headers/Kieszonka.h"
#include "Game.h"
#include "../headers/Game.h"

UserInterface::UserInterface(sf::RenderWindow* window, Game* game) : window(window), game(game) {
	UI_Background = new sf::RectangleShape(sf::Vector2f(320.0f,512.0f));
	UI_Background->setPosition(sf::Vector2f(512.0f,0.0f));
	sf::Texture* bg_texture = new sf::Texture;
	bg_texture->loadFromFile("res/UI_BG.png");
	UI_Background->setTexture(bg_texture);
	turret_builder = nullptr;

	sf::Texture* turret1_texture;
	sf::Texture* turret2_texture;
	sf::Texture* turret3_texture;
	sf::Texture* turret4_texture;

	sf::Texture* next_wave_texture;

	next_wave_texture = new sf::Texture();
	turret1_texture = new sf::Texture();
	turret2_texture = new sf::Texture();
	turret3_texture = new sf::Texture();
	turret4_texture = new sf::Texture();
	next_wave_texture->loadFromFile("res/new_wave_button.png");
	turret1_texture->loadFromFile("res/turret1.png");
	turret2_texture->loadFromFile("res/turret2.png");
	turret3_texture->loadFromFile("res/turret3.png");
	turret4_texture->loadFromFile("res/turret4.png");

	next_wave_button = new sf::RectangleShape(sf::Vector2<float>(next_wave_size_x,next_wave_size_y));
	next_wave_button->setTexture(next_wave_texture);
	next_wave_button->setPosition(sf::Vector2<float>(next_wave_pos_x,next_wave_pos_y));

	turret1 = new sf::RectangleShape(sf::Vector2<float>(turrets_ui_cell_size,turrets_ui_cell_size));
	turret1->setTexture(turret1_texture);
	turret1->setPosition(sf::Vector2<float>(turrets_ui_row_x,turrets_ui_row_y));

	turret2 = new sf::RectangleShape(sf::Vector2<float>(turrets_ui_cell_size,turrets_ui_cell_size));
	turret2->setTexture(turret2_texture);
	turret2->setPosition(sf::Vector2<float>(turrets_ui_row_x+turrets_ui_cell_size,turrets_ui_row_y));

	turret3 = new sf::RectangleShape(sf::Vector2<float>(turrets_ui_cell_size,turrets_ui_cell_size));
	turret3->setTexture(turret3_texture);
	turret3->setPosition(sf::Vector2<float>(turrets_ui_row_x+(2*turrets_ui_cell_size),turrets_ui_row_y));

	turret4 = new sf::RectangleShape(sf::Vector2<float>(turrets_ui_cell_size,turrets_ui_cell_size));
	turret4->setTexture(turret4_texture);
	turret4->setPosition(sf::Vector2<float>(turrets_ui_row_x+(3*turrets_ui_cell_size),turrets_ui_row_y));

    font->loadFromFile("res/arial.ttf");
    score_text = new sf::Text();
    score_text->setFont(*font);
	score_text->setCharacterSize(24);
    score_text->setString(*(score->get_string()));
    score_text->setPosition(sf::Vector2f(512.0f, 0.0f));
}

void UserInterface::handle_player_input(int x, int y) {
	if(y > turrets_ui_row_y && y < turrets_ui_row_y+(4*turrets_ui_cell_size)) {
		if(x > turrets_ui_row_x && x < turrets_ui_row_x + turrets_ui_cell_size) {
			turret_builder = get_turret1;
		}
		if(x > turrets_ui_row_x + turrets_ui_cell_size && x < turrets_ui_row_x + (2*turrets_ui_cell_size)) {
			turret_builder = get_turret2;
		}
		if(x > turrets_ui_row_x + (2*turrets_ui_cell_size)&& x < turrets_ui_row_x + (3*turrets_ui_cell_size)) {
			turret_builder = get_turret3;
		}
		if(x > turrets_ui_row_x + (3*turrets_ui_cell_size) && x < turrets_ui_row_x + (4*turrets_ui_cell_size)) {
			turret_builder = get_turret4;
		}
	}
	if(x < turrets_ui_row_x && turret_builder != nullptr) {
		turret_builder();
//		std::cout<<"wywolalem turret builder" << std::endl;
		game->stage->add_turret(turret_builder(),x / cell_size,y / cell_size);
	}
}

void UserInterface::update_score_text(){
    score_text->setString(*(score->get_string()));
//    std::cout<< "UPDATEEEEEEE: " << score->score << std::endl;
}

void UserInterface::show() {
	window->draw(*UI_Background);
	window->draw(*turret1);
	window->draw(*turret2);
	window->draw(*turret3);
	window->draw(*turret4);
	window->draw(*next_wave_button);
    update_score_text();
    window->draw(*score_text);
}
