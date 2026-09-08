#include "Robot.h"

Robot::Robot() // <--- Implementación del constructor vacío
{
    nombre = "";
    tipo = "";
}

Robot::Robot(string n, string t)
{
    nombre = n;
    tipo = t;
}

string Robot::getNombre()
{
    return nombre;
}

string Robot::getTipo()
{
    return tipo;
}