#include "../headers/LinearPushStrategy.h"

LinearPushStrategy::LinearPushStrategy(Game* game, std::list<Enemy*>* enemies)
				: PushStrategy(game, enemies)
{
	time_of_last_push = std::chrono::system_clock::now();

	float speed = 2;
	for (int i = 0; i < 9; ++i) {
		enemies->push_back( new_enemy(speed, 100) );
	}
	std::cout << "Utworzono push strategy" << std::endl;
}

bool LinearPushStrategy::can_push() {
	return time_of_last_push + time_beetwen_push < std::chrono::system_clock::now();
}

void LinearPushStrategy::push()
{
//	std::cout << "push" << std::endl;
	if(!passive_enemies->empty())
	{
		if (can_push())
		{
			std::cout << "can push" << std::endl;
			game->add_enemy(passive_enemies->back());
			std::cout << "enemy added" << std::endl;
			passive_enemies->pop_back();
			std::cout << "enemy pop_baked" << std::endl;
			time_of_last_push = std::chrono::system_clock::now();
			std::cout << "time reset" << std::endl;
		}
	}
}

void LinearPushStrategy::set_step(int step){
	this->step = step;
}

