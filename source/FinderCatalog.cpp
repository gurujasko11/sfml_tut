#include "../headers/FinderCatalog.h"


Enemy* FinderCatalog::template_finder(Turret* turret, std::function<bool(Enemy*,Enemy*)> comparator) {
	Enemy* result = NULL;
	std::list<Enemy*> enemies = turret->find_enemies_in_range();
	std::list<Enemy*>::iterator it = enemies.begin();
	while(it != enemies.end())
	{
		if(result == NULL)
			result = *it;
		else if(comparator(*it,result))
		{
			result = *it;
		}
		it++;
	}
	return result;
}

bool FinderCatalog::get_weaker (Enemy *e1, Enemy *e2) {
	return e1->getHp() < e2->getHp();
};

bool FinderCatalog::get_stronger (Enemy *e1, Enemy *e2) {
	return e1->getHp() > e2->getHp();
}

bool FinderCatalog::get_further (Turret *turret, Enemy *e1, Enemy *e2) {
	return e1->get_distance_from(&(turret->shape)) > e2->get_distance_from(&(turret->shape));
};

bool FinderCatalog::get_closer (Turret *turret, Enemy *e1, Enemy *e2) {
	return e1->get_distance_from(&(turret->shape)) < e2->get_distance_from(&(turret->shape));
}

Enemy *FinderCatalog::closest_enemy_finder (Turret *turret) {
	using namespace std::placeholders;
	return FinderCatalog::template_finder(turret, std::bind(&FinderCatalog::get_closer, turret, _1, _2));
};

Enemy *FinderCatalog::farrest_enemy_finder (Turret *turret) {
	using namespace std::placeholders;
	return FinderCatalog::template_finder(turret, std::bind(&FinderCatalog::get_further, turret, _1, _2));
};

Enemy *FinderCatalog::weakest_enemy_finder (Turret *turret) {
	return FinderCatalog::template_finder(turret, &FinderCatalog::get_weaker);
};

Enemy *FinderCatalog::strongest_enemy_finder (Turret *turret) {
	return FinderCatalog::template_finder(turret, &FinderCatalog::get_stronger);
};
