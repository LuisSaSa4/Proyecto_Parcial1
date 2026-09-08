#include "Equipo.h"

Equipo::Equipo(string n)
{
    nombre = n;
}

void Equipo::agregarParticipante(Participante participante)
{
    participantes.push_back(participante);
}

void Equipo::agregarRobot(Robot robot)
{
    robots.push_back(robot);
}

string Equipo::getNombre()
{
    return nombre;
}

vector<Participante>& Equipo::getParticipantes()
{
    return participantes;
}

vector<Robot>& Equipo::getRobots()
{
    return robots;
}