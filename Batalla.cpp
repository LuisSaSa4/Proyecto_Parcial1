#include <iostream>
#include <cstdlib>
#include "Batalla.h"

using namespace std;

Batalla::Batalla(Robot r1, Robot r2)
{
    robot1 = r1;
    robot2 = r2;

    int resultado = rand() % 2;

    if (resultado == 0)
    {
        ganador = robot1;
    }
    else
    {
        ganador = robot2;
    }
}

void Batalla::mostrarBatalla()
{
    cout << robot1.getNombre() << " VS " << robot2.getNombre() << endl;
    cout << "Ganador: " << ganador.getNombre() << endl;
}