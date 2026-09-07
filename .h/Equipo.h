#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include <vector>
#include "Participante.h"
#include "Robot.h"

using namespace std;

class Equipo
{
private:
    string nombre;
    vector<Participante> participantes;
    vector<Robot> robots;

public:
    Equipo(string n);

    void agregarParticipante(Participante participante);
    void agregarRobot(Robot robot);

    string getNombre();
    vector<Participante>& getParticipantes();
    vector<Robot>& getRobots();
};

#endif