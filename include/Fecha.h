#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


class Fecha
{
private:

    int _dia, _mes, _anio;

public:
    Fecha(int dia, int mes, int anio);
    Fecha ();
    std::string toString();

    void setDia(int);
    void setMes(int);
    void setAnio(int);

    int getDia();
    int getMes();
    int getAnio();

};
#endif // FECHA_H_INCLUDED
