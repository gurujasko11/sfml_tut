#include <iostream>
#include "../headers/Game.h"
#include "../headers/LinearPushStrategy.h"
#include "../headers/GlobalVariables.h"

Game::Game(Background& background, sf::RenderWindow* window)
:background(background),
 window(window) {
	userInterface = new UserInterface(window);
	pushStrategy = new LinearPushStrategy(this);
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
	for(std::list<Turret*>::iterator it = turrets.begin();it != turrets.end();it++)
		(*it)->move();
	for(std::list<Bullet*>::iterator it = bullets.begin();it != bullets.end();it++)
		(*it)->move();
	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end();it++)
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
