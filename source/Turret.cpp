#include "../headers/Turret.h"


Turret::Turret()
{
	Turret::find_target = [this](std::list<Enemy*> enemies) ->
				Enemy* {
						Enemy* result = NULL;
						std::list<Enemy*>::iterator it = enemies.begin();
						while(it != enemies.end())
						{
							if((*(it))->get_distance_from(&shape) < range)
							{
								if(result == NULL
												||
												(*(it))->get_distance_from(&shape) < result->get_distance_from(&shape))
								{
									result = *it;
								}
							}
							it++;
						}
						return result;
				};
}


Turret::Turret(Cell_type cell_type, sf::RectangleShape* shape, int range)
				: Cell(cell_type, shape),
				  range(range)
{
	Turret::find_target = [this](std::list<Enemy*> enemies) ->
					Enemy* {
			Enemy* result = NULL;
			std::list<Enemy*>::iterator it = enemies.begin();
			while(it != enemies.end())
			{
				if((*(it))->get_distance_from(&(this->shape)) < this->range)
				{
					if(result == NULL
					   ||
					   (*(it))->get_distance_from(&(this->shape)) < result->get_distance_from(&(this->shape)))
					{
						result = *it;
					}
				}
				it++;
			}
			return result;
	};
}
