#include "../headers/LinearPushStrategy.h"

LinearPushStrategy::LinearPushStrategy(Game* game, std::list<Enemy*>* enemies)
				: PushStrategy(game, enemies)
{
	time_of_last_push = std::chrono::system_clock::now();

	sf::Texture* nmTexture = (new sf::Texture());
	nmTexture->loadFromFile("res/nmy1.png");

	sf::CircleShape* nm1 = (new sf::CircleShape(16));
	sf::CircleShape* nm2 = (new sf::CircleShape(16));
	sf::CircleShape* nm3 = (new sf::CircleShape(16));
	sf::CircleShape* nm4 = (new sf::CircleShape(16));

	nm1->setTexture(nmTexture);
	nm2->setTexture(nmTexture);
	nm3->setTexture(nmTexture);
	nm4->setTexture(nmTexture);

	float speed = 0.2;
	enemies->push_back(new Enemy(nm1, speed, 100));
	enemies->push_back(new Enemy(nm2, speed, 100));
	enemies->push_back(new Enemy(nm3, speed, 100));
	enemies->push_back(new Enemy(nm4, speed, 100));
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

