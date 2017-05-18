#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>

class Cell
{
public:
		enum Cell_type
		{
				BACKGROUND,
				ROAD,
				TURRET
		} cell_type;

		sf::RectangleShape shape;

		Cell(Cell_type cell_type, sf::RectangleShape& shape);
		Cell();
};
#endif //CELL_H
