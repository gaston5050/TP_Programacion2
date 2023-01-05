#include <iostream>
#include "../include/Estudiante.h"
#include "../include/Fecha.h"


    void Estudiante::setNombre(std::string nombre) { _nombre = nombre;}

    void Estudiante::setApellido(std::string apellido){ _apellido = apellido;}

    void Estudiante::setFechaNac (int d, int m, int a){ _fechaNac.setDia(d);
                                            _fechaNac.setMes(m);
                                            _fechaNac.setAnio(a);
                                            }
    void Estudiante::setLegajo(int legajo) { _legajo = legajo ;}


    std::string Estudiante::getNombre(){return _nombre;}
    std::string Estudiante::getApellido(){ return _apellido;}
    int Estudiante::getLegajo() {return _legajo;}
    Fecha Estudiante::getFecha() {return _fechaNac;}


    int Estudiante::getEdad(){
        Fecha aux;

        int dia = this->getFecha().getDia();
        int mes = this->getFecha().getMes();
        int anio = this->getFecha().getAnio();
        int edad;

        edad = aux.getAnio() - anio;

        if(mes > aux.getMes()) {return edad;}
        if(mes == aux.getMes()&& dia >= aux.getDia()) { return edad +1;}
        else return edad;




    }
