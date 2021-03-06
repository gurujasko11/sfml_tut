#include <iostream>
#include "../headers/Level.h"
#include "../headers/WavyPushStrategy.h"

Level::Level(sf::RenderWindow* window) : window(window){
	pushStrategy = new WavyPushStrategy(this);
	enemies.back();
//	std::cout<<"konstruktor level"<<std::endl;
}
void Level::add_enemy(Enemy* enemy) {
	enemies.push_back(enemy);
}
void Level::add_bullet(Bullet* bullet) {
	bullets.push_back(bullet);
}

void Level::move_bullets() {
	for(std::list<Bullet*>::iterator it = bullets.begin();it != bullets.end();) {
		(*it)->move();
		if((*it)->enemy->get_distance_from((*it)->shape) < 2) {
			(*it)->hit();
			if ((*it)->enemy->getHp() < 0) {
				enemies_to_delete.insert((*it)->enemy);
//				std::cout << "DODAL ENEMY DO LLISTY" << std::endl;
			}
			Bullet *bullet_to_delete = *it;
			bullets.erase(it++);
			delete bullet_to_delete;
//			std::cout << "DELETED BULLET" << std::endl;
		}
		else
			it++;
	}
}
void Level::move_enemies() {
	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end();it++)
		(*it)->move();
}

void Level::draw_bullets() {
	for(std::list<Bullet*>::iterator it = bullets.begin();it != bullets.end(); it++)
		window -> draw(*(*it)->get_shape());
}
void Level::draw_enemies() {
//	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end(); it++){
//
//		std::cout<<"XXXX"<< enemies.size()<<std::endl;
//		if((*it)->get_shape() == NULL)
//			std::cout<<"NULL"<<std::endl;
//		std::cout<<"QQQQQQQQQQQQQQQQQQ"<<std::endl;
//		window -> draw(*((*it)->get_shape()));
//		std::cout<<"po draw single enemy"<<std::endl;
//		window -> draw(*(*it)->hp_shape);
//		std::cout<<"po draw single enemy hp"<<std::endl;
//	}
	for(std::list<Enemy*>::iterator it = enemies.begin();it != enemies.end(); it++){
//		std::cout << (*it)->shape->getPosition().x << std::endl;
//		std::cout << (*it)->shape->getPosition().y << std::endl;
		window -> draw(*(*it)->shape);
		window -> draw(*(*it)->hp_shape);
		}
}

void Level::clean_enemies() {
	for(std::set<Enemy*>::iterator it = enemies_to_delete.begin();it != enemies_to_delete.end();) {
		Enemy* enemy = *it;
//		std::cout << "PRZED REMOVE IF" << std::endl;
		bullets.remove_if([enemy] (Bullet* b) -> bool {return b->enemy == enemy;});
//		std::cout << "po REMOVE IF" << std::endl;
		enemies_to_delete.erase(it++);
		enemies.remove(enemy);
//		std::cout << "enemies erase" << std::endl;
		delete enemy;
//		std::cout << "po delete enemy" << std::endl;
	}
}
