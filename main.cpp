#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Participante.h"
#include "Robot.h"
#include "Equipo.h"
#include "Batalla.h"

using namespace std;

void registrarEquipo(Equipo& equipo)
{
    int cantidadParticipantes;

    cout << "\nRegistro del equipo: " << equipo.getNombre() << endl;

    cout << "Cuantos participantes tiene el equipo: ";
    cin >> cantidadParticipantes;

    cin.ignore();

    for (int i = 0; i < cantidadParticipantes; i++)
    {
        string nombre;
        string carrera;

        cout << "\nNombre del participante: ";
        getline(cin, nombre);

        cout << "Carrera: ";
        getline(cin, carrera);

        Participante participante(nombre, carrera);

        equipo.agregarParticipante(participante);
    }

    int cantidadRobots;

    cout << "\nCuantos robots tiene el equipo: ";
    cin >> cantidadRobots;

    cin.ignore();

    for (int i = 0; i < cantidadRobots; i++)
    {
        string nombre;
        string tipo;

        cout << "\nNombre del robot: ";
        getline(cin, nombre);

        cout << "Tipo de robot: ";
        getline(cin, tipo);

        Robot robot(nombre, tipo);

        equipo.agregarRobot(robot);
    }
}

void mostrarRegistro(vector<Equipo>& equipos)
{
    cout << "\n========== REGISTRO ==========\n";

    for (Equipo& equipo : equipos)
    {
        cout << "\nEquipo: " << equipo.getNombre() << endl;

        cout << "Participantes:\n";

        for (Participante& participante : equipo.getParticipantes())
        {
            cout << "- " << participante.getNombre()
                 << " - " << participante.getCarrera() << endl;
        }

        cout << "Robots:\n";

        for (Robot& robot : equipo.getRobots())
        {
            cout << "- " << robot.getNombre()
                 << " - " << robot.getTipo() << endl;
        }
    }
}

void iniciarCompetencia(vector<Equipo>& equipos)
{
    string tipos[] =
    {
        "sumo",
        "seguidor de linea",
        "laberinto",
        "velocista"
    };

    cout << "\n========== COMPETENCIA ==========\n";

    for (int t = 0; t < 4; t++)
    {
        string tipo = tipos[t];

        vector<Robot*> robotsDelTipo;

        for (Equipo& equipo : equipos)
        {
            for (Robot& robot : equipo.getRobots())
            {
                if (robot.getTipo() == tipo)
                {
                    robotsDelTipo.push_back(&robot);
                }
            }
        }

        cout << "\nDisciplina: " << tipo << endl;

        if (robotsDelTipo.size() == 0)
        {
            cout << "No hay robots registrados en esta disciplina." << endl;
        }
        else
        {
            for (int i = 0; i < robotsDelTipo.size(); i += 2)
            {
                if (i + 1 >= robotsDelTipo.size())
                {
                    cout << "El robot "
                         << robotsDelTipo[i]->getNombre()
                         << " no tiene rival." << endl;
                }
                else
                {
                    Batalla batalla(
                        *robotsDelTipo[i],
                        *robotsDelTipo[i + 1]
                    );

                    batalla.mostrarBatalla();
                }
            }
        }
    }
}

int main()
{
    srand(time(0));

    vector<Equipo> equipos;

    int cantidadEquipos;

    cout << "========== COMPETENCIA DE ROBOTICA ==========\n";

    cout << "Cuantos equipos se registraran: ";
    cin >> cantidadEquipos;

    cin.ignore();

    for (int i = 0; i < cantidadEquipos; i++)
    {
        string nombreEquipo;

        cout << "\nNombre del equipo: ";
        getline(cin, nombreEquipo);

        Equipo equipo(nombreEquipo);

        registrarEquipo(equipo);

        equipos.push_back(equipo);
    }

    mostrarRegistro(equipos);

    iniciarCompetencia(equipos);

    cout << "\n========== COMPETENCIA FINALIZADA ==========\n";

    return 0;
}