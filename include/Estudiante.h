#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include "Fecha.h"

class Estudiante{

private:
     char _nombre[50]{};
     char _apellido[50]{};
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


    bool guardarEnDisco();
    std::string toString();

void cargarEstudiante();
bool listarEstudiantes();
bool leerEstudianteX(int posicion);
bool modificarEstudiante(int legajo);

};


int cantidad_registros_estudiantes();
int cantidadEstudiantes();
bool aproboMas2(int legajo);
bool leerArchivoEstudiantes();
 void reporteA();


#endif // ESTUDIANTE_H_INCLUDED
