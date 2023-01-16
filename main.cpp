#include <iostream>
#include "include/Fecha.h"
#include "include/Estudiante.h"
#include "include/Examen.h"
#include<locale.h>

using namespace std;

int main()
{
      Estudiante aux;

system("pause");


cout<< cantidadEstudiantes();
cout<< endl;
cout<< cantidad_registros_estudiantes();



    int opcion;
   // Estudiante aux;
    setlocale(LC_CTYPE, "Spanish");

while (true){
cout<<"MENÚ PRINCIPAL"<<endl;
cout<<" ----------------------------"<<endl;
cout<<"1 - CARGAR EXAMEN"<<endl;
cout<<"2 - LISTAR EXÁMENES"<<endl;
cout<<"3 - BUSCAR MEJOR NOTA"<<endl;
cout<<"4 - MODIFICAR REGISTRO"<<endl;
cout<<"5 - CANTIDAD EXAMENES"<<endl;
cout<<"6 - CARGAR ESTUDIANTE"<<endl;
cout<<"7 - LISTAR ESTUDIANTES"<<endl;
cout<<"7 - REPORTE A"<<endl;
cout<<"9 - MODIFICAR ESTUDIANTE"<<endl;

cout<<" ----------------------------"<<endl;
cout<<"0 - SALIR"<<endl;

cin>> opcion;

switch(opcion){

case 1:
    system("cls");
    cargarExamenes(500);

    system("pause");
    system("cls");
    break;
case 2:
    system("cls");
    listar();
    system("pause");
    system("cls");
    cout<<endl;
    break;
case 3:
    int mat,leg;
    cout<< "INGRESE MATERIA: ";
    cin>> mat;
    cout<<endl;
    cout<< "INGRESE LEGAJO";
    cin>> leg;

        if(BuscarMejorNota(mat,leg) == -1){
                system("cls");
            cout<< "NO EXISTE LEGAJO" <<endl;
               system("pause");
            system("cls");

        }
        else{
            system("cls");

            cout<< " LA MEJOR NOTA DEL LEGAJO " << leg << " EN LA MATERIA  " << mat << " FUE " << BuscarMejorNota(mat,leg);
            cout <<endl;
            system("pause");
            system("cls");
        }

    break;
case 4:
    int pos;
    system("cls");

    cout<< "INGRESE POSICION: ";
    cin>> pos;

    leerRegistroX(pos);
    break;
case 5:
    system("cls");
    cout<< " CANTIDAD DE REGISTROS EXAMEN: " << cantidad();
    cout<<endl;
    system("pause");
    system("cls");



case 6:
            system("cls");
            aux.cargarEstudiante();
            system("pause");
            system("cls");



    break;




case 7:
    system("cls");
    aux.listarEstudiantes();
    system("pause");
    system("cls");



    break;

case 8:

    system("cls");
    reporteA();
      system("pause");
    system("cls");


    break;

    case 9:
    int legajo;



    system("cls");
    std::cout << "INGRESE LEGAJO: "<<std::endl;
    cin >> legajo;
    system("cls");
    aux.modificarEstudiante(legajo);
    system("pause");    system("cls");





    break;
   case 0:
    break;


}














}

    return 0;
}


