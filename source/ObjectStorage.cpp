#include <iostream>
#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/Game.h"
#include "../headers/ObjectStorage.h"

void ObjectStorage::add_enemy (Enemy* enemy) {
	enemies.push_back(enemy);
	game->add_movable(enemy);
}
void ObjectStorage::add_turrets(Turret* turret) {
	turrets.push_back(turret);
	game->add_movable(turret);
}
void ObjectStorage::add_bullet(Bullet* bullet) {
	bullets.push_back(bullet);
	game->add_movable(bullet);
}

std::list<Enemy*>::iterator ObjectStorage::get_enemies_begin() {
	return enemies.begin();
}
std::list<Enemy*>::iterator ObjectStorage::get_enemies_end() {
	return enemies.end();
}

void ObjectStorage::remove_bullet(Bullet* bullet) {
	bullets.remove(bullet);
}

ObjectStorage::ObjectStorage (Game *game) : game(game) {
	bullets = *(new std::list<Bullet*>());
}
