#include <iostream>
#include "../headers/Game.h"

Game::Game(Background& background, sf::RenderWindow* window)
:background(background),
 window(window){}

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
		std::list<Enemy*>::iterator it = enemies.begin();
		while(it != enemies.end())
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
	std::list<Enemy*>::iterator it = enemies.begin();
	while(it != enemies.end())
	{
		window->draw(*((*it)->shape));
		it++;
	}
}

void Game::draw_turrets()
{
	std::list<Turret*>::iterator it = turrets.begin();
	while(it != turrets.end())
	{
		window->draw((*it)->shape);
		it++;
	}
}
