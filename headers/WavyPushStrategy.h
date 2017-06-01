//
// Created by busz on 28.05.17.
//

#ifndef SFML_TUT_WAVYPUSHSTRATEGY_H
#define SFML_TUT_WAVYPUSHSTRATEGY_H

#include "PushStrategy.h"
#include "Enemy.h"
#include "GlobalVariables.h"
#include <iostream>
#include <chrono>

class WavyPushStrategy : public PushStrategy{
public:
    WavyPushStrategy(Level* level, std::list<Enemy*>* enemies = new std::list<Enemy*>() );
    bool can_push();
    void set_step(int step);
    void push() override;

private:
    int wave_step = 10;
    int push_step = 5;
    std::chrono::milliseconds time_beetwen_push = std::chrono::milliseconds(10000 * push_step)/fps;
    std::chrono::milliseconds time_beetwen_waves = std::chrono::milliseconds(10000 * wave_step)/fps;
    std::chrono::time_point<std::chrono::system_clock> time_of_last_push;
    int enemies_in_wave = 4;
    int pushed = 0;
    bool is_wave_next = false;
};

#endif //SFML_TUT_WAVYPUSHSTRATEGY_H
