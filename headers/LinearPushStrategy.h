#ifndef SFML_TUT_LINEARPUSHSTRATEGY_H
#define SFML_TUT_LINEARPUSHSTRATEGY_H

#include "PushStrategy.h"
#include "Enemy.h"
#include <iostream>
#include <chrono>

class LinearPushStrategy : public PushStrategy{
public:
		LinearPushStrategy(Game* game, std::list<Enemy*>* enemies = new std::list<Enemy*>() );
		bool can_push();
		void push() override;

private:
		std::chrono::duration<int> time_beetwen_push = std::chrono::duration<int>(1);
		std::chrono::time_point<std::chrono::system_clock> time_of_last_push;
};

#endif //SFML_TUT_LINEARPUSHSTRATEGY_H
