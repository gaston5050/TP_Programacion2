#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "Fecha.h"

class Estudiante{

private:
    std::string _nombre;
    std::string _apellido;
    Fecha _fechaNac;
    int _legajo;

public:

    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setFechaNac (int d, int m, int a);
    void setLegajo(int legajo);


    std::string getNombre();
    std::string getApellido();
    int getLegajo();
    Fecha getFecha();
    int getEdad();


};

#endif // ESTUDIANTE_H_INCLUDED
