
#include "../headers/Enemy.h"

Enemy *new_enemy (float speed, int hp, Color color=Color::NONE) {
    sf::Texture* nmTexture = (new sf::Texture());
    switch (color) {
        case NONE:
            nmTexture->loadFromFile("res/nmy1.png");
        break;
        case BLUE:
            nmTexture->loadFromFile("res/nmy2.png");
        break;
        case RED:
            nmTexture->loadFromFile("res/nmy3.png");
        break;
        case GREEN:
            nmTexture->loadFromFile("res/nmy4.png");
        break;
    }
//    nmTexture->loadFromFile("res/nmy1.png");
    sf::CircleShape* nm = (new sf::CircleShape(16));
    nm->setTexture(nmTexture);
    return new Enemy(nm, speed, hp, color);
}
