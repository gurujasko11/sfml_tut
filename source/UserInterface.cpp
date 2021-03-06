#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../headers/UserInterface.h"
#include "../headers/Kieszonka.h"
#include "../headers/Game.h"
#include "../headers/FinderCatalog.h"
#include "../headers/GlobalVariables.h"

UserInterface::UserInterface(sf::RenderWindow* window, Game* game) : window(window), game(game) {
	UI_Background = new sf::RectangleShape(sf::Vector2f(320.0f,512.0f));
	UI_Background->setPosition(sf::Vector2f(512.0f,0.0f));
	sf::Texture* bg_texture = new sf::Texture;
	bg_texture->loadFromFile("res/UI_BG.png");
	UI_Background->setTexture(bg_texture);
	turret_builder = nullptr;
	selected_turret = nullptr;

	sf::Texture* turret1_texture = new sf::Texture();
	sf::Texture* turret2_texture = new sf::Texture();
	sf::Texture* turret3_texture = new sf::Texture();
	sf::Texture* turret4_texture = new sf::Texture();

	sf::Texture* farthest_enemy_texture = new sf::Texture();
	sf::Texture* nearest_enemy_texture = new sf::Texture();
	sf::Texture* strongest_enemy_texture = new sf::Texture();
	sf::Texture* weakest_enemy_texture = new sf::Texture();

	sf::Texture* next_wave_texture = new sf::Texture();
	sf::Texture* upgrade_texture = new sf::Texture();
	sf::Texture* sell_texture = new sf::Texture();
	sf::Texture* tick_texture = new sf::Texture();

	sf::Texture* selected_turret_texture = new sf::Texture();

	next_wave_texture->loadFromFile("res/new_wave_button.png");
	upgrade_texture->loadFromFile("res/upgrade_button.png");
	sell_texture->loadFromFile("res/sell_button.png");
	turret1_texture->loadFromFile("res/turret1.png");
	turret2_texture->loadFromFile("res/turret2.png");
	turret3_texture->loadFromFile("res/turret3.png");
	turret4_texture->loadFromFile("res/turret4.png");
	farthest_enemy_texture->loadFromFile("res/attack_the_farthest.png");
	nearest_enemy_texture->loadFromFile("res/attack_the_nearest.png");
	strongest_enemy_texture->loadFromFile("res/attack_the_strongest.png");
	weakest_enemy_texture->loadFromFile("res/attack_the_weakest.png");
	tick_texture->loadFromFile("res/tick.png");
	selected_turret_texture->loadFromFile("res/selected_turret.png");

	next_wave_button = new sf::RectangleShape(sf::Vector2<float>(next_wave_size_x,next_wave_size_y));
	next_wave_button->setTexture(next_wave_texture);
	next_wave_button->setPosition(sf::Vector2<float>(next_wave_pos_x,next_wave_pos_y));

	sell_button = new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	sell_button ->setTexture(sell_texture);
	sell_button ->setPosition(sf::Vector2<float>(turrets_ui_row_x,turrets_ui_row_y+turrets_ui_cell_size));

	upgrade_button = new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	upgrade_button ->setTexture(upgrade_texture);
	upgrade_button ->setPosition(sf::Vector2<float>(turrets_ui_row_x+(2*turrets_ui_cell_size),turrets_ui_row_y+turrets_ui_cell_size));

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

	farthest_enemy_button = new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	farthest_enemy_button->setTexture(farthest_enemy_texture);
	farthest_enemy_button->setPosition(sf::Vector2<float>(512.0f,200.0f));

	nearest_enemy_button = new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	nearest_enemy_button->setTexture(nearest_enemy_texture);
	nearest_enemy_button->setPosition(sf::Vector2<float>(512.0f,240.0f));

	strongest_enemy_button= new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	strongest_enemy_button->setTexture(strongest_enemy_texture);
	strongest_enemy_button->setPosition(sf::Vector2<float>(512.0f,280.0f));

	weakest_enemy_button= new sf::RectangleShape(sf::Vector2<float>(2*turrets_ui_cell_size,turrets_ui_cell_size/2));
	weakest_enemy_button->setTexture(weakest_enemy_texture);
	weakest_enemy_button->setPosition(sf::Vector2<float>(512.0f,320.0f));

	tick_shape= new sf::RectangleShape(sf::Vector2<float>(turrets_ui_cell_size/2,turrets_ui_cell_size/2));
	tick_shape->setTexture(tick_texture);

	selected_turret_shape = new sf::RectangleShape(sf::Vector2<float>(cell_size,cell_size));
	selected_turret_shape ->setTexture(selected_turret_texture);

	font->loadFromFile("res/arial.ttf");
  score_text = new sf::Text();
  score_text->setFont(*font);
	score_text->setCharacterSize(24);
  score_text->setString(*(score->get_string()));
  score_text->setPosition(sf::Vector2f(517.0f, 0.0f));

  lvl_text = new sf::Text();
  lvl_text->setFont(*font);
  lvl_text->setCharacterSize(14);
  lvl_text->setPosition(sf::Vector2f(672.0f, 200.0f));
  damage_text = new sf::Text();
  damage_text->setFont(*font);
  damage_text->setCharacterSize(14);
  damage_text->setPosition(sf::Vector2f(672.0f, 240.0f));
  range_text = new sf::Text();
  range_text->setFont(*font);
  range_text->setCharacterSize(14);
  range_text->setPosition(sf::Vector2f(672.0f, 280.0f));
  interval_text = new sf::Text();
  interval_text->setFont(*font);
  interval_text->setCharacterSize(14);
  interval_text->setPosition(sf::Vector2f(672.0f, 320.0f));

  money_text = new sf::Text();
  money_text->setFont(*font);
  money_text->setCharacterSize(14);
  money_text->setPosition(sf::Vector2f(517.0f, 40.0f));
  game_hp_text = new sf::Text();
  game_hp_text->setFont(*font);
  game_hp_text->setCharacterSize(14);
  game_hp_text->setPosition(sf::Vector2f(517.0f, 512.0f-160.0f));

}

