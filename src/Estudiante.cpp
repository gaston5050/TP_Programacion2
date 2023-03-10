#include <cstring>
#include <iostream>
#include <iomanip>
#include "../include/Fecha.h"
#include "../include/Estudiante.h"
#include "../include/Examen.h"


void Estudiante::setNombre(std::string nombre)
{
    strcpy(_nombre,nombre.c_str() );
   // _nombre = nombre;
}

void Estudiante::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
    //_apellido = apellido;
}

void Estudiante::setFechaNac (int d, int m, int a)
{
    _fechaNac.setDia(d);
    _fechaNac.setMes(m);
    _fechaNac.setAnio(a);
}
void Estudiante::setLegajo(int legajo)
{
    _legajo = legajo ;
}


std::string Estudiante::getNombre()
{
    std::string nombre;
    nombre = _nombre;
    return nombre;
}
std::string Estudiante::getApellido()
{
    std::string apellido (_apellido);
    return apellido;
}
int Estudiante::getLegajo()
{
    return _legajo;
}
Fecha Estudiante::getFecha()
{
    return _fechaNac;
}


int Estudiante::getEdad()
{
    Fecha aux;

    int dia = this->getFecha().getDia();
    int mes = this->getFecha().getMes();
    int anio = this->getFecha().getAnio();
    int edad;

    edad = aux.getAnio() - anio;

    if(mes > aux.getMes())
    {
        return edad;
    }
    if(mes == aux.getMes()&& dia >= aux.getDia())
    {
        return edad +1;
    }
    else return edad;

}
void Estudiante::cargarEstudiante()
{


    std::string nombre, apellido;
    int legajo, dia, mes, anio;


    std::cout<< " INGRESE LEGAJO ESTUDIANTE: " <<std::endl;
    std::cin>>legajo;

    while(legajo != 0)
    {

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

bool Estudiante::leerEstudianteX(int posicion){

        FILE *p = fopen("estudiantes.gas","rb");
        if(p == NULL){ return false;}

        fseek(p, sizeof(Estudiante) * posicion, SEEK_SET);
        bool leyo = fread(this, sizeof (Estudiante), 1,p);
        fclose(p);
        return leyo;


}
bool Estudiante::guardarEnDisco()
{


    FILE *p = fopen("estudiantes.gas", "ab");
    if(p == NULL) return false;

    bool escribio = fwrite(this, sizeof (Estudiante),1, p);

    fclose(p);

    return escribio;

}

bool Estudiante::listarEstudiantes()
{

    FILE *p= fopen("estudiantes.gas", "rb");
    if(p== NULL) return false;

    std::cout<< std::setw(10) << "LEGAJO";
    std::cout<< std::setw(15) << "APELLIDO";
    std::cout<< std::setw(15) << "NOMBRE";
    std::cout<< std::setw(15) << "FECHANAC";

    std::cout<<std::endl;
    std::cout<<std::endl;

    while(fread(this,sizeof(Estudiante), 1, p))
    {



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

std::string Estudiante::toString(){

    std::string texto;



    texto = " LEGAJO " + std::to_string(this->getLegajo()) + " NOMBRE " + this->getNombre() + " APELLIDO " + this->getApellido();

    return texto;

}







void reporteA()
{

        Estudiante aux;
        bool bandera = true;
        FILE *p = fopen("estudiantes.gas", "rb");
        if(p==NULL) return;

        while( fread(&aux, sizeof(Estudiante), 1, p)){


                if(aproboMas2(aux.getLegajo())){
                if(aproboMas2(aux.getLegajo())){

                   if(bandera){

    std::cout<< std::setw(10) << "LEGAJO";
    std::cout<< std::setw(15) << "APELLIDO";
    std::cout<< std::setw(15) << "NOMBRE";


    std::cout<<std::endl;

    bandera = false;


                  }
                    std::cout<< std::setw(10)<< aux.getLegajo();

        std::cout<< std::setw(15)<< aux.getNombre();
        std::cout<< std::setw(15)<< aux.getApellido();

        std::cout<<std::endl;







                   }


}



    }
}

 bool aproboMas2(int legajo){

 Examen reg;
 int contador = 0;
    Fecha hoy;


 FILE *p = fopen("examenes.dat", "rb");

 if (p == NULL) {return false;}

    while(fread(&reg, sizeof(Examen), 1,p)){

        if(reg.getLegajo()== legajo && reg.getCalificacion()<6&& reg.getFecha().getAnio() == 2022){


            contador++;
        }

    }

    if(contador >1 ) return true;
    else return false;



 }


int cantidad_registros_estudiantes(){
    FILE *p = fopen("estudiantes.gas", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(Estudiante);
    return cant_reg;

}



int cantidadEstudiantes(){

    FILE *p = fopen("estudiantes.gas", "rb");
    if (p == NULL )  return -2;

    fseek(p,0,SEEK_END);

        int num = ftell(p)/ sizeof(Estudiante);

        return num;

}

bool Estudiante::modificarEstudiante(int legajo){

    std::string nombre, apellido;
    int lega, dia, mes, anio;



    FILE *p = fopen("estudiantes.gas", "rb+");
    if (p== NULL)return false;
    int pos = 0;
    Estudiante aux;
    while(aux.leerEstudianteX(pos)){

        if (aux.getLegajo()== legajo){

            fseek(p, ftell(p)- sizeof(Estudiante) , SEEK_CUR);


         //   std::cout<< " INGRESE LEGAJO ESTUDIANTE: " <<std::endl;
  //  std::cin>>lega;


    {

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

       fwrite(this, sizeof(Estudiante),1,p);
       fclose(p);


        return true;

            }


        }


    }



    return true;

}

/*
1004
52
19
9
2020
8
1035
32
24
5
2018
5
1036
33
3
11
2021
3
1003
49
22
9
2016
8
1003
12
20
9
2020
10
1038
5
13
3
2022
9
1039
18
31
5
2019
8
1013
4
3
12
2018
7
1011
9
16
8
2016
10
1000
35
12
9
2018
2
1004
19
9
10
2018
3
1005
10
19
11
2016
1
1035
19
23
4
2018
7
1013
26
10
8
2021
1
1033
32
18
7
2015
7
1017
15
4
11
2019
7
1025
29
11
3
2018
4
1011
15
10
8
2021
3
1007
45
3
4
2022
5
1009
20
30
7
2021
8
1010
41
24
9
2020
9
1039
44
18
8
2021
2
1010
58
23
12
2016
4
1035
20
20
4
2016
3
1010
57
18
12
2018
10
1024
10
23
7
2021
6
1006
21
31
7
2018
8
1027
23
24
2
2022
6
1014
52
11
5
2017
4
1013
10
16
3
2018
6
1002
33
27
4
2020
9
1038
59
24
1
2017
6
1022
15
4
2
2018
8
1007
54
6
9
2020
5
1017
46
29
11
2017
5
1038
34
29
9
2021
1
1004
13
18
4
2021
10
1039
15
2
6
2020
5
1014
27
25
10
2018
1
1013
58
7
10
2020
3
1013
12
28
7
2016
1
1039
6
18
4
2016
7
1010
42
22
5
2018
10
1024
47
17
7
2019
10
1029
25
27
12
2019
9
1035
58
18
2
2016
1
1022
24
16
10
2017
9
1031
1
5
5
2017
8
1024
34
26
4
2019
5
1006
45
15
1
2021
2
1031
16
31
12
2016
8
1033
15
10
7
2017
9
1032
18
4
6
2020
4
1013
37
10
5
2016
8
1001
59
20
6
2020
9
1011
16
28
6
2017
4
1024
39
31
12
2021
2
1024
58
23
1
2020
4
1022
41
12
9
2018
4
1021
55
4
3
2019
9
1010
42
27
4
2022
2
1013
20
27
2
2020
10
1018
53
6
4
2022
2
1037
26
24
7
2017
8
1010
26
28
1
2020
3
1022
4
4
8
2020
3
1031
13
4
4
2016
3
1033
44
23
7
2017
10
1023
11
30
9
2016
3
1007
50
29
7
2019
6
1001
29
4
1
2017
3
1025
57
3
10
2021
5
1000
16
9
5
2021
7
1038
48
25
6
2020
3
1010
25
29
8
2021
9
1012
33
25
7
2021
5
1034
23
6
2
2018
1
1033
47
14
12
2020
9
1019
23
4
4
2020
8
1008
26
1
9
2021
10
1000
32
22
7
2020
6
1038
60
17
10
2017
2
1004
5
17
8
2016
2
1016
55
28
6
2021
5
1038
10
14
5
2017
10
1039
24
2
3
2019
7
1009
6
25
3
2016
10
1009
49
6
12
2017
10
1009
43
19
9
2017
9
1023
38
22
7
2021
8
1024
40
9
2
2017
8
1035
9
23
3
2021
2
1039
10
15
9
2019
5
1017
46
8
12
2021
1
1032
26
30
11
2020
2
1009
16
26
10
2015
8
1008
37
24
7
2016
1
1012
25
23
8
2021
10
1012
11
8
12
2016
9
1005
46
22
6
2018
2
1008
3
18
10
2016
5
1030
50
24
5
2017
2
1009
20
27
4
2016
5
1003
16
18
4
2016
7
1023
19
3
8
2020
7
1033
23
18
12
2019
5
1025
15
11
12
2015
8
1022
21
12
11
2018
9
1019
7
22
5
2016
9
1022
14
10
2
2018
7
1003
49
22
12
2020
8
1020
9
2
4
2021
5
1018
48
19
9
2017
8
1018
21
30
7
2017
5
1034
23
5
2
2019
8
1031
38
14
7
2015
1
1031
16
25
8
2016
4
1030
34
28
7
2021
6
1031
46
21
5
2019
1
1028
49
19
11
2020
3
1011
4
15
10
2020
1
1029
32
24
10
2017
6
1034
18
23
10
2018
6
1019
54
22
4
2017
4
1004
37
13
10
2019
4
1016
47
4
5
2017
2
1026
59
26
12
2015
5
1017
40
1
8
2021
4
1016
29
21
11
2016
9
1011
37
19
10
2019
5
1018
18
26
2
2016
10
1005
56
7
3
2018
6
1005
19
12
3
2020
5
1008
7
5
4
2016
10
1032
39
10
4
2021
8
1006
57
10
12
2015
1
1006
60
14
5
2017
5
1012
4
22
5
2015
6
1007
2
23
4
2022
7
1022
57
8
9
2021
7
1001
18
30
11
2017
9
1023
52
18
1
2022
1
1019
54
18
3
2022
5
1039
16
12
11
2015
9
1031
11
4
3
2017
4
1039
11
21
9
2019
8
1023
1
14
7
2016
4
1004
21
13
9
2020
5
1001
15
1
5
2022
9
1028
31
21
2
2018
3
1000
37
8
3
2020
8
1005
49
14
2
2016
9
1034
15
22
4
2022
3
1039
47
24
4
2022
7
1020
26
18
7
2021
1
1031
24
21
2
2021
1
1025
39
16
5
2020
4
1022
39
19
1
2018
6
1020
43
1
7
2018
3
1030
5
14
4
2022
5
1036
12
2
12
2017
8
1000
31
2
4
2017
6
1032
16
14
10
2018
9
1039
49
5
2
2018
8
1028
24
12
5
2019
8
1010
45
22
11
2016
1
1004
6
21
9
2015
3
1029
60
16
12
2015
9
1011
58
12
10
2018
6
1038
1
3
1
2021
9
1037
4
5
5
2020
9
1016
51
17
6
2015
7
1007
24
5
9
2016
1
1007
44
4
11
2019
5
1001
5
18
11
2018
6
1024
5
13
5
2018
2
1030
13
23
12
2020
7
1027
50
8
8
2015
7
1007
57
11
3
2018
5
1020
23
23
9
2015
8
1015
33
17
2
2017
10
1020
22
25
6
2020
7
1010
16
4
9
2019
7
1037
14
26
12
2020
5
1006
32
1
2
2018
6
1007
18
28
4
2016
2
1017
14
24
7
2019
7
1007
49
21
1
2022
7
1022
6
9
6
2016
2
1000
59
21
5
2019
6
1037
17
4
10
2019
7
1022
26
10
10
2020
3
1006
32
24
2
2019
6
1014
18
6
3
2019
1
1023
49
7
6
2018
5
1032
5
28
1
2018
8
1015
27
8
6
2019
2
1038
32
27
3
2018
6
1033
39
10
7
2018
2
1012
34
26
8
2020
5
1008
8
1
9
2015
9
1007
44
14
1
2022
2
1009
1
8
9
2016
4
1026
27
3
2
2020
8
1039
57
22
8
2016
6
1032
11
5
10
2017
1
1013
34
4
11
2017
6
1014
8
24
9
2020
6
1033
2
21
6
2017
8
1035
50
28
4
2021
6
1024
52
22
10
2016
10
1016
56
9
10
2015
7
1011
31
24
7
2016
1
1034
10
15
8
2018
6
1014
27
27
9
2020
5
1033
4
15
7
2015
7
1004
8
12
9
2018
1
1036
4
6
9
2021
7
1015
16
28
1
2021
3
1010
44
17
9
2017
2
1005
33
24
11
2017
10
1031
6
24
4
2021
6
1030
31
14
11
2020
2
1018
14
15
1
2021
1
1010
53
29
9
2020
3
1015
58
13
6
2017
9
1006
35
24
5
2020
10
1015
23
23
1
2019
9
1001
27
24
12
2017
2
1001
55
26
6
2019
9
1003
3
9
9
2017
10
1023
44
30
1
2020
5
1032
31
14
2
2016
9
1038
32
8
8
2018
9
1030
45
5
12
2015
7
1038
48
31
8
2021
3
1038
14
7
9
2016
6
1018
14
2
5
2017
9
1011
15
20
2
2017
4
1018
13
9
12
2018
1
1023
2
22
12
2021
3
1029
35
9
6
2020
9
1037
37
2
7
2017
7
1039
40
4
3
2020
8
1020
44
16
11
2019
9
1024
56
28
3
2019
7
1001
2
12
10
2020
5
1015
21
22
6
2021
10
1011
40
7
7
2020
8
1029
46
29
7
2016
4
1005
33
9
12
2019
2
1016
28
15
2
2018
2
1032
20
24
7
2016
8
1036
59
31
10
2019
2
1031
16
16
5
2017
8
1012
29
24
7
2021
7
1028
22
14
11
2016
10
1006
42
17
11
2016
5
1009
19
25
1
2022
6
1005
32
4
12
2015
3
1034
41
1
6
2020
6
1016
37
26
2
2022
2
1003
21
26
4
2016
7
1033
32
26
11
2017
1
1028
19
17
8
2015
3
1030
34
23
6
2017
2
1026
39
17
1
2016
7
1028
14
17
3
2020
2
1006
24
1
11
2021
1
1007
45
5
5
2021
8
1011
16
6
10
2017
1
1007
48
20
7
2020
6
1016
54
23
5
2020
4
1032
30
27
8
2020
2
1023
19
17
8
2016
7
1028
31
30
7
2019
6
1016
47
19
7
2016
6
1025
28
8
7
2019
9
1025
25
21
9
2019
9
1039
31
6
12
2019
6
1007
29
4
8
2016
3
1023
26
27
8
2015
10
1039
2
5
5
2020
3
1007
18
30
9
2020
1
1017
45
6
12
2016
3
1020
4
12
9
2017
8
1025
9
28
6
2017
10
1034
31
20
3
2022
6
1022
59
12
8
2021
3
1027
50
18
8
2021
6
1005
22
7
3
2022
9
1020
26
23
8
2020
1
1031
11
28
6
2018
10
1000
11
5
4
2019
1
1018
30
1
6
2021
10
1011
59
25
6
2015
1
1008
9
27
2
2017
1
1023
58
3
11
2015
10
1006
8
15
4
2020
2
1034
23
10
2
2022
1
1033
28
1
6
2020
7
1023
36
16
8
2016
3
1023
20
18
8
2019
10
1003
57
8
8
2019
4
1020
45
12
11
2020
2
1003
34
6
6
2018
5
1038
50
6
3
2016
10
1020
48
7
1
2022
1
1029
57
5
7
2017
3
1036
26
29
7
2018
4
1035
50
9
8
2015
9
1013
8
1
7
2016
9
1018
45
23
11
2020
7
1036
5
3
4
2016
8
1022
31
5
7
2015
1
1017
29
7
10
2020
8
1038
24
8
8
2019
3
1026
21
3
2
2020
3
1008
16
11
7
2019
4
1026
26
16
10
2016
1
1031
52
4
6
2016
2
1029
46
2
11
2017
2
1029
40
15
2
2019
8
1007
52
12
9
2016
10
1030
45
9
7
2017
8
1003
48
2
3
2016
9
1010
5
24
11
2020
9
1038
34
1
3
2019
3
1003
51
8
6
2017
7
1021
4
12
11
2018
2
1035
19
16
8
2021
8
1014
53
11
3
2020
4
1027
25
10
1
2018
8
1006
9
19
7
2020
2
1020
53
17
3
2022
3
1039
45
7
2
2021
6
1024
46
4
1
2017
1
1013
55
23
1
2019
6
1027
38
19
12
2016
8
1034
34
18
3
2018
5
1020
11
28
8
2015
4
1010
50
26
6
2021
3
1031
36
23
1
2019
4
1021
44
23
10
2016
1
1022
28
2
3
2022
2
1020
39
30
7
2016
8
1007
36
28
7
2017
1
1039
46
8
6
2020
1
1001
53
21
11
2017
1
1025
1
24
4
2021
3
1005
16
21
9
2019
2
1026
16
28
1
2018
8
1000
59
22
9
2019
8
1000
17
14
7
2018
9
1016
11
29
7
2020
1
1036
60
8
8
2016
8
1008
53
17
10
2016
4
1023
31
15
3
2016
10
1027
13
24
8
2016
10
1022
50
27
3
2020
7
1036
12
1
10
2015
2
1038
6
2
5
2017
10
1014
56
21
2
2018
2
1027
39
20
9
2020
2
1003
24
4
9
2021
2
1014
6
4
2
2021
6
1017
22
16
11
2019
2
1020
20
21
10
2021
8
1035
8
21
7
2021
10
1013
4
28
3
2018
6
1034
56
7
12
2017
2
1021
49
7
8
2021
9
1039
36
17
7
2015
8
1030
3
23
10
2020
9
1010
3
17
3
2022
3
1013
50
7
8
2017
6
1009
9
28
3
2021
4
1013
30
10
9
2019
2
1001
28
24
1
2018
3
1030
16
4
3
2016
10
1014
8
31
8
2016
5
1028
7
30
11
2021
10
1008
21
20
11
2019
3
1018
18
29
1
2021
10
1003
59
18
9
2021
6
1018
15
11
12
2018
9
1034
16
24
11
2017
6
1036
4
18
11
2019
8
1025
53
15
7
2015
3
1000
38
25
11
2018
5
1035
54
5
5
2018
2
1028
40
24
4
2022
1
1038
26
12
11
2015
2
1022
20
13
9
2015
6
1020
47
9
10
2018
5
1004
59
4
1
2021
8
1024
60
3
9
2021
2
1032
48
6
10
2019
10
1038
21
9
3
2019
7
1037
52
19
4
2020
9
1003
23
2
3
2017
5
1033
21
15
10
2018
7
1019
52
15
10
2018
4
1017
40
15
11
2015
3
1004
45
22
1
2018
10
1034
14
24
8
2019
2
1019
37
2
3
2017
5
1012
5
12
6
2021
1
1014
8
1
3
2022
5
1034
32
3
11
2021
2
1010
47
4
12
2016
10
1036
53
6
10
2019
4
1036
11
27
12
2016
9
1038
58
26
9
2019
2
1029
38
30
4
2021
7
1005
14
30
1
2017
9
1018
50
31
1
2020
8
1009
32
1
4
2018
8
1028
40
4
11
2019
9
1006
23
12
3
2020
5
1037
30
16
7
2018
3
1035
51
9
8
2020
10
1004
34
13
1
2016
10
1028
60
1
3
2021
2
1024
54
20
2
2017
3
1010
59
19
2
2022
6
1033
41
20
2
2019
9
1014
55
19
9
2020
4
1028
56
19
2
2016
4
1035
4
19
4
2020
1
1039
17
9
5
2017
5
1002
53
13
7
2016
8
1036
30
30
12
2019
2
1001
51
7
3
2021
2
1037
58
17
4
2022
5
1028
47
28
12
2018
2
1002
13
21
8
2015
4
1006
5
24
10
2020
8
1032
33
1
3
2020
9
1036
59
28
11
2016
10
1000
1
7
1
2018
5
1016
53
31
7
2020
7
1024
3
1
9
2015
5
1031
7
6
5
2017
9
1008
60
26
1
2022
6
1019
55
18
9
2021
3
1035
20
25
12
2018
5
1005
17
7
1
2019
4
1001
60
26
2
2018
5
1026
54
11
3
2016
9
1002
24
23
11
2018
5
1029
30
29
6
2019
5
1031
25
7
7
2015
2
1021
38
17
10
2018
1
1003
44
15
10
2018
8
1035
6
30
7
2019
1
1018
15
26
12
2020
4
1003
49
10
8
2020
6
1017
16
24
9
2018
4
1032
15
4
1
2020
1
1024
55
9
7
2015
5
1038
40
24
12
2015
7
1018
15
17
12
2021
10
1024
6
27
6
2015
10
1021
40
21
11
2018
8
1038
32
21
3
2019
10
1037
55
18
12
2020
5
1003
27
25
5
2019
3
1026
46
14
11
2021
3
1016
15
22
10
2019
10
1013
20
7
6
2018
9
1015
49
10
10
2018
8
1034
27
26
6
2021
3
1007
1
17
1
2022
2
1037
46
3
11
2016
5
1005
56
1
4
2020
10
1014
40
21
12
2021
5
1030
31
4
9
2021
7
1029
32
13
4
2021
8
1027
47
11
8
2020
3
1033
46
31
7
2019
10
1006
55
16
1
2016
2
1013
39
5
2
2016
8
1021
34
27
9
2015
5
1030
49
21
9
2020
8
1039
14
3
1
2016
10
1038
45
16
3
2018
2
1014
7
26
1
2017
4
1023
44
31
3
2016
1
1019
42
16
12
2015
10
1038
4
3
7
2016
9
1008
24
3
12
2016
8
1023
55
13
4
2022
6
1000
23
24
6
2019
6
1021
50
31
5
2015
8
1028
56
27
6
2020
1
1025
17
21
8
2020
3
1038
53
29
5
2017
7
1018
48
30
6
2021
10
1011
20
14
7
2022
3

    31
    */
