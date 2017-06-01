#ifndef SFML_TUT_PUSHSTRATEGY_H
#define SFML_TUT_PUSHSTRATEGY_H
#include "Enemy.h"

class Level;

class PushStrategy{
public:
		PushStrategy(Level* level, std::list<Enemy*>* enemies );
		bool is_done();
		virtual void push() = 0;

		//private:
		std::list<Enemy*>* passive_enemies;
		Level* level;
};
#endif //SFML_TUT_PUSHSTRATEGY_H
