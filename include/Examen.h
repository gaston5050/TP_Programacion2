#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED


class Examen {

private:
    Fecha _fechaExamen;
    int _legajo;
    int _materia;
    float _calificacion;
    char _tipoExamen;
    bool _eliminado;

public:
    Examen();
    void setEliminado(bool eliminado);
    void setFecha(int dia, int mes , int anio);
    void setLegajo(int legajo);
    void setMateria(int materia);
    void setCalificacion(float calificacion);
    void setTipoExamen(char tipoExamen);

    bool getEliminado();
    Fecha getFecha();
    int getLegajo();
    int getMateria();
    float getCalificacion();
    char getTipoExamen();

     bool guardarEnDisco();
    std::string toString();






};

   void cargarExamenes(int cantidad);
   bool listar();
   bool leerRegistroX(int posicion);
   int BuscarMejorNota(int materia, int legajo);
    int cantidad();

#endif // EXAMEN_H_INCLUDED
