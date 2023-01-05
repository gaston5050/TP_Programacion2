#include <iostream>
#include <string>
#include <ctime>
#include "../include/Fecha.h"

    Fecha::Fecha(){

     time_t now =time(NULL); //variables donde guardo el valor de la funcion time
     struct tm *tlocal = localtime(&now);//estructura donde obtengo el tiempo

            _dia = tlocal->tm_mday;
            _mes = tlocal ->tm_mon+1;
            _anio = tlocal->tm_year + 1900;


    }

    Fecha::Fecha(int dia, int mes, int anio){

    if(!(_dia < 0 || dia >31 || mes < 0 || mes > 12 || anio < 0)){
    _dia = dia;
    _mes = mes;
    _anio = anio;
    }
    else {
    _dia = 0;
    _mes = 0;
    _anio = 0;


    }


    }
    std::string Fecha::toString(){

        std::string fecha  = std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);

        return fecha;



    }

    void Fecha::setDia(int dia){_dia = dia;}
    void Fecha::setMes(int mes){_mes = mes;}
    void Fecha::setAnio(int anio){_anio = anio;}

    int Fecha::getDia(){return _dia;}
    int Fecha::getMes(){return _mes;}
    int Fecha::getAnio(){return _anio;}
