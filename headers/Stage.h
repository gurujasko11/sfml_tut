#ifndef SFML_TUT_STAGE_H
#define SFML_TUT_STAGE_H

#include "Background.h"
#include "Turret.h"
#include "Level.h"

class Stage {
public:
		Background background;
		std::list<Turret*> turrets;
		std::list<Level*> levels;
		std::list<Level*>::iterator level;
		sf::RenderWindow* window;

		bool add_turret(Turret* turret, int x, int y);

		void handle_turrets();
		void draw_turrets();

		void draw_background();

		void move_level();
		void draw_level();

		bool is_level_active();
		Level* get_level();

		Stage(sf::RenderWindow* window);


};
#endif //SFML_TUT_STAGE_H
