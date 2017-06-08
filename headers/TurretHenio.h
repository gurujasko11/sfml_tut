#ifndef SFML_TUT_TURRETHENIO_H
#define SFML_TUT_TURRETHENIO_H

#include "Turret.h"

class TurretHenio : public Turret{
public:
    int counter = 0;
    int step = 0;

    TurretHenio(Cell_type cell_type, sf::RectangleShape* shape, int range, int damage,Color color = Color::NONE, int lvl=1, int step=10);
    void shoot() override;
};
#endif //SFML_TUT_TURRETHENIO_H
