#include "../headers/WavyPushStrategy.h"
#include "helpers.cpp"

WavyPushStrategy::WavyPushStrategy(Game* game, std::list<Enemy*>* enemies)
        : PushStrategy(game, enemies)
{
    time_of_last_push = std::chrono::system_clock::now();

    float speed = 2;
    for (int i = 0; i < 15; ++i) {
        enemies->push_back( new_enemy(speed, 100) );
    }
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

