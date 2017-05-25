#ifndef SFML_TUT_PUSHSTRATEGY_H
#define SFML_TUT_PUSHSTRATEGY_H
#include "Enemy.h"
#include "Game.h"

class PushStrategy{
public:
		PushStrategy(Game* game, std::list<Enemy*>* enemies );
		bool is_done();
		virtual void push() = 0;

		//private:
		std::list<Enemy*>* passive_enemies;
		Game* game;
};
#endif //SFML_TUT_PUSHSTRATEGY_H
