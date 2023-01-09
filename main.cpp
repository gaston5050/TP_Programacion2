#include <iostream>
#include "include/Fecha.h"
#include "include/Estudiante.h"
#include "include/Examen.h"
#include<locale.h>

using namespace std;

int main()
{
    int opcion;
    setlocale(LC_CTYPE, "Spanish");

while (true){
cout<<"MENÚ PRINCIPAL"<<endl;
cout<<" ----------------------------"<<endl;
cout<<"1 - CARGAR EXAMEN"<<endl;
cout<<"2 - LISTAR EXÁMENES"<<endl;
cout<<"3 - BUSCAR MEJOR NOTA"<<endl;
cout<<" ----------------------------"<<endl;
cout<<"0 - SALIR"<<endl;

cin>> opcion;

switch(opcion){

case 1:
    system("cls");
    cargarExamenes(1);

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
            cout <<ewndl;
            system("pause");
            system("cls");
        }

    break;
case 4:
    break;
case 0:
    break;


}














}

    return 0;
}
