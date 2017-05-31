#include <iostream>
#include "../headers/Game.h"

Game::Game(sf::RenderWindow* window) : window(window){
	userInterface = new UserInterface(window);
	stage = new Stage(window);
}
void Game::play() {
	if(!can_tick())
		return;
	window->clear();
	userInterface->show();
	stage->draw_background();
//	std::cout<<"Po draw_background()"<<std::endl;
	if(stage->is_level_active()){
		std::cout<<"checkpoint0"<<std::endl;
		if(!(stage->get_level()->pushStrategy->is_done())){
			stage->get_level()->pushStrategy->push();
		}
		stage->move_level();

		stage->draw_level();

		std::cout<<"po levelu"<<std::endl;
		stage->handle_turrets();
	}
	std::cout<<"Przed draw_turrets()"<<std::endl;
	stage->draw_turrets();
	time_of_last_tick = std::chrono::system_clock::now();
}
bool Game::can_tick() {
	return (std::chrono::system_clock::now() - time_of_last_tick)*fps >= (std::chrono::seconds(1));
}
