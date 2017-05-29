#include "../headers/Stage.h"
#include "../headers/Kieszonka.h"
bool Stage::add_turret(Turret* turret, int x, int y) {
	if(background.BG_matrix[x][y]->cell_type != Cell::Cell_type::BACKGROUND)
		return false;
	turret->shape->setPosition(sf::Vector2f(x * cell_size,y * cell_size));
	background.BG_matrix[x][y] = turret;
	background.BG_matrix[x][y]->cell_type = Cell::Cell_type ::TURRET;//TODO, konstruktor turreta powinien to ustawiac, teraz jest spierdolone a nie zrobione
	turrets.push_back(turret);
}

void Stage::handle_turrets() {
	for(std::list<Turret*>::iterator it = turrets.begin();it != turrets.end();it++)
		(*it)->move();
}
void Stage::draw_turrets() {
	for(std::list<Turret*>::iterator it = turrets.begin();it != turrets.end(); it++)
		window -> draw(*(*it)->get_shape());
}

void Stage::draw_background() {
	background.draw_bg(*window);
}

void Stage::move_level() {
	(*level)->move_bullets();
	(*level)->clean_enemies();
	(*level)->move_enemies();
}
void Stage::draw_level() {
	(*level)->draw_bullets();
	(*level)->draw_enemies();
}

bool Stage::is_level_active() {
	if(level == levels.end())
		return false;
	if((*level)->enemies.empty() && (*level)->pushStrategy->is_done())
		return false;
	return true;
}
Level* Stage::get_level() {
	return *level;
}


Stage::Stage(sf::RenderWindow* window) :window(window){
	background = get_background1();
}
