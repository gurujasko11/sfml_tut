#ifndef SFML_TUT_FINDERCATALOG_H
#define SFML_TUT_FINDERCATALOG_H

#include "Turret.h"
#include "Enemy.h"

class FinderCatalog {
public:
		static Enemy* default_finder(Turret* turret);
};
#endif //SFML_TUT_FINDERCATALOG_H
