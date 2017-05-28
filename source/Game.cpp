#include <iostream>
#include "../headers/Game.h"
#include "../headers/LinearPushStrategy.h"
#include "../headers/WavyPushStrategy.h"
#include "../headers/GlobalVariables.h"

Game::Game(Background& background, sf::RenderWindow* window)
:background(background),
 window(window) {
	userInterface = new UserInterface(window);
	pushStrategy = new WavyPushStrategy(this);
}

void Game::play()
{
	if(!can_tick())
		return;
	window->clear();
	background.draw_bg(*window);
	userInterface->show();

	if(!pushStrategy->is_done()){
		pushStrategy->push();
	}

	move_movables();
	draw_movables();
	time_of_last_tick = std::chrono::system_clock::now();
}

void Game::move_movables() {
	for(std::list<Bullet*>::iterator it = bullets.begin();it != bullets.end();){
		(*it)->move();
		if((*it)->enemy->get_distance_from((*it)->shape) < 2) {
			(*it)->enemy->hp -= (*it)->power;
			if((*it)->enemy->getHp() < 0){
				enemies_to_delete.push_back((*it)->enemy);
				std::cout << "DODAL ENEMY DO LLISTY" << std::endl;
			}
			Bullet* bullet_to_delete = *it;
			bullets.erase(it++);
			delete bullet_to_delete;
			std::cout << "DELETED BULLET" << std::endl;
		}
		else
			it++;
	}
	//its time for cleanup
	for(std::list<Enemy*>::iterator it = enemies_to_delete.begin();it != enemies_to_delete.end();) {
		Enemy* enemy = *it;
		std::cout << "PRZED REMOVE IF" << std::endl;
		bullets.remove_if([enemy] (Bullet* b) -> bool {return b->enemy == enemy;});
		std::cout << "po REMOVE IF" << std::endl;
		enemies_to_delete.erase(it++);
		enemies.remove(enemy);
		std::cout << "enemies erase" << std::endl;
		delete enemy;
		std::cout << "po delete enemy" << std::endl;
	}
	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end();it++)
		(*it)->move();
	for(std::list<Turret*>::iterator it = turrets.begin();it != turrets.end();it++)
		(*it)->move();
}

void Game::draw_movables() {
	for(std::list<Turret*>::iterator it = turrets.begin();it != turrets.end(); it++)
		window -> draw(*(*it)->get_shape());
	for(std::list<Bullet*>::iterator it = bullets.begin();it != bullets.end(); it++)
		window -> draw(*(*it)->get_shape());
	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end(); it++)
		window -> draw(*(*it)->get_shape());
}

void Game::add_enemy(Enemy* enemy) {
	enemies.push_back(enemy);
}
void Game::add_turret(Turret* turret) {
	turret->game = this;
	turrets.push_back(turret);
}

void Game::add_bullet(Bullet* bullet) {
	bullets.push_back(bullet);
}

bool Game::can_tick() {
//	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::seconds(1)/fps).count() << std::endl;
	return (std::chrono::system_clock::now() - time_of_last_tick)*fps >= (std::chrono::seconds(1));
}
