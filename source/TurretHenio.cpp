#include "../headers/TurretHenio.h"


TurretHenio::TurretHenio(Cell_type cell_type, sf::RectangleShape* shape, int range, int damage,Color color, int lvl, int step)
        : Turret(cell_type, shape, range, damage, color, lvl), step(step){}

void TurretHenio::shoot(){
    if(counter == step)
        (this->time_beetwen_shot) /= 2;

    if(counter == 2*step) {
        (this->time_beetwen_shot) *= 2;
        counter = 0;
    }
    counter++;
    std::cout << counter << std::endl;
    std::cout << (this->Turret::time_beetwen_shot).count() << std::endl;
    Turret::shoot();
}

