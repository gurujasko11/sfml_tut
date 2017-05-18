#include "../headers/Cell.h"


Cell::Cell(Cell_type cell_type, sf::RectangleShape& shape)
				: cell_type(cell_type), shape(shape) {}

Cell::Cell(){}
