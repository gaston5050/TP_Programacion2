#include <iostream>
#include <iomanip>
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



void Estudiante::cargarEstudiante(){


std::string nombre, apellido;
int legajo, dia, mes, anio;


std::cout<< " INGRESE LEGAJO ESTUDIANTE: " <<std::endl;
std::cin>>legajo;

while(legajo != 0){

std::cout<< " INGRESE APELLIDO ESTUDIANTE: " <<std::endl;
std::cin>>apellido;
std::cout<< " INGRESE NOMBRE ESTUDIANTE: " <<std::endl;
std::cin>>nombre;
std::cout<< " DIA NAC: " <<std::endl;
std::cin>>dia;
std::cout<< " MES NAC: " <<std::endl;
std::cin>>mes;
std::cout<< " DIA ANIO: " <<std::endl;
std::cin>>anio;


this->setApellido(apellido);
this->setNombre(nombre);
this->setLegajo(legajo);
this->setFechaNac(dia,mes, anio);

this->guardarEnDisco();

std::cout<< " INGRESE LEGAJO ESTUDIANTE: " <<std::endl;
std::cin>>legajo;
}
}


bool Estudiante::guardarEnDisco(){


FILE *p = fopen("estudiantes.gas", "ab");
if(p == NULL) return false;

bool escribio = fwrite(this, sizeof (Estudiante),1, p);

fclose(p);

return escribio;

}

bool Estudiante::listarEstudiantes(){

FILE *p= fopen("estudiantes.gas", "rb");
if(p== NULL) return false;

std::cout<< std::setw(10) << "LEGAJO";
std::cout<< std::setw(15) << "APELLIDO";
std::cout<< std::setw(15) << "NOMBRE";
std::cout<< std::setw(15) << "FECHANAC";

std::cout<<std::endl;
std::cout<<std::endl;

while(fread(this,sizeof(Estudiante), 1, p)){



    std::cout<< std::setw(10)<< this->getLegajo();
   std::cout<< std::setw(15)<< this->getNombre();
    std::cout<< std::setw(15)<< this->getApellido();
   std::cout<< std::setw(15)<<  this->getFecha().toString();
std::cout<<std::endl;

}

std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;







}


/*
1000
Southgate
Peg
10
2
2000
1001
O'Luney
Reinwald
11
11
1995
1002
Thorwarth
Frederic
23
8
1998
1003
Anthes
Rurik
5
10
1987
1004
Vernay
Gare
27
12
1986
1005
Ferier
Viviyan
2
7
1993
1006
Beardsall
Korie
24
8
1986
1007
Tamburo
Steve
29
10
1989
1008
Swainsbury
Vivianna
15
9
1998
1009
Coule
Candis
24
5
1995
1010
Manford
Lucretia
4
1
1999
1011
Lansberry
Belita
4
7
1992
1012
Yong
Hardy
10
4
1989
1013
Fleming
Demeter
17
12
1987
1014
Gauchier
Mac
25
5
1995
1015
Overal
Kalindi
20
9
1998
1016
Christie
Kort
27
6
1987
1017
Iggulden
Norby
25
8
1992
1018
Bedminster
Allsun
8
12
1999
1019
Spinley
Dotti
27
2
1996
1020
Oliva
Perry
4
5
1994
1021
Kienl
Gaspar
12
7
1995
1022
Sent
Cherida
6
6
1987
1023
Woolham
Byran
23
11
1988
1024
Howen
Theodore
13
3
1992
1025
Haps
Jakob
3
7
1986
1026
Kinsett
Pinchas
24
3
1997
1027
Wetherill
Jobye
26
11
1988
1028
Flegg
Alice
24
1
1998
1029
Massinger
Flora
5
7
1998
1030
Tomkiss
Emmy
6
2
1997
1031
Camsey
Juliane
26
8
1998
1032
Brankle
Zac
23
7
1991
1033
Thomson
Cam
29
7
1990
1034
Besset
Cassey
6
7
1998
1035
Topham
Dimitry
23
10
1999
1036
O'Doherty
Felice
12
8
1991
1037
Burbidge
Anica
3
7
1997
1038
Nussii
Neal
29
6
1992
1039
Bilbrook
Jeanne
26
8
1987
*/
