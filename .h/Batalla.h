#ifndef BATALLA_H
#define BATALLA_H

#include "Robot.h"

class Batalla
{
private:
    Robot robot1;
    Robot robot2;
    Robot ganador;

public:
    Batalla(Robot r1, Robot r2);

    void mostrarBatalla();
};

#endif