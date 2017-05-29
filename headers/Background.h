#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include "Cell.h"
#include <list>

class Background
{
public:
		Background(Cell* matrix[16][16]);

		Background ();

		void draw_bg(sf::RenderWindow& window);
		Cell* BG_matrix[16][16];
};
#endif //BACKGROUND_H
