#include "FinderCatalog.h"

Enemy* FinderCatalog::default_finder(Turret* turret) {
			Enemy* result = NULL;
			std::list<Enemy*> enemies = turret->find_enemies_in_range();
			std::list<Enemy*>::iterator it = enemies.begin();
			while(it != enemies.end())
			{
				if((*(it))->get_distance_from(&(turret->shape)) < turret->range)
				{
					if(result == NULL
					   ||
					   (*(it))->get_distance_from(&(turret->shape)) < result->get_distance_from(&(turret->shape)))
					{
						result = *it;
					}
				}
				it++;
			}
			return result;
	};
