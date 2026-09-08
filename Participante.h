#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <string>
using namespace std;

class Participante
{
private:
    string nombre;
    string carrera;

public:
    Participante(string n, string c);

    string getNombre();
    string getCarrera();
};

#endif