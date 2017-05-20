#ifndef SFML_TUT_FINDERCATALOG_H
#define SFML_TUT_FINDERCATALOG_H

#include "Turret.h"
#include "Enemy.h"

class FinderCatalog {
public:
		static Enemy* closest_enemy_finder    (Turret* turret);
		static Enemy* farrest_enemy_finder   (Turret *turret);
		static Enemy* weakest_enemy_finder   (Turret *turret);
		static Enemy* strongest_enemy_finder (Turret *turret);

		static Enemy *template_finder (Turret* turret, std::function<bool(Enemy*, Enemy*)> comparator);

		static bool get_closer(Turret *turret, Enemy* e1,   Enemy* e2);
		static bool get_further(Turret *turret, Enemy* e1,  Enemy* e2);
		static bool get_weaker(Enemy* e1,   Enemy* e2);
		static bool get_stronger(Enemy* e1, Enemy* e2);

};
#endif //SFML_TUT_FINDERCATALOG_H
