#include <iostream>
#include "../headers/Game.h"
#include "../headers/ObjectsStorage.h"

Game::Game(Background& background, sf::RenderWindow* window)
:background(background),
 window(window) {
	objectStorage = new ObjectStorage();
}

void Game::play()
{
	window->clear();
	background.draw_bg(*window);
	draw_turrets();
	move_enemies();
	draw_enemies();
}

void Game::move_enemies()
{
		std::list<Enemy*>::iterator it = objectStorage->get_enemies_begin();
		while(it != objectStorage->get_enemies_end())
		{
			if((*it)->is_on_target())
			{
				(*it)->next_target();
			}
			(*it)->move_shape_to_target();
			it++;
		}
};

void Game::draw_enemies()
{
	std::list<Enemy*>::iterator it = objectStorage->get_enemies_begin();
	while(it != objectStorage->get_enemies_end())
	{
		window->draw(*((*it)->shape));
		it++;
	}
}

void Game::draw_turrets()
{
	std::list<Turret*>::iterator it = objectStorage->get_turrets_begin();
	while(it != objectStorage->get_turrets_end())
	{
		window->draw((*it)->shape);
		(*it)->find_target();
		it++;
	}
}


void Game::add_enemy(Enemy* enemy) {
	objectStorage->add_enemy(enemy);
}
void Game::add_turret(Turret* turret) {
	objectStorage->add_turrets(turret);
}
