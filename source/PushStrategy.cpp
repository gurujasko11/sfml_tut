#include "../headers/PushStrategy.h"

PushStrategy::PushStrategy(Game* game, std::list<Enemy*>* enemies) : game(game), passive_enemies(enemies){};

bool PushStrategy::is_done(){
	return passive_enemies->empty();
}