void UserInterface::handle_player_input(int x, int y) {


	if(game->state == Game::game_state::GAME_OVER) {
		if(game->welcomeBoard->is_play_button_pressed(x,y)){
			std::cout << "INITIAL BUTTON PRESSED" << std::endl;
			game_hp->getInstance()->hp = 1;
			game->state = Game::game_state::INITIAL;
		}
		return;
	}
	if(game->state == Game::game_state::INITIAL) {
		if(game->welcomeBoard->is_play_button_pressed(x,y)){
			std::cout << "INITIAL BUTTON PRESSED" << std::endl;
			game->state = Game::game_state::LEVEL_NOT_STARTED;
		}
		return;
	}
	if(is_next_wave_button_clicked(x,y)) {
		game->stage->level++;
		game->state = Game::game_state::LEVEL_STARTED;
		return;
	}

	if(selected_turret != nullptr) {
		if(is_sell_button_clicked(x,y)) {
			game->rm_turret(selected_turret);
//			std::cout << "usunalem turret"  << std::endl;
			selected_turret = nullptr;
		}
		if(is_upgrade_button_clicked(x,y)) {
			if(selected_turret->lvl < 10)
				selected_turret->lvl++;
		}
		if(is_shoot_strategy_button_clicked(x,y)) {
//						std::cout << "UPDATE " <<get_clicked_strategy(x,y) << std::endl;
			switch(get_clicked_strategy(x,y)) {
				case Turret::find_function_type::NEAREST:
					selected_turret->find_target_type = Turret::find_function_type::NEAREST;
					selected_turret->find_target = std::bind(&FinderCatalog::closest_enemy_finder, selected_turret);
					break;
				case Turret::find_function_type::FARTHEST:
					selected_turret->find_target_type = Turret::find_function_type::FARTHEST;
					selected_turret->find_target = std::bind(&FinderCatalog::farrest_enemy_finder, selected_turret);
					break;
				case Turret::find_function_type::STRONGEST:
					selected_turret->find_target_type = Turret::find_function_type::STRONGEST;
					selected_turret->find_target = std::bind(&FinderCatalog::strongest_enemy_finder, selected_turret);
					break;
				case Turret::find_function_type::WEAKEST:
					selected_turret->find_target_type = Turret::find_function_type::WEAKEST;
					selected_turret->find_target = std::bind(&FinderCatalog::weakest_enemy_finder, selected_turret);
					break;
			}
		}
	}
	if(x < turrets_ui_row_x) {
		if(game->stage->background.BG_matrix[x/cell_size][y/cell_size]->cell_type == Cell::TURRET) {
			selected_turret = (Turret*)game->stage->background.BG_matrix[x/cell_size][y/cell_size];
			selected_turret_shape->setPosition(selected_turret->get_shape()->getPosition());
		}
		else
			selected_turret = nullptr;
	}
	if(y > turrets_ui_row_y && y < turrets_ui_row_y+(4*turrets_ui_cell_size)) {
		if(x > turrets_ui_row_x && x < turrets_ui_row_x + turrets_ui_cell_size) {
			turret_builder = get_turret1;
            cost = turret_cost1;
            std::cout << "kurwa " << std::endl;
            std::cout << cost << std::endl;
        }
		if(x > turrets_ui_row_x + turrets_ui_cell_size && x < turrets_ui_row_x + (2*turrets_ui_cell_size)) {
			turret_builder = get_turret2;
            cost = turret_cost2;
		}
		if(x > turrets_ui_row_x + (2*turrets_ui_cell_size)&& x < turrets_ui_row_x + (3*turrets_ui_cell_size)) {
			turret_builder = get_turret3;
            cost = turret_cost3;
		}
		if(x > turrets_ui_row_x + (3*turrets_ui_cell_size) && x < turrets_ui_row_x + (4*turrets_ui_cell_size)) {
			turret_builder = get_turret4;
            cost = turret_cost4;
		}
	}
	if(x < turrets_ui_row_x && turret_builder != nullptr) {
		//turret_builder();
//		std::cout<<"wywolalem turret builder" << std::endl;
        if(cost <= game->money) {
            game->stage->add_turret(turret_builder(), x / cell_size, y / cell_size);
            game->money -= cost;
            std::cout << game->money << std::endl;
            std::cout << cost << std::endl;
        }

	}
}

