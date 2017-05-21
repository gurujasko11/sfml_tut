#include <iostream>
#include "../headers/Game.h"
#include "../headers/Turret.h"

Game::Game(Background& background, sf::RenderWindow* window)
:background(background),
 window(window) {
	objectStorage = new ObjectStorage(this);
	userInterface = new UserInterface(window);
}

void Game::play()
{
	window->clear();
	background.draw_bg(*window);
	userInterface->show();

	move_movables();
	draw_movables();
}

void Game::move_movables() {
	for(std::list<Movable*>::iterator it = movables.begin();it != movables.end();)
	{
		Movable* movable = *it;
		if((*it)->move()) {
			movables.erase(it++);
			delete movable;
		}
		else
			it++;
	}
}

void Game::draw_movables() {
	for(std::list<Movable*>::iterator it = movables.begin();it != movables.end(); it++)
	{
		window -> draw(*(*it)->get_shape());
	}
}

void Game::add_enemy(Enemy* enemy) {
	objectStorage->add_enemy(enemy);
}
void Game::add_turret(Turret* turret) {
	turret->objectStorage = objectStorage;
	objectStorage->add_turrets(turret);
}

void Game::add_movable(Movable* movable) {
	movables.push_back(movable);
}
