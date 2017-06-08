#ifndef SFML_TUT_GLOBALVARIABLES_H
#define SFML_TUT_GLOBALVARIABLES_H
#include<SFML/Graphics/Texture.hpp>
#include "Score.h"
#include "Hp.h"

static int fps       = 100;
static int cell_size = 32;

static float turrets_ui_row_x = 512;
static float turrets_ui_row_y = 80;
static int turrets_ui_cell_size = 80;

static float next_wave_pos_x = 512;
static float next_wave_pos_y = 512-80;

static float next_wave_size_x = 320;
static float next_wave_size_y = 80;

static sf::Font* font = new sf::Font();

static Score* score = Score::getInstance();

static Hp* game_hp = Hp::getInstance();

static int turret_cost1 = 10;
static int turret_cost2 = 20;
static int turret_cost3 = 30;
static int turret_cost4 = 40;



#endif //SFML_TUT_GLOBALVARIABLES_H
