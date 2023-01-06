#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED


class Examen {

private:
    Fecha _fechaExamen;
    int _legajo;
    int _materia;
    float _calificacion;
    char _tipoExamen;

public:

    void setFecha(int dia, int mes , int anio);
    void setLegajo(int legajo);
    void setMateria(int materia);
    void setCalificacion(float calificacion);
    void setTipoExamen(char tipoExamen);

    Fecha getFecha();
    int getLegajo();
    int getMateria();
    float getCalificacion();
    char getTipoExamen();


    std::string toString();






};

   bool guardarEnDisco(Examen examen);
   bool listar();
   bool leerRegistroX(int posicion);


#endif // EXAMEN_H_INCLUDED
