#include "../headers/Enemy.h"
#include "../headers/Turret.h"
#include "../headers/ObjectStorage.h"

void ObjectStorage::add_enemy (Enemy* enemy) {
	enemies.push_back(enemy);
}
void ObjectStorage::add_turrets(Turret* turret) {
	turrets.push_back(turret);
}
void ObjectStorage::add_bullet(Bullet* bullet) {
	bullets.push_back(bullet);
}

std::list<Enemy*>::iterator ObjectStorage::get_enemies_begin() {
	return enemies.begin();
}
std::list<Enemy*>::iterator ObjectStorage::get_enemies_end() {
	return enemies.end();
}

std::list<Turret*>::iterator ObjectStorage::get_turrets_begin() {
	return turrets.begin();
}
std::list<Turret*>::iterator ObjectStorage::get_turrets_end() {
	return turrets.end();
}

std::list<Bullet*>::iterator ObjectStorage::get_bullets_begin() {
	return bullets.begin();
}
std::list<Bullet*>::iterator ObjectStorage::get_bullets_end() {
	return bullets.end();
}
void ObjectStorage::remove_bullet(Bullet* bullet) {
	bullets.remove(bullet);
}

std::list<Enemy*> ObjectStorage::get_enemy_in_range(sf::Shape* shape, float range) {
	std::list<Enemy*> result;
	for(std::list<Enemy*>::iterator i; i != enemies.end(); ++i) {
		if((*i)->get_distance_from(shape) < range)
			result.push_back(*i);
	}
	return result;
}