bool UserInterface::is_next_wave_button_clicked(int x, int y) {
	if(game->stage->is_level_active())
		return false;
	return x > next_wave_pos_x && y >next_wave_pos_y;
}

bool UserInterface::is_sell_button_clicked(int x, int y) {
	return x > sell_button->getPosition().x && x < sell_button->getPosition().x + sell_button->getSize().x
	&& y > sell_button->getPosition().y && y < sell_button->getPosition().y + sell_button->getSize().y;
}
bool UserInterface::is_upgrade_button_clicked(int x, int y) {
	return x > upgrade_button->getPosition().x && x < upgrade_button->getPosition().x + upgrade_button->getSize().x
	&& y > upgrade_button->getPosition().y && y < upgrade_button->getPosition().y + upgrade_button->getSize().y;
}
void UserInterface::update_score_text(){
    static int last_score = score->score;
    if(last_score != score->score) {
        score_text->setString(*(score->get_string()));
        game->money += (score->score - last_score)/2;
        last_score = score->score;
    }
//    std::cout<< "UPDATEEEEEEE: " << score->score << std::endl;
}

void UserInterface::update_turret_ui(){
    if(selected_turret != nullptr){
        lvl_text     ->setString("Level:   " + std::to_string(selected_turret->lvl));
        damage_text  ->setString("Damage:  " + std::to_string(selected_turret->get_fixed_damage()));
        range_text   ->setString("Range:   " + std::to_string(selected_turret->get_fixed_range()));
        interval_text->setString("Interval:" + std::to_string((selected_turret->get_fixed_time()).count()));
	    set_tick_position();
    }
}

void UserInterface::update_game_hp_text(){
    game_hp_text->setString("HP: " + std::to_string(game_hp->getInstance()->hp));
}

void UserInterface::update_money_text(){
    money_text->setString("Money: " + std::to_string(game->money));
}

void UserInterface::set_tick_position() {
	switch(selected_turret->find_target_type){
		case Turret::find_function_type::NEAREST:
			tick_shape->setPosition(632.0f,200.0f);
			break;
		case Turret::find_function_type::FARTHEST:
			tick_shape->setPosition(632.0f,240.0f);
			break;
		case Turret::find_function_type::STRONGEST:
			tick_shape->setPosition(632.0f,280.0f);
			break;
		case Turret::find_function_type::WEAKEST:
			tick_shape->setPosition(632.0f,320.0f);
			break;
	}
}


bool UserInterface::is_shoot_strategy_button_clicked(int x, int y) {
	return (x > 512 && x < 672 && y >  200 && y < 360);
}

Turret::find_function_type UserInterface::get_clicked_strategy(int x, int y) {
	if(y < 240)
		return Turret::find_function_type::NEAREST;
	if(y < 280)
		return Turret::find_function_type::FARTHEST;
	if(y < 320)
		return Turret::find_function_type::STRONGEST;
	return Turret::find_function_type::WEAKEST;
}

void UserInterface::draw_selected_turret() {
	if(selected_turret != nullptr)
		window->draw(*selected_turret_shape);
}

void UserInterface::show() {
	window->draw(*UI_Background);
	window->draw(*sell_button);
	window->draw(*upgrade_button);
	window->draw(*turret1);
	window->draw(*turret2);
	window->draw(*turret3);
	window->draw(*turret4);


  window->draw(*next_wave_button);
  update_score_text();
  window->draw(*score_text);
  update_turret_ui();
  update_game_hp_text();
  update_money_text();
  window->draw(*game_hp_text);
  window->draw(*money_text);
  if(selected_turret != nullptr) {
  	window->draw(*lvl_text);
  	window->draw(*damage_text);
  	window->draw(*range_text);
  	window->draw(*interval_text);
  	window->draw(*farthest_enemy_button);
  	window->draw(*nearest_enemy_button);
  	window->draw(*strongest_enemy_button);
  	window->draw(*weakest_enemy_button);
  	window->draw(*tick_shape);
  }
}
