#ifndef ROBOT_H
#define ROBOT_H

#include <string>
using namespace std;

class Robot 
{
private:
    string nombre;
    string tipo; 

public:
    Robot(); // <--- Esta es la línea clave que faltaba
    Robot(string n, string t); 

    string getNombre(); 
    string getTipo(); 
}; 

#endif