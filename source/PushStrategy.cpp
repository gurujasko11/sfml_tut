#include "../headers/PushStrategy.h"

PushStrategy::PushStrategy(Level* level, std::list<Enemy*>* enemies) : level(level), passive_enemies(enemies){};

bool PushStrategy::is_done(){
	return passive_enemies->empty();
}
