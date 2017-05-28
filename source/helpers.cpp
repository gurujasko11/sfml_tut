
Enemy* new_enemy(float speed = 2, int hp = 100){
    sf::Texture* nmTexture = (new sf::Texture());
    nmTexture->loadFromFile("res/nmy1.png");
    sf::CircleShape* nm = (new sf::CircleShape(16));
    nm->setTexture(nmTexture);
    return new Enemy(nm, speed, hp);
}