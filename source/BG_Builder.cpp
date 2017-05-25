#include <iostream>
#include "../headers/BG_Builder.h"
#include "../headers/Enemy.h"

BG_Builder::BG_Builder()
{
	path = std::list<std::pair<int,int>>();
}

BG_Builder::BG_Builder(std::list<std::pair<int,int>>& path) : path(path) {}

void BG_Builder::add_point(int x, int y) {
	path.push_back(std::pair<int,int>(x,y));
}

Background BG_Builder::build(sf::Texture& rdTexture, sf::Texture& bgTexture, sf::Texture& fnTexture)
{
	Cell matrix[16][16];
	for(int x = 0; x < BG_X; ++x)
	{
		for(int y = 0; y < BG_Y; ++y)
		{
			sf::RectangleShape bg_shape(sf::Vector2<float>(32,32));
			bg_shape.setTexture(&bgTexture);
			bg_shape.setPosition(sf::Vector2f(x*cell_size,y*cell_size));
			matrix[x][y] = *(new Cell(Cell::BACKGROUND,bg_shape));

		}
	}

	//2
	std::list<std::pair<int, int> >::iterator it = path.begin();
	std::pair<int,int> point1 = *(it);
	std::pair<int,int> point2 = *(it);
//	Enemy::targets.push_back(new sf::RectangleShape(sf::Vector2f(point2.first,point2.second)));
	for(; it != path.end() ; it++)
	{
		point1 = point2;
		point2 = *(it);
		while(point1.first != point2.first || point1.second != point2.second)
		{
			sf::RectangleShape rd_shape(sf::Vector2<float>(32,32));
			rd_shape.setTexture(&rdTexture);
			rd_shape.setPosition(sf::Vector2f(point1.first*cell_size,point1.second*cell_size));
			matrix[point1.first][point1.second] = *(new Cell(Cell::ROAD,rd_shape));
			if(point1.first == point2.first)
			{
				//xs are the same
				if(point1.second < point2.second)
				{
					point1.second++;
				}
				else
				{
					point1.second--;
				}
			}
			else
			{
				//ys are the same
				if(point1.first < point2.first)
				{
					point1.first++;
				}
				else
				{
					point1.first--;
				}
			}
		}
		sf::RectangleShape rd_shape(sf::Vector2<float>(32,32));
		rd_shape.setTexture(&fnTexture);
		rd_shape.setPosition(sf::Vector2f(point2.first*cell_size,point2.second*cell_size));
		matrix[point2.first][point2.second] = *(new Cell(Cell::ROAD,rd_shape));
		Enemy::targets.push_back(new sf::RectangleShape(rd_shape));
	}

	return Background(matrix);
}
