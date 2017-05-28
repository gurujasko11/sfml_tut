#ifndef SFML_TUT_MOVABLE_H
#define SFML_TUT_MOVABLE_H

#include <SFML/Graphics/Shape.hpp>

class Movable {
public:
		virtual void move() = 0;
		virtual sf::Shape* get_shape() = 0;
		virtual ~Movable();
};
#endif //SFML_TUT_MOVABLE_H
