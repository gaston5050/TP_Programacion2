#include <iostream>
#include <cstring>
#include <locale.h>
#include <iomanip>
#include "../include/Fecha.h"
#include "../include/Estudiante.h"
#include "../include/Examen.h"





    void Examen::setFecha(int dia, int mes , int anio) {  _fechaExamen.setFecha(dia, mes, anio); }
    void Examen::setLegajo(int legajo){ _legajo = legajo;}
    void Examen::setMateria(int materia){ _materia = materia;}
    void Examen::setCalificacion(float calificacion){ _calificacion = calificacion;}
    void Examen::setTipoExamen(char tipoExamen) { _tipoExamen = tipoExamen;}

    Fecha Examen::getFecha(){return _fechaExamen;}
    int Examen::getLegajo(){ return _legajo;}
    int Examen::getMateria() {return _materia;}
    float Examen::getCalificacion(){return _calificacion;}
    char Examen::getTipoExamen() {return _tipoExamen;}

    bool Examen::getEliminado(){ return _eliminado;}
    void Examen::setEliminado( bool eliminado){ _eliminado = eliminado;}



    std::string Examen::toString(){
    setlocale(LC_ALL, "spanish");
        std::string texto = "Materia: " +  std::to_string(_materia) + " Legajo: " + std::to_string(_legajo) + " Fecha: " + _fechaExamen.toString() + " Caliﬁcacion:"  + std::to_string(_calificacion) + " Tipo de Examen: " + std::to_string(_tipoExamen);

        return texto;

    }


        Examen::Examen(){
        _eliminado = true;

        }


     bool Examen::guardarEnDisco(){

        FILE *p = fopen("examenes.dat", "ab");
        if(p == NULL) {return false;}

        bool grabo = fwrite(this, sizeof(Examen), 1, p);

        fclose(p);
        return grabo;


     }

     bool listar(){

     FILE *p = fopen("examenes.dat", "rb");
     Examen aux;

     std::cout << "LISTADO DE EXAMENES "<<std::endl;
     std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<< std::setw(6) << "LEGAJO";
    std::cout<< std::setw(15) << "ID_MATERIA";
    std::cout<< std::setw(10) << "FECHA";
    std::cout<< std::setw(15) << "TIPO";
    std::cout<< std::setw(18) << "CALIFICACION";
    std::cout <<std::endl;
     std::cout<<"------------------------------------------------------------------------------------"<<std::endl;
     if(p==NULL) { return false;}

     while(fread( &aux , sizeof(Examen), 1, p)){


    std::cout<< std::setw(6) << aux.getLegajo();
    std::cout<< std::setw(10) << aux.getMateria();
    std::cout<< std::setw(18) << aux.getFecha().toString();
    std::cout<< std::setw(11) << aux.getTipoExamen();
    std::cout<< std::setw(14) << aux.getCalificacion();

    std::cout <<std::endl;
       // std::cout<< aux.toString() <<std::endl;


     }

    fclose(p);
    return true;


     }

    bool leerRegistro(Examen &aux){

        Examen aux2;
        FILE * p = fopen("examenes.dat","ab");

        if(p== NULL) return false;

        while(fread(&aux2,sizeof(Examen), 1, p)){

           if(aux.getFecha() == aux2.getFecha() && aux.getLegajo() == aux2.getLegajo() && aux.getMateria()== aux2.getMateria() ){

              return false;
              }
        }
        return true;

    }

    bool leerRegistroX(int posicion){

        Examen aux;
        FILE *p = fopen("examenes.dat", "rb+");

        if(p == NULL){ return false;}
        posicion = posicion - 1;
        fseek(p, sizeof(Examen)* posicion, 0);

        bool leyo = fread(&aux, sizeof(Examen), 1 , p);




        if(leyo){

    fseek(p, ftell(p)-sizeof(Examen),0);

    int legajo, materia;
    float calificacion;
    char tipoExa;




        std::cout<< "LEGAJO: ";
        std::cin>> legajo;
        std::cout<<std::endl;
        std::cout<< "MATERIA: ";
        std::cin>> materia;
        std::cout<<std::endl;
        std::cout<< "CALIFICACION: ";
        std::cin>> calificacion;
        std::cout<<std::endl;
        std::cout<< "TIPO DE EXAMEN: ";
        std::cin>> tipoExa;
        std::cout<<std::endl;



        aux.setLegajo(legajo);
        aux.setMateria(materia);
        aux.setCalificacion(calificacion);
        aux.setTipoExamen(tipoExa);




        bool escribio =  fwrite(&aux, sizeof aux,1, p );




        fclose(p);

        return escribio;

            }



        }








  int BuscarMejorNota(int materia, int legajo){

  Examen aux;
  bool bandera = true;

  int mejorNota = NULL;
    int leg, mat;


  FILE  *p = fopen("examenes.dat", "rb");
  if(p==NULL){ return -2;}

  while(fread(&aux, sizeof aux, 1, p)){
    leg = aux.getLegajo();
    mat =aux.getMateria();

    if(aux.getLegajo() == legajo && aux.getMateria() == materia){

       if(bandera){
       mejorNota = aux.getCalificacion();
       bandera = false;
        }
        if(mejorNota < aux.getCalificacion()){

           mejorNota = aux.getCalificacion();


        }




    }



  }

  if (mejorNota == NULL ) return -1;
  else return mejorNota;







  return mejorNota;

  }

void cargarExamenes(int cantidad){

    Examen aux;
    int legajo, materia;
    float calificacion;
    char tipoExa;


    while( cantidad > 0){
        std::cout<< "LEGAJO: ";
        std::cin>> legajo;
        std::cout<<std::endl;
        std::cout<< "MATERIA: ";
        std::cin>> materia;
        std::cout<<std::endl;
        std::cout<< "CALIFICACION: ";
        std::cin>> calificacion;
        std::cout<<std::endl;
        std::cout<< "TIPO DE EXAMEN: ";
        std::cin>> tipoExa;
        std::cout<<std::endl;



        aux.setLegajo(legajo);
        aux.setMateria(materia);
        aux.setCalificacion(calificacion);
        aux.setTipoExamen(tipoExa);

        if(leerRegistro(aux)){

        aux.guardarEnDisco();
        cantidad --;
        }
        else {
        std::cout<< " REGISTRO REPETIDO "<<std::endl;
        return;
        }


    }



return;

}

int cantidad(){

    Examen aux;
    FILE *p = fopen("examenes.dat","rb");

    if(p==NULL)return false;

    while(fread(&aux,sizeof(Examen),1,p)){


    }
    int total = ftell(p)/sizeof(Examen);
    fclose(p);
    return total;







}
