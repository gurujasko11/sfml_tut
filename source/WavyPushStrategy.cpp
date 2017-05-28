#include "../headers/WavyPushStrategy.h"

WavyPushStrategy::WavyPushStrategy(Game* game, std::list<Enemy*>* enemies)
        : PushStrategy(game, enemies)
{
    time_of_last_push = std::chrono::system_clock::now();

    sf::Texture* nmTexture = (new sf::Texture());
    nmTexture->loadFromFile("res/nmy1.png");

    sf::CircleShape* nm1 = (new sf::CircleShape(16));
    sf::CircleShape* nm2 = (new sf::CircleShape(16));
    sf::CircleShape* nm3 = (new sf::CircleShape(16));
    sf::CircleShape* nm4 = (new sf::CircleShape(16));
    sf::CircleShape* nm5 = (new sf::CircleShape(16));
    sf::CircleShape* nm6 = (new sf::CircleShape(16));
    sf::CircleShape* nm7 = (new sf::CircleShape(16));
    sf::CircleShape* nm8 = (new sf::CircleShape(16));
    sf::CircleShape* nm9 = (new sf::CircleShape(16));

    nm1->setTexture(nmTexture);
    nm2->setTexture(nmTexture);
    nm3->setTexture(nmTexture);
    nm4->setTexture(nmTexture);
    nm5->setTexture(nmTexture);
    nm6->setTexture(nmTexture);
    nm7->setTexture(nmTexture);
    nm8->setTexture(nmTexture);
    nm9->setTexture(nmTexture);

    float speed = 2;
    enemies->push_back(new Enemy(nm1, speed, 100));
    enemies->push_back(new Enemy(nm2, speed, 100));
    enemies->push_back(new Enemy(nm3, speed, 100));
    enemies->push_back(new Enemy(nm4, speed, 100));
    enemies->push_back(new Enemy(nm5, speed, 100));
    enemies->push_back(new Enemy(nm6, speed, 100));
    enemies->push_back(new Enemy(nm7, speed, 100));
    enemies->push_back(new Enemy(nm8, speed, 100));
    enemies->push_back(new Enemy(nm9, speed, 100));
    std::cout << "Utworzono push strategy" << std::endl;
}

bool WavyPushStrategy::can_push() {
    return time_of_last_push +
            (is_wave_next ? time_beetwen_waves : time_beetwen_push)
                                                       < std::chrono::system_clock::now();
}

void WavyPushStrategy::push()
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
            is_wave_next = ++pushed % enemies_in_wave == 0;
        }
    }
}

//void WavyPushStrategy::set_step(int step){
//    this->step = step;
//}

