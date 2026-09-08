#include "Participante.h"

Participante::Participante(string n, string c)
{
    nombre = n;
    carrera = c;
}

string Participante::getNombre()
{
    return nombre;
}

string Participante::getCarrera()
{
    return carrera;
}