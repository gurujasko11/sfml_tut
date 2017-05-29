#include "../headers/Cell.h"
#include "../headers/Background.h"

Background::Background(Cell* matrix[16][16])
{
	for(int x = 0; x < 16; ++x)
	{
		for(int y = 0; y < 16; ++y)
		{
			BG_matrix[x][y] = matrix[x][y];
		}
	}
}

void Background::draw_bg(sf::RenderWindow& window)
{
	for(int x = 0; x < 16; ++x)
	{
		for(int y = 0; y < 16; ++y)
		{
			window.draw(*(BG_matrix[x][y]->shape));
		}
	}
}

Background::Background () {}
