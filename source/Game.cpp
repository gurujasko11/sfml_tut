#include <iostream>
#include "../headers/Game.h"

Game::Game(sf::RenderWindow* window) : window(window){
	userInterface = new UserInterface(window, this);
	stage = new Stage(window);
	state = INITIAL;
	welcomeBoard = new WelcomeBoard(window);
}
void Game::play() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				userInterface->handle_player_input(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);
				break;
		}
	}
	if(state == INITIAL) {
//		state = LEVEL_NOT_STARTED;
		welcomeBoard->show();
		window->display();
		return;
	}
	if(!can_tick())
		return;
	if(!stage->is_level_active())
		state = game_state::LEVEL_NOT_STARTED;
	if(stage->level == stage->levels.end()) {
		state = game_state::STAGE_FINISHED;
		return;
	}
	window->clear();
	userInterface->show();
	stage->draw_background();
//	std::cout<<"Po draw_background()"<<std::endl;
	if(stage->is_level_active()){
//		std::cout<<"checkpoint0"<<std::endl;
		if(!(stage->get_level()->pushStrategy->is_done())){
			stage->get_level()->pushStrategy->push();
		}
		stage->move_level();

		stage->draw_level();

//		std::cout<<"po levelu"<<std::endl;
		stage->handle_turrets();
	}
//	std::cout<<"Przed draw_turrets()"<<std::endl;
	stage->draw_turrets();
	userInterface->draw_selected_turret();
	time_of_last_tick = std::chrono::system_clock::now();
}

bool Game::rm_turret(Turret* turret) {
	sf::Texture* bgTexture = new sf::Texture();
	bgTexture->loadFromFile("res/bg_cell.png");
	sf::RectangleShape* bg_shape = new sf::RectangleShape(sf::Vector2<float>(32,32));
	bg_shape->setTexture(bgTexture);
	bg_shape->setPosition(sf::Vector2f(turret->shape->getPosition().x,turret->shape->getPosition().y));
	stage->background.BG_matrix[(int)(turret->shape->getPosition().x/cell_size)][(int)(turret->shape->getPosition().y/cell_size)] = new Cell(Cell::BACKGROUND,bg_shape);
	stage->turrets.remove(turret);
//	std::cout << "przed remove turret w rm_turret" << std::endl;
	delete turret;
}
bool Game::can_tick() {
	return (std::chrono::system_clock::now() - time_of_last_tick)*fps >= (std::chrono::seconds(1));
}
